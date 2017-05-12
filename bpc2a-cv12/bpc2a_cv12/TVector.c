//
//  TVector.c
//  bpc2a-project-template
//
//  Created by: Petr Petyovsky on 20/04/17.
//  $Id: TVector.c 289 2017-04-20 13:24:57Z petyovsky $
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


#include <stdio.h>
#include <stdlib.h>
#include "TVector.h"
#include "check.h"

TErrCode VectorCreate(TVector *aVector, size_t aCount)
	{
	if(!aVector)
		{
		fprintf(stderr, "Error: Pointer to the data structure is NULL!\n");
		return EDataNullPointer;
		}

	if(aVector->iCount && aVector->iData)
		{
		fprintf(stderr, "Error: Data structure isn't empty. Deallocate it before new allocation!\n");
		return EDataNotEmpty;
		}

	if (aVector->iCount || aVector->iData)
		{
		fprintf(stderr, "Error: Data structure values are inconsistent!\n");
		return EDataInconsistent;
		}

	if(!aCount)
		{
		fprintf(stderr, "Error: Data array size cannot be a zero!\n");
		return EDataArraySizeZero;
		}
	
	aVector->iData = calloc(aCount, sizeof(aVector->iData[0]));
	if(!aVector->iData)
		{
		fprintf(stderr, "Error: No memory for allocation!\n");
		return EDataNoMemory;
		}
	aVector->iCount = aCount;
	
	return EOk;
	} /* CreateData() */

TErrCode VectorDestroy(TVector *aVector)
	{
	if(!aVector)
		{
		fprintf(stderr, "Error: Pointer to the data structure is NULL!\n");
		return EDataNullPointer;
		}

	if(!aVector->iCount && !aVector->iData)
		{
		fprintf(stderr, "Error: Data structure already dealocated!\n");
		return EDataAlreadyDeallocated;
		}

	if(!aVector->iCount || !aVector->iData)
		{
		fprintf(stderr, "Error: Data structure is inconsistent!\n");
		return EDataInconsistent;
		}
	
	free(aVector->iData);
	
	aVector->iData = NULL;
	aVector->iCount = 0;
	
	return EOk;
	} /* DestroyData() */


TErrCode VectorSetAt(TVector *aVector, size_t aIndex, double aValue)
	{
	if(!aVector)
		{
		fprintf(stderr, "Error: Pointer to the data structure is NULL!\n");
		return EDataNullPointer;
		}

	if(!aVector->iCount && !aVector->iData)
		{
		fprintf(stderr, "Error: Data structure already dealocated!\n");
		return EDataAlreadyDeallocated;
		}

	if(!aVector->iCount || !aVector->iData)
		{
		fprintf(stderr, "Error: Data structure is inconsistent!\n");
		return EDataInconsistent;
		}

	if(aIndex >= aVector->iCount)
		{
		fprintf(stderr, "Error: Data array wrong index!\n");
		return EDataWrongIndex;
		}

	aVector->iData[aIndex] = aValue;
	
	return EOk;
	} /* SetAt() */

TErrCode VectorAt(TVector *aVector, size_t aIndex, double *aValue)
	{
	if(!aVector)
		{
		fprintf(stderr, "Error: Pointer to the data structure is NULL!\n");
		return EDataNullPointer;
		}

	if(!aVector->iCount && !aVector->iData)
		{
		fprintf(stderr, "Error: Data structure already dealocated!\n");
		return EDataAlreadyDeallocated;
		}

	if(!aVector->iCount || !aVector->iData)
		{
		fprintf(stderr, "Error: Data structure is inconsistent!\n");
		return EDataAlreadyDeallocated;
		}

	if(aIndex >= aVector->iCount)
		{
		fprintf(stderr, "Error: Data array wrong index!\n");
		return EDataWrongIndex;
		}

	if(!aValue)
		{
		fprintf(stderr, "Error: Pointer to the value is NULL!\n");
		return EDataValueNullPointer;
		}

	*aValue = aVector->iData[aIndex];

	return EOk;
	} /* At() */

TErrCode VectorStore(const TVector * const aVector, FILE * aOutp)
{
	if (aVector == NULL || aOutp == NULL) return EDataNullPointer;
	if (aVector->iData == NULL) return EDataValueNullPointer;
	if (aVector->iCount == 0) return EDataArraySizeZero;

	fprintf(aOutp, "%zu: ", aVector->iCount);
	for (unsigned u = 0; u < aVector->iCount; u++) {
		fprintf(aOutp, "%.2lf ", aVector->iData[u]);
	}

	printf("\n");
	return EOk;
}

TErrCode VectorLoad(TVector * aVector, FILE * aInput)
{
	unsigned length;
	if (aVector == NULL || aInput == NULL) return EDataNullPointer; //parameter error
	if (fscanf(aInput, "%u:", &length) != 1) return EDataInconsistent; //error in file
	TErrCode err = VectorCreate(aVector, length);
	if (err != EOk) return err; //allocation error

	for (unsigned u = 0; u < length; u++) {
		double number;
		if (fscanf(aInput, "%lf", &number) != 1) return EDataInconsistent; //error in file
		aVector->iData[u] = number;
	}
	return EOk;
}
