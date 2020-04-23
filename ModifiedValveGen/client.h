
#pragma once

#include "required.h"
#include "singleton.h"
#include <iostream>

#define OUTPUT_DIR "C:\\Users\\Athena\\Downloads\\ValveGen-master\\ValveGen-master\\ValveGen\\dump\\"
#define GETALLCLASSES_IDX 11
#define CLIENTMODULE "client.dll"
#define LIST_OFFSET 0x288e719

// CLIENT.DLL global offset
#define B_LEVELINIT 0xC3D87C
#define P_IMPACT_EFFECT_TABLE_NAMES 0xC3DB08
#define P_STRING_TABLE_EFFECT_DISPATCH 0xC3DAD0
#define P_STRING_TABLE_VGUI_SCREEN 0xC3DAC8
#define P_STRING_TABLE_MATERIALS 0xC3DB18
#define P_STRING_TABLE_INFO_PANEL 0xC3DAD8
#define P_MOVIES 0xC3DB20
#define P_WEAPONNAMES 0xC3DAE8
#define P_SCRIPTNAMES 0xC3DAF0
#define P_CLASSLIST 0xC3DB30
#define P_CLIENTMODE 0xFB3780
#define P_GLOBALS 0xB06AD0
namespace valvegen
{
	struct EngineInterface
	{
		LPVOID				callback;
		PCHAR				name;
		EngineInterface*	next;
	};

	class DVariant
	{
	public:
		union
		{
			float	m_Float;
			long	m_Int;
			char	*m_pString;
			void	*m_pData;
			float   m_Vector[4];
			__int64	m_Int64;
		};
		int	m_Type;
	};

	struct RecvProp;

	class CRecvProxyData
	{
	public:
		const RecvProp	*m_pRecvProp;
		DVariant		m_Value;
		int				m_iElement;
		int				m_ObjectID;
	};


	typedef void(*RecvVarProxyFn)(const CRecvProxyData *pData, void *pStruct, void *pOut);

	struct RecvTable
	{
		char			_unk0x0000[0x8];		//0x0000
		RecvProp		**m_pProps;
		int				m_nProps;
		char			_unk0x0014[0x10C];		//0x0014
		void			*m_pDecoder;
		char			*m_pNetTableName;
		bool			m_bInitialized;
		bool			m_bInMainList;
	};


	struct RecvProp
	{
		int			   m_RecvType;				//0x0000
		int				m_Offset;				//0x0004
		int				_unk0x0008;				//0x0008
		int				_unk0x000C;				//0x000C size?
		char			_unk0x0010[0x10];		//0x0010
		RecvTable*		m_pDataTable;			//0x0020
		char*			m_pVarName;				//0x0028
		bool			m_bInsideArray;			//0x0030
		char			_unk0x0031[0x7];		//0x0031
		RecvProp*		m_pArrayProp;			//0x0038
		void*			m_ProxyFn;				//0x0040
		char			_unk0x0048[0xC];		//0x0048
		int				m_Flags;				//0x0054
		char			_unk0x0058[0x4];		//0x0058
		int				m_nElements;			//0x005C
		char			_unk0x0060[0x8];		//0x0060
	}; //Size = 0x68

	//struct RecvProp
	//{
	//	char					*m_pVarName;
	//	int						m_RecvType;
	//	int						m_Flags;
	//	int						m_StringBufferSize;
	//	bool					m_bInsideArray;
	//	const void				*m_pExtraData;
	//	RecvProp				*m_pArrayProp;
	//	void*					m_ArrayLengthProxy;
	//	void*					m_ProxyFn;
	//	void*					m_DataTableProxyFn;
	//	RecvTable				*m_pDataTable;
	//	int						m_Offset;
	//	int						m_ElementStride;
	//	int						m_nElements;
	//	const char				*m_pParentArrayPropName;
	//};
	struct ClientClass
	{
		void*			m_pCreateFn;		//0x0000
		void*			m_pCreateEventFn;	//0x0008
		char*			m_pNetworkName;		//0x0010
		RecvTable*		m_pRecvTable;		//0x0018
		ClientClass*	m_pNext;			//0x0020
		char			_unk0028[0x8];		//0x0028
		char*			name;				//0x0030
	}; //Size = 0x38

	//struct ClientClass
	//{
	//	void*			m_pCreateFn;
	//	void*			m_pCreateEventFn;
	//	char			*m_pNetworkName;
	//	RecvTable		*m_pRecvTable;
	//	ClientClass		*m_pNext;
	//	//int				m_ClassID;
	//	//char			_unk0028[0x8];		//0x0028
	//	char*			name;
	//};

	/// <summary>
	/// Class Client.
	/// </summary>
	/// <seealso cref="Singleton{Client}" />
	class Client : public Singleton<Client>
	{
		friend class Singleton<Client>;
	private:
		/// <summary>
		/// Prevents a default instance of the <see cref="Client"/> class from being created.
		/// </summary>
		Client();

	public:
		/// <summary>
		/// Waits for client to become ready.
		/// </summary>
		void WaitForClientToBecomeReady();

		/// <summary>
		/// Initializes the client interface.
		/// </summary>
		/// <returns>bool.</returns>
		bool InitClientInterface();

		/// <summary>
		/// Gets all classes.
		/// </summary>
		/// <returns>valvegen.ClientClass *.</returns>
		ClientClass* GetAllClasses();

	private:
		/// <summary>
		/// The client_dll_handle_
		/// </summary>
		HMODULE client_dll_handle_;
		/// <summary>
		/// The class_ptr_
		/// </summary>
		LPVOID class_ptr_;
	};
}
