//
//  TVector.h
//  bpc2a-project-template
//
//  Created by: Petr Petyovsky on 20/04/17.
//  $Id: TVector.h 289 2017-04-20 13:24:57Z petyovsky $
//
/*
* The MIT License (MIT)
*
* Modified 2017 Jiøí Šrámek (https://github.com/JiriS97/)
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


#ifndef __TDATA_H__
#define __TDATA_H__

#include <stdlib.h>
#include "check.h"

typedef enum{
	EOk = 0,
	EDataNotEmpty,
	EDataInconsistent,
	EDataArraySizeZero,
	EDataNoMemory,
	EDataAlreadyDeallocated,
	EDataNullPointer,
	EDataValueNullPointer,
	EDataWrongIndex,
}TErrCode;

typedef struct {
	size_t iCount;
	double *iData;
}TVector;

TErrCode VectorCreate(TVector *aVector, size_t aCount);
TErrCode VectorDestroy(TVector *aVector);
TErrCode VectorSetAt(TVector *aVector, size_t aIndex, double aValue);
TErrCode VectorAt(TVector *aVector, size_t aIndex, double *aValue);

TErrCode VectorStore(const TVector* const aVector, FILE *aOutp);
TErrCode VectorLoad(TVector *aVector, FILE *aInput);
#endif /* __TDATA_H__ */
