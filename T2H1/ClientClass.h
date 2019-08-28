#pragma once
#include "stdafx.h"
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