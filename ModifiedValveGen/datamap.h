#pragma once
#include "required.h"

const char* getType(signed int a1) // a1 is offset 72 or 112
{
	if (a1 <= 0x8000200)
	{
		if (a1 == 0x8000200)
			return "nativeclosure";
		if (a1 > 0x5000004)
		{
			int v5 = a1 - 0x8000010; // 0x8000010 is signal
			if (!v5)
				return "string";
			int v6 = v5 - 0x30;
			if (!v6)
				return "array";
			if (v6 == 0xC0)
				return "closure";
		}
		else
		{
			if (a1 == 0x5000004)
				return "float";
			int v1 = a1 - 0x800;
			if (!v1)
				return "userpointer";
			int v2 = v1 - 0xFFF801;
			if (!v2)
				return "null";
			int v3 = v2 - 7;
			if (!v3)
				return "bool";
			if (v3 == 0x3FFFFFA)
				return "integer";
		}
		return "unknown";
	}
	if (a1 <= 0xA000020)
	{
		switch (a1)
		{
		case 0xA000020:
			return "table";
		case 0x8001000:
			return "thread";
		case 0x8004000:
			return "class";
		case 0x8010000:
			return "weakref";
		}
		return "unknown";
	}
	if (a1 == 0xA000080)
		return "userdata";
	if (a1 == 0xA008000)
		return "instance";
	if (a1 != 0xA400000)
		return "unknown";
	return "entity";
}


struct inputdata_t;
typedef enum _fieldtypes
{
	FIELD_VOID = 0,			// No type or value
	FIELD_FLOAT = 1,			// Any floating point value
	FIELD_STRING = 33,			// A string ID (return from ALLOC_STRING)
	FIELD_VECTOR = 3,			// Any vector, QAngle, or AngularImpulse
	FIELD_QUATERNION,		// A quaternion
	FIELD_INTEGER = 5,			// Any integer or enum
	FIELD_BOOLEAN = 6,			// boolean, implemented as an int, I may use this as a hint for compression
	FIELD_SHORT,			// 2 byte integer
	FIELD_CHARACTER = 8,		// a byte
	FIELD_COLOR32,			// 8-bit per channel r,g,b,a (32bit color)
	FIELD_EMBEDDED,			// an embedded object with a datadesc, recursively traverse and embedded class/structure based on an additional typedescription
	FIELD_CUSTOM,			// special type that contains function pointers to it's read/write/parse functions

	FIELD_CLASSPTR,			// CBaseEntity *
	FIELD_EHANDLE = 34,			// Entity handle
	FIELD_EDICT,			// edict_t *

	FIELD_POSITION_VECTOR,	// A world coordinate (these are fixed up across level transitions automagically)
	FIELD_TIME,				// a floating point time (these are fixed up automatically too!)
	FIELD_TICK,				// an integer tick count( fixed up similarly to time)
	FIELD_MODELNAME,		// Engine string that is a model name (needs precache)
	FIELD_SOUNDNAME,		// Engine string that is a sound name (needs precache)

	FIELD_INPUT,			// a list of inputed data fields (all derived from CMultiInputVar)
	FIELD_FUNCTION,			// A class function pointer (Think, Use, etc)

	FIELD_VMATRIX,			// a vmatrix (output coords are NOT worldspace)

							// NOTE: Use float arrays for local transformations that don't need to be fixed up.
							FIELD_VMATRIX_WORLDSPACE,// A VMatrix that maps some local space to world space (translation is fixed up on level transitions)
							FIELD_MATRIX3X4_WORLDSPACE,	// matrix3x4_t that maps some local space to world space (translation is fixed up on level transitions)

							FIELD_INTERVAL,			// a start and range floating point interval ( e.g., 3.2->3.6 == 3.2 and 0.4 )
							FIELD_MODELINDEX,		// a model index
							FIELD_MATERIALINDEX,	// a material index (using the material precache string table)

							FIELD_VECTOR2D,			// 2 floats

							FIELD_INTEGER64,
							FIELD_VECTOR4D,
							FIELD_TYPECOUNT		// MUST BE LAST
} fieldtype_t; // ENTITY IS 13


