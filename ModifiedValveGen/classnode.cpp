
#include "classnode.h"
#include "classbuilder.h"

/// <summary>
/// The valvegen namespace.
/// </summary>
namespace valvegen
{
	

	ClassNode::ClassNode()
	{}

	void ClassNode::Cleanup()
	{
		for (auto& e : data_elements_)
		{
			if (e)
			{
				delete e;
				e = NULL;
			}
		}

		data_elements_.clear();
	}

	void ClassNode::SetClassName(std::string name)
	{
		//std::cout << "Setting Class Name" << std::endl;
		if (name.find("DT_") == 0)
			name.replace(name.begin(), name.begin() + 3, "C");

		class_name_ = name;
	}

	DataElement* ClassNode::CreateDataElement(uintptr_t offset, std::string name, DATA_TYPE dtype, uintptr_t stride /*= 0*/)
	{
		for (auto& e : data_elements_)
		{
			if (e->name_ == name)
			{
				if (e->dtype_ == ARRAY)
				{
					e->array_stride_ = stride;
				}
				return e;
			}

			/* avoid adding multiple members at the same offset e.g. "movecollide" */
			if (e->offset_ == offset)
				return e;
		}
		//std::cout << "Creating Data Element" << std::endl;
		DataElement* element = new DataElement();
		element->name_		= name;
		element->offset_	= offset;
		element->dtype_		= dtype;

		data_elements_.push_back(element);

		return element;
	}

	DataElement* ClassNode::CreateDataElementClassInstance(uintptr_t offset, std::string name, std::string varname, DATA_TYPE dtype)
	{
		if (name.find("DT_") == 0)
			name.replace(name.begin(), name.begin() + 3, "C");
		std::cout << "Creating Data Element Class Instance: " << name << std::endl;
		for (auto& e : data_elements_)
		{
			if (e->name_ == varname)
			{
				if (e->dtype_ == ARRAY)
				{
					/* calculate the stride */
					if (e->offset_ == 0)
						e->array_stride_ = offset - e->offset_;

					e->array_size_++;
				}
				return e;
			}
		}		

		DataElement* element = new DataElement();
		element->name_ = varname;
		element->instance_name_ = name;
		element->offset_ = offset;
		element->dtype_ = dtype;

		data_elements_.push_back(element);

		return element;
	}

	std::string ClassNode::GetBaseName()
	{
		return class_name_;
	}

	void ClassNode::ShuffleMembers()
	{
	//	std::cout << "Shuffling Members" << std::endl;
		std::sort(data_elements_.begin(), data_elements_.end(), [](DataElement const* a, DataElement const* b) { return (a->offset_ < b->offset_); });
	}

	void ClassNode::OuputHeader(std::ofstream& of)
	{
		of << "//***********************************************" << std::endl;
		of << "// File: " << GetBaseName() + ".h" << std::endl;
		of << "//***********************************************" << std::endl << std::endl;
		of << "#pragma once" << std::endl << std::endl;
	}

	void ClassNode::ResolveIncludes(std::ofstream& of)
	{
		if (HasInheritence())
		{
			/* resolve inheritence first of all */
			for (UINT i = 0; i < GetNumParents(); ++i)
			{
				of << "#include \"" << GetInheritedClassName(i) << ".h\"" << std::endl;
			}			
		}

		/* then resolve data elements, if there are any */
		for (auto& e : data_elements_)
		{
			if (e->dtype_ == CLASS)
			{
				of << "#include \"" << e->instance_name_ << ".h\"" << std::endl;
			}
		}

		of << std::endl;
	}

	bool ClassNode::HasInheritence()
	{
		return (parents_.size() > 0);
	}

	void ClassNode::SetParent(ClassNode* parent)
	{
		for (auto& p : parents_)
		{
			if (p->GetBaseName() == parent->GetBaseName())
				return;
		}
		parents_.push_back(parent);
	}

	std::string ClassNode::GetInheritedClassName(UINT index /*= 0*/)
	{
		if (HasInheritence())
			return parents_.at(index)->GetBaseName();
		return "";
	}

	UINT ClassNode::GetNumParents()
	{
		return parents_.size();
	}

	ClassNode* ClassNode::GetParent(UINT index /*= 0*/)
	{
		if (index < 0 || index >= parents_.size())
			return nullptr;

		return parents_.at(index);
	}

	std::vector<DataElement*>& ClassNode::GetDataElements()
	{
		return data_elements_;
	}

	uintptr_t ClassNode::GetInheritedClassSize(UINT index /*= 0*/)
	{
		uintptr_t class_size = 0;

		if (HasInheritence())
		{
			ClassNode* parent = GetParent(index);

			if(parent)
				class_size += parent->GetClassSize();
		}		

		return class_size;
	}

	uintptr_t ClassNode::GetClassSize() const
	{
		if (data_elements_.size() > 0)
		{
			DataElement* last_element = data_elements_.at(data_elements_.size() - 1);

			if (last_element)
			{
				uintptr_t size = last_element->offset_;

				size += last_element->GetElementSize();

				return size;
			}
		}

		return 0;
	}

	void ClassNode::ShuffleParents()
	{
		std::sort(parents_.begin(), parents_.end(), [](ClassNode const* a, ClassNode const* b) { return (a->GetClassSize() < b->GetClassSize()); });

		/* this is a hacky fix for classes such as CBaseCombatWeapon where CLocalActiveWeaponData are actually in the middle of the class */
		if (data_elements_.size())
		{
			for (UINT i = 0; i < GetDataElements().size(); ++i)
			{
				DataElement* element = GetDataElements().at(i);

				/* check for inline classes */
				if (element->dtype_ == CLASS && element->offset_ == 0)
				{
					ClassNode* instance = ClassBuilder::Instance()->FindNode(element->instance_name_);

					if (instance)
					{
						bool found = false;

						for (UINT j = 0; j < instance->GetDataElements().size(); ++j)
						{
							DataElement* child_element = instance->GetDataElements().at(j);

							for (UINT k = 0; k < GetDataElements().size(); ++k)
							{
								// skip ourselves
								if (k == i)
									continue;

								DataElement* other_element = GetDataElements().at(k);

								/* does the offset clash with other members */
								if (child_element->offset_ >= other_element->offset_)
								{
									/* insert the variables from the inline class back into the parent class and sort them */
									data_elements_.insert(data_elements_.end(), instance->GetDataElements().begin(), instance->GetDataElements().end());
									ShuffleMembers();

									/* delete the inline class now that we have taken the members out */
									GetDataElements().erase(GetDataElements().begin() + i);
									i--;
									found = true;

									break;
								}
							}

							if (found)
								break;
						}
					}
				}				
			}

			/* remove duplicates by offset value (can sometimes happen) */
			data_elements_.erase(std::unique(data_elements_.begin(), data_elements_.end(),
				[](DataElement const* a, DataElement const* b) { return (a->offset_ == b->offset_); }), data_elements_.end());
		}
	}
}