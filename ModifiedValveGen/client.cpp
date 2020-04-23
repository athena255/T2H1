#include "client.h"

namespace valvegen
{
	inline void**& getvtable(void* inst, size_t offset = 0)
	{
		return *reinterpret_cast<void***>((size_t)inst + offset);
	}
	inline const void** getvtable(const void* inst, size_t offset = 0)
	{
		return *reinterpret_cast<const void***>((size_t)inst + offset);
	}
	template< typename Fn >
	inline Fn getvfunc(const void* inst, size_t index, size_t offset = 0)
	{
		return reinterpret_cast<Fn>(getvtable(inst, offset)[index]);
	}


	Client::Client() :
		client_dll_handle_(nullptr)
	{}

	void Client::WaitForClientToBecomeReady()
	{
		HMODULE client_dll = nullptr;
		do
		{
			client_dll = GetModuleHandle(CLIENTMODULE);
		} while (client_dll == nullptr);

		client_dll_handle_ = client_dll;
	}



	bool Client::InitClientInterface()
	{
		if (!client_dll_handle_)
			return false;

		auto create_interface_fn = GetProcAddress(client_dll_handle_, "CreateInterface");
		if (!create_interface_fn)	return false;

		//auto start_address = reinterpret_cast<uintptr_t>(create_interface_fn);
		std::cout << "Create Interface Address: " << std::hex << reinterpret_cast<uintptr_t>(create_interface_fn) << std::endl;

		auto FindListAddress = [](auto function_address) -> uintptr_t
		{
			const BYTE OPCODE_MOV = 0x4C;

			uintptr_t start_address = reinterpret_cast<uintptr_t>(function_address);

			PBYTE opcode_info = reinterpret_cast<PBYTE>(start_address);
			do
			{
				++opcode_info;
			}
			while (*opcode_info != OPCODE_MOV);
			return reinterpret_cast<uintptr_t>(opcode_info) + LIST_OFFSET;
		};

		uintptr_t list_address = FindListAddress(create_interface_fn);
		std::cout << "list_address: " << std::hex << list_address << std::endl;

		if (list_address == NULL)
			return false;

		EngineInterface* interface_list = *reinterpret_cast<EngineInterface**>(list_address);
		std::cout << "interface_list: " << interface_list << std::endl;

		if (!interface_list)
			return false;

		bool found_interface = false;

		while (interface_list)
		{
			std::string interface_name = interface_list->name;
			std::cout << "interface_name: " << interface_name << std::endl;
		
			for (size_t i = interface_name.length() - 1; i > 0; i--)
			{
				if (isdigit(interface_name[i]))
					interface_name.erase(interface_name.length() - 1, 1);
				else
					break;
			}

			if (interface_name == "VClient")
			{
				found_interface = true;
				break;
			}

			interface_list = interface_list->next;
		}

		if (!found_interface)
			return false;

		class_ptr_ = ((LPVOID(*)(void))interface_list->callback)();

		if (!class_ptr_)
			return false;

		return true;
	}


	ClientClass* Client::GetAllClasses()
	{
		int index = GETALLCLASSES_IDX;

		typedef ClientClass* (*tGetAllClasses)(void*);
		tGetAllClasses pGetAllClasses = getvfunc<tGetAllClasses>(class_ptr_, index);
		//std::cout << "Get All Classes: " << pGetAllClasses << std::endl;

		if (!pGetAllClasses) {
			std::cout << "Get All Classes failed " << std::endl;
			return nullptr;
		}

		return pGetAllClasses(class_ptr_);
	}
}