const char* ConvertTypeToString(unsigned int type)
{
	switch (type)
	{
	case FIELD_VOID: return "void";
	case FIELD_FLOAT: return "float";
	case FIELD_STRING: return "char*";
	case FIELD_VECTOR: return "Vector";
	case FIELD_QUATERNION: return "Quarternion";
	case FIELD_INTEGER: return "unsigned int";
	case FIELD_BOOLEAN: return "bool";
	case FIELD_SHORT: return "short";
	case FIELD_CHARACTER: return "char";
	case FIELD_COLOR32: return "color32";
	case FIELD_EMBEDDED: return "typedescription_t";
	case FIELD_CUSTOM: return "custom";
	case FIELD_CLASSPTR: return "C_BaseEntity*";
	case FIELD_EHANDLE: return "EHANDLE";
	case FIELD_EDICT: return "edict_t*";
	case FIELD_POSITION_VECTOR: return "Vector";
	case FIELD_TIME: return "float";
	case FIELD_TICK: return "int";
	case FIELD_MODELNAME: return "const char*";
	case FIELD_SOUNDNAME: return "const char*";
	case FIELD_INPUT: return "input";
	case FIELD_FUNCTION: return "FUNC";
	case FIELD_VMATRIX: return "VMatrix";
	case FIELD_VMATRIX_WORLDSPACE: return "VMatrix";
	case FIELD_MATRIX3X4_WORLDSPACE: return "matrix3x4_t";
	case FIELD_INTERVAL: return "float";
	case FIELD_MODELINDEX: return "int";
	case FIELD_MATERIALINDEX: return "int";
	case FIELD_VECTOR2D: return "Vector2D";
	case FIELD_INTEGER64: return "__int64";
	case FIELD_VECTOR4D: return "Vector4D";
	default: return "null";
	}
}


class ISaveRestoreOps;
class C_BaseEntity;
//
// Function prototype for all input handlers.
//
typedef void (C_BaseEntity::*inputfunc_t)(inputdata_t &data);

struct datamap_t;
struct typedescription_t;

enum
{
	TD_OFFSET_NORMAL = 0,
	TD_OFFSET_PACKED = 1,

	// Must be last
	TD_OFFSET_COUNT,
};

struct typedescription_t
{
	fieldtype_t            fieldType;
	const char            *fieldName;
	int                    fieldOffset[TD_OFFSET_COUNT]; // 0 == normal, 1 == packed offset
	unsigned short        fieldSize;
	short                flags;
	// the name of the variable in the map/fgd data, or the name of the action
	const char            *externalName;
	// pointer to the function set for save/restoring of custom data types
	ISaveRestoreOps        *pSaveRestoreOps;
	// for associating function with string names
	inputfunc_t            inputFunc;
	// For embedding additional datatables inside this one
	datamap_t            *td;

	// Stores the actual member variable size in bytes
	int                    fieldSizeInBytes;

	// FTYPEDESC_OVERRIDE point to first baseclass instance if chains_validated has occurred
	struct typedescription_t *override_field;

	// Used to track exclusion of baseclass fields
	int                    override_count;

	// Tolerance for field errors for float fields
	float                fieldTolerance;

	// Unknown, required for correct sizeof
	int unk[3];
};


   //-----------------------------------------------------------------------------
   // Purpose: stores the list of objects in the hierarchy
   //            used to iterate through an object's data descriptions
   //-----------------------------------------------------------------------------
struct datamap_t
{
	typedescription_t    *dataDesc;
	int                    dataNumFields;
	char const            *dataClassName;
	datamap_t            *baseMap;

	bool                chains_validated;
	// Have the "packed" offsets been computed
	bool                packed_offsets_computed;
	int                    packed_size;
};


//datamap_t *GetDataDescMap()
//{
//	typedef datamap_t*(__thiscall *o_GetDataDescMap)(void*);
//	return VT::vfunc<o_GetDataDescMap>(this, 15)(this);
//}
// 
//datamap_t *GetPredDescMap()
//{
//	typedef datamap_t*(__thiscall *o_GetPredDescMap)(void*);
//	return VT::vfunc<o_GetPredDescMap>(this, 17)(this);
//}

void DumpDataMap(datamap_t *pMap)
{
	while (pMap)
	{
		printf("\nclass %s\n", pMap->dataClassName);
		for (int i = 0; i < pMap->dataNumFields; i++)
		{
			if (pMap->dataDesc[i].fieldName == NULL)
				continue;

			printf("> %s %s 0x%X\n", ConvertTypeToString(pMap->dataDesc[i].fieldType), pMap->dataDesc[i].fieldName, pMap->dataDesc[i].fieldOffset);

			if (pMap->dataDesc[i].td)
			{
				DumpDataMap(pMap->dataDesc[i].td);
			}
		}
		pMap = pMap->baseMap;
	}
}

