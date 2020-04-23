
#include "classbuilder.h"
#include "client.h"

namespace valvegen
{
    ClassBuilder::ClassBuilder()
    {}

    void ClassBuilder::Cleanup()
    {
        for ( auto& n : nodes_ )
        {
            if ( n )
            {
                n->Cleanup();
                delete n;
                n = NULL;
            }
        }

        nodes_.clear();
    }

    bool ClassBuilder::CreateClasses( HINSTANCE module_instance )
    {
        auto class_head = Client::Instance()->GetAllClasses();
		
		if (class_head == nullptr) {
			std::cout << "class_head == nullptr" << std::endl;
			return false;
		}

        for ( ; class_head != nullptr; class_head = class_head->m_pNext )
        {
			//std::cout << "Loop: class_head " << class_head << std::endl;
			//std::cout << "Loop: m_pNext " << class_head->m_pNext << std::endl;
            CreateNodes( class_head->m_pRecvTable , nullptr );
        }

		std::cout << "Creating SDK " << std::endl;
        CreateSDK( module_instance );

        return true;
    }

    ClassNode* ClassBuilder::CreateNode( RecvTable* instance , ClassNode* parent /*= nullptr*/ )
    {
        std::string fixed_name = instance->m_pNetTableName;
		std::cout << "CreateNode: instance->m_pNetTableName;: " << fixed_name << std::endl;

        if ( fixed_name.find( "DT_" ) == 0 )
            fixed_name.replace( fixed_name.begin() , fixed_name.begin() + 3 , "C" );

        for ( auto& n : nodes_ )
        {
			//std::cout << "CreateNode: 57: n->GetBaseName(): " << n->GetBaseName() << std::endl;
            if ( n->GetBaseName() == fixed_name )
            {
                if ( parent )
                    parent->SetParent( n );

                return n;
            }
        }
        auto node = new ClassNode();
	//	std::cout << "CreateNode: 66: node created " << std::endl;
        nodes_.push_back( node );

        return node;
    }

    void ClassBuilder::AddElement( RecvProp* prop , ClassNode* current_node )
    {
		//std::cout << "Entering AddElement with prop: " << prop << " and " << current_node << std::endl;
		//std::cout << "*prop" << *reinterpret_cast<uintptr_t*>(prop) << std::endl;
		//auto csName = reinterpret_cast<char*>(*reinterpret_cast<uintptr_t*>(prop) + 0x28);
		//std::cout << "ClassBuilder: 78: csName " << csName << std::endl;
		//system("PAUSE");
		std::string sName = prop->m_pVarName;
		//std::cout << "ClassBuilder: 76:  sName " << sName << std::endl;
		//system("PAUSE");
        // Now let's make the c++ compiler able to read the networked variables, if you don't want to end up with big errors when you compile...
        int iPos;

        // Replace [ by _.
        while ( true )
        {
            iPos = sName.find( TEXT( "[" ) );

            if ( iPos != std::string::npos )
            {
                sName[ iPos ] = TEXT( '_' );
            }
            else
            {
                break;
            }
        }

        // delete ] from networked variables
        while ( true )
        {
            iPos = sName.find( TEXT( "]" ) );

            if ( iPos != std::string::npos )
            {
                sName.erase( iPos );
            }
            else
            {
                break;
            }
        }

        // delete . from networked variables.
        while ( true )
        {
            iPos = sName.find( TEXT( "." ) );

            if ( iPos != std::string::npos )
            {
                sName[ iPos ] = TEXT( '_' );
            }
            else
            {
                break;
            }
        }

        // delete " from networked variables.
        while ( true )
        {
            iPos = sName.find( TEXT( "\"" ) );

            if ( iPos != std::string::npos )
            {
                sName[ iPos ] = TEXT( '_' );
            }
            else
            {
                break;
            }
        }
		//std::cout << "ClassBuilder:139  prop->m_RecvType: " << prop->m_RecvType << std::endl;
		//system("PAUSE");
        if ( prop->m_RecvType == CLASS )
        {
            if ( !strcmp( prop->m_pVarName , "baseclass" ) )
                CreateNodes( prop->m_pDataTable , current_node );
            else
            {
				auto p = *prop->m_pDataTable->m_pProps;
                if ( p->m_pVarName[ 0 ] == '0' )
                {
					uintptr_t last_array_offset = 0;
                    int num_array_elements = 0;
                    DataElement* array_member = nullptr;

                    for ( auto i = 0; i < prop->m_pDataTable->m_nProps; ++i )
                    {
						uintptr_t stride = (*prop->m_pDataTable->m_pProps)[ i ].m_Offset - last_array_offset;

                        array_member = current_node->CreateDataElement( prop->m_Offset , sName.c_str() , DATA_TYPE::ARRAY , stride );

                        last_array_offset = (*prop->m_pDataTable->m_pProps)[ i ].m_Offset;

                        num_array_elements++;
                    }

                    array_member->array_size_ = num_array_elements - 1;
                }
                else
                {
                    CreateNodes( prop->m_pDataTable );

                    current_node->CreateDataElementClassInstance( prop->m_Offset , prop->m_pDataTable->m_pNetTableName , sName.c_str() , static_cast< DATA_TYPE >( prop->m_RecvType ) );
                }

            }
        }
        else
        {
            /* Create a new variable */
			auto pt = prop->m_RecvType;
			if (pt > 8) {
				std::cout <<  prop->m_pVarName << " "<< prop->m_RecvType << std::endl;
			}
			current_node->CreateDataElement( prop->m_Offset , sName.c_str() , static_cast< DATA_TYPE >( prop->m_RecvType ) );
        }
    }

