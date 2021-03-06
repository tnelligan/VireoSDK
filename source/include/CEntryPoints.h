/**
 
Copyright (c) 2014-2015 National Instruments Corp.
 
This software is subject to the terms described in the LICENSE.TXT file
 
SDG
*/

/*! \file
    \brief  C entry points for core Vireo functions. Used when the runtime is built and loaded as a library
 */

using namespace Vireo;

//------------------------------------------------------------
//! EggShell functions
VIREO_EXPORT Int32 Vireo_Version();
VIREO_EXPORT void* EggShell_Create(EggShell* parent);
VIREO_EXPORT void EggShell_REPL(EggShell* pShell, const char* commands);
VIREO_EXPORT Int32 EggShell_ExecuteSlices(EggShell* pShell, Int32 numSlices);
VIREO_EXPORT void EggShell_Delete(EggShell* pShell);
VIREO_EXPORT Int32 EggShell_PeekMemory(EggShell* pShell, const char* viName, const char* eltName, Int32 bufferSize, char* buffer);
VIREO_EXPORT Int32 EggShell_PokeMemory(EggShell* pShell, const char* viName, const char* eltName, Int32 bufferSize, char* buffer);
VIREO_EXPORT void Data_WriteString(EggShell* pShell, StringRef stringObject, const unsigned char* buffer, Int32 length);
VIREO_EXPORT void Data_WriteInt32(Int32* destination, Int32 value);
VIREO_EXPORT void Data_WriteUInt32(UInt32* destination, UInt32 value);
//------------------------------------------------------------
//! Typeref functions
VIREO_EXPORT TypeRef TypeManager_Define(TypeManagerRef typeManager, const char* typeName, const char* typeString);
VIREO_EXPORT TypeRef TypeManager_FindType(TypeManagerRef typeManager, const char* typeName);
VIREO_EXPORT Int32 TypeRef_TopAQSize(TypeRef typeRef);
VIREO_EXPORT Boolean TypeRef_IsFlat(TypeRef typeRef);
VIREO_EXPORT Boolean TypeRef_IsValid(TypeRef typeRef);
VIREO_EXPORT Boolean TypeRef_HasCustomDefault(TypeRef typeRef);
VIREO_EXPORT EncodingEnum TypeRef_BitEncoding(TypeRef typeRef);
VIREO_EXPORT Int32 TypeRef_Alignment(TypeRef typeRef);
VIREO_EXPORT void TypeRef_Name(TypeRef typeRef, Int32* bufferSize, char* buffer);
VIREO_EXPORT void TypeRef_ElementName(TypeRef typeRef, Int32* bufferSize, char* buffer);
VIREO_EXPORT Int32 TypeRef_ElementOffset(TypeRef typeRef);
VIREO_EXPORT Int32 TypeRef_Rank(TypeRef typeRef);
VIREO_EXPORT Int32 TypeRef_SubElementCount(TypeRef typeRef);
VIREO_EXPORT TypeRef TypeRef_GetSubElementByPath(TypeRef typeRef, char* buffer, Int32 *offset);
VIREO_EXPORT TypeRef TypeRef_GetSubElementByIndex(TypeRef typeRef, Int32 index);
//------------------------------------------------------------
//! TypedBlock functions
VIREO_EXPORT Int32 Data_RawBlockSize(TypedBlock* object);
VIREO_EXPORT Int32 Data_Length(TypedBlock* object);
VIREO_EXPORT TypeRef Data_Type(TypedBlock* object);
VIREO_EXPORT Int32 Data_GetLength(TypedBlock* object, Int32 dimension);
VIREO_EXPORT void Data_Resize1D(TypedBlock* object, Int32 size);
VIREO_EXPORT void Data_ResizeDimensions(TypedBlock* object, Int32 rank, Int32* sizes);
VIREO_EXPORT void* Data_RawPointerFromOffset(TypedBlock* object, Int32 offset);
VIREO_EXPORT void Data_Read1Byte(TypedBlock* object, Int32 offset, Int8* value);
VIREO_EXPORT void Data_Write1Byte(TypedBlock* object, Int32 offset, Int8 value);
VIREO_EXPORT void Data_Read2Bytes(TypedBlock* object, Int32 offset, Int16* value);
VIREO_EXPORT void Data_Write2Bytes(TypedBlock* object, Int32 offset, Int16 value);
VIREO_EXPORT void Data_Read4Bytes(TypedBlock* object, Int32 offset, Int32* value);
VIREO_EXPORT void Data_Write4Bytes(TypedBlock* object, Int32 offset, Int32 value);
VIREO_EXPORT void Data_Read8Bytes(TypedBlock* object, Int32 offset, Int64* value);
VIREO_EXPORT void Data_Write8Bytes(TypedBlock* object, Int32 offset, Int64 value);
VIREO_EXPORT void Data_ReadPointer(TypedBlock* object, Int32 offset, void** value);
VIREO_EXPORT void Data_WritePointer(TypedBlock* object, Int32 offset, void* value);
VIREO_EXPORT void Data_ReadBytes(TypedBlock* object, Int32 offset, Int32 count, Int32* buffer);
VIREO_EXPORT void Data_WriteBytes(TypedBlock* object, Int32 offset, Int32 count, Int32* buffer);
//------------------------------------------------------------
//! Occurrence functions
VIREO_EXPORT void Occurrence_Set(OccurrenceRef occurrence);
