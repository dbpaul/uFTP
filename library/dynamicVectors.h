/*
 * The MIT License
 *
 * Copyright 2018 Ugo Cirmignani.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#ifndef DYNAMIC_VECTORS_H
#define	DYNAMIC_VECTORS_H

#include "dynamicMemory.h"

#ifdef	__cplusplus
extern "C" {
#endif

struct DYNV_VectorString
{
	DYNMEM_MemoryTable_DataType *memoryTable;
    char **Data;
    int Size;
    int *ElementSize;
    void (*PushBack)(void *TheVector, char * TheString, int StringLenght);
    void (*PopBack)(void *TheVector);
    void (*Destroy)(void *TheVector);
    void (*DeleteAt)(void *TheVector, int index);
} typedef DYNV_VectorString_DataType;

struct DYNV_VectorGenericDataStruct
{
	DYNMEM_MemoryTable_DataType *memoryTable;
    void **Data;
    int Size;
    int *ElementSize;
    void (*PushBack)(void *TheVectorGeneric, void * TheElementData, int TheElementSize);
    void (*PopBack)(void *TheVector, void (*DeleteElement)(void *TheElementToDelete));
    void (*SoftPopBack)(void *TheVector);
    void (*Destroy)(void *TheVector, void (*DeleteElement)(struct DYNV_VectorGenericDataStruct *TheElementToDelete));
    void (*SoftDestroy)(void *TheVector);
    void (*DeleteAt)(void *TheVector, int index, void (*DeleteElement)(void *TheElementToDelete));
    int  (*SearchElement)(void *TheVectorGeneric, void * TheElementData);
} typedef DYNV_VectorGenericDataType;


void DYNV_VectorString_Init(DYNV_VectorString_DataType *TheVector);
void DYNV_VectorString_PushBack(DYNV_VectorString_DataType *TheVector, char * TheString, int StringLenght);
void DYNV_VectorString_PopBack(DYNV_VectorString_DataType *TheVector);
void DYNV_VectorString_Destroy(DYNV_VectorString_DataType *TheVector);
void DYNV_VectorString_DeleteAt(DYNV_VectorString_DataType *TheVector, int index);
void DYNV_VectorGeneric_Init(DYNV_VectorGenericDataType *TheVectorGeneric);
void DYNV_VectorGeneric_InitWithSearchFunction(DYNV_VectorGenericDataType *TheVectorGeneric, int (*SearchFunction)(void *TheVectorGeneric, void * TheElementData));
void DYNV_VectorGeneric_PushBack(DYNV_VectorGenericDataType *TheVectorGeneric, void * TheElementData, int TheElementSize);
void DYNV_VectorGeneric_PopBack(DYNV_VectorGenericDataType *TheVector, void (*DeleteElementFunction)(void *TheElementToDelete));
void DYNV_VectorGeneric_SoftPopBack(DYNV_VectorGenericDataType *TheVector);
void DYNV_VectorGeneric_Destroy(DYNV_VectorGenericDataType *TheVector, void (*DeleteElementFunction)(DYNV_VectorGenericDataType *TheVector));
void DYNV_VectorGeneric_SoftDestroy(DYNV_VectorGenericDataType *TheVector);
void DYNV_VectorGeneric_DeleteAt(DYNV_VectorGenericDataType *TheVector, int index, void (*DeleteElementFunction)(void *TheElementToDelete));

#ifdef	__cplusplus
}
#endif

#endif	/* DYNAMIC_VECTORS_H */