    void ClassBuilder::CreateNodes( RecvTable* head , ClassNode* parent /*= nullptr*/ )
    {
		//std::cout << "CreateNodes: RecvTable head: " << head << std::endl;
        ClassNode* current_node = CreateNode( head , parent );
	
        // it has already been created so ignore it
        if ( !current_node )
            return;

		//std::cout << "m_pNetTableName: " << head->m_pNetTableName << std::endl;
        current_node->SetClassName( head->m_pNetTableName );

        if ( head->m_pProps != nullptr )
        {
			//std::cout << "Check this: head->m_pProps: " << head->m_pProps << std::endl;
			//std::cout << "Check this: head->m_nProps: " << head->m_nProps << std::endl;
			//std::cout << "Check this: &head " << &head << std::endl;
			//std::cout << "Check this: &head->m_pProps " << &head->m_pProps << std::endl;
			//system("PAUSE");
            for ( auto i = 0; i < head->m_nProps; ++i )
            {
                auto prop = &head->m_pProps[ i ];

                if ( prop == nullptr )
                    continue;
			//	std::cout << "Adding Prop: "<< prop <<  std::endl;

                AddElement( *prop , current_node );
            }

            /* Shuffle the members so that they are in offset order */
            current_node->ShuffleMembers();
        }
	//	std::cout << "ClassBuilder:209: Node Created" << std::endl;
    }

    void ClassBuilder::CreateSDK( HINSTANCE module_instance )
    {
		if (nodes_.size() == 0)
		{
			std::cout << "nodes_.size() == 0" << std::endl;
			return;
		}
	
        /* Create SDK directory */
        char module_path[ MAX_PATH ];
		memcpy(module_path, OUTPUT_DIR, strlen(OUTPUT_DIR));
         
        std::string sdk_path = module_path;
        size_t pos = sdk_path.find_last_of( '\\' );
        if ( pos != std::string::npos )
        {
            sdk_path = sdk_path.substr( 0 , pos + 1 );
        }

        sdk_path.append( "ValveGen\\" );

        if ( GetFileAttributes( sdk_path.c_str() ) == INVALID_FILE_ATTRIBUTES )
        {
            CreateDirectory( sdk_path.c_str() , nullptr );
        }

        for ( auto& n : nodes_ )
        {
            std::string output_file = n->GetBaseName() + ".h";

            std::ofstream of( sdk_path + output_file , std::ios::out );

            if ( !of.is_open() )
                continue;

            n->OuputHeader( of );

            n->ShuffleParents();

            n->ResolveIncludes( of );

            of << "#pragma pack(push,1)" << std::endl;

            /* classname */
            of << "\tclass " << n->GetBaseName();

			uintptr_t inherited_size = 0;

            if ( n->HasInheritence() )
            {
                of << " : " << std::endl;

                UINT number_of_parents = n->GetNumParents();
                for ( UINT i = 0; i < number_of_parents; ++i )
                {
                    if ( number_of_parents > 1 && i < number_of_parents - 1 )
                        of << "\t\t public " << n->GetInheritedClassName( i ) << ", // 0x" << std::hex << n->GetInheritedClassSize( i ) << std::endl;
                    else
                        of << "\t\t public " << n->GetInheritedClassName( i ) << " // 0x" << std::hex << n->GetInheritedClassSize( i ) << std::endl;

                    /* make note of the inherited size so we can pad to it */
                    if ( i == number_of_parents - 1 )
                        inherited_size = n->GetInheritedClassSize( i );
                }
            }
            else
            {
                of << std::endl;
            }

            of << "\t{" << std::endl << "\tpublic:" << std::endl;

			uintptr_t last_offset = inherited_size;

            for ( unsigned int i = 0; i < n->GetDataElements().size(); ++i )
            {
                auto e = n->GetDataElements().at( i );

                /* check for padding */
                if ( e->offset_ > last_offset )
                {
					uintptr_t padding = e->offset_ - last_offset;

                    of << "\t\tunsigned char _0x" << std::hex << last_offset << "[0x" << std::hex << padding << "];" << std::endl;
                }

                of << "\t\t" << e->GetTypeName() << "\t" << e->name_ << e->GetArrayTerminator() << "; // 0x" << std::hex << e->offset_ << std::endl;

                last_offset = e->offset_ + e->GetElementSize();
            }

            of << "\t};" << std::endl;

            of << "#pragma pack(pop)" << std::endl;

            of.close();
        }

        std::string sdkheader = "#pragma once;\n\n";
        for ( auto& n : nodes_ )
        {
            sdkheader += "#include \"";
            sdkheader += n->GetBaseName() + ".h\"\n";
        }

        std::ofstream of( sdk_path + "GeneratedSDK.h" , std::ios::out );

        if ( !of.is_open() )
            return;

        of << sdkheader;

        of.close();
    }

    ClassNode* ClassBuilder::FindNode( std::string name )
    {
        for ( auto& n : nodes_ )
        {
            if ( n->GetBaseName() == name )
                return n;
        }
        return nullptr;
    }
}
