/*
* The MIT License (MIT)
*
* Copyright (c) 2017 Jiøí Šrámek (https://github.com/JiriS97/)
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

#include "TMatrix.h"
#include "check.h"

TErrCode MatrixLoad(TMatrix * aMatrix, FILE * aInput)
{
	if (aMatrix == NULL || aInput == NULL) return EDataNullPointer;

	unsigned length;
	if (fscanf(aInput, "%u", &length) != 1) return EDataInconsistent; //error in file
	aMatrix->iVectors = calloc(length, sizeof(TVector));
	if (aMatrix->iVectors == NULL) return EDataValueNullPointer;
	aMatrix->iSize = length;

	for (unsigned u = 0; u < length; u++) {
		int ret_val = VectorLoad(&(aMatrix->iVectors[u]), aInput);
		if (ret_val != EOk) return ret_val;
	}
	return EOk;
}

TErrCode MatrixStore(const TMatrix * const aMatrix, FILE *aOutp)
{
	if (aMatrix == NULL || aOutp == NULL) return EDataNullPointer; //parameter error
	if (aMatrix->iSize == 0) return EDataArraySizeZero;

	fprintf(aOutp, "%u\n", aMatrix->iSize);
	for (unsigned u = 0; u < aMatrix->iSize; u++) {
		TErrCode err = VectorStore(&(aMatrix->iVectors[u]), aOutp);
		if (err != EOk) return err;
	}
	return EOk;
}

TErrCode MatrixSummarize(TMatrix * const aMatrix)
{
	size_t max_length = 0;
	for (unsigned u = 0; u < aMatrix->iSize; u++) {
		if (aMatrix->iVectors[u].iCount > max_length) max_length = aMatrix->iVectors[u].iCount;
	}
	TVector *new_pointer = realloc(aMatrix->iVectors, (aMatrix->iSize + 1) * sizeof(TVector));
	if (new_pointer  == NULL) {
		//error alloc
	}
	aMatrix->iVectors = new_pointer;
	aMatrix->iSize++;
	memset(&(aMatrix->iVectors[aMatrix->iSize - 1]), 0, sizeof(TVector));
	VectorCreate(&(aMatrix->iVectors[aMatrix->iSize-1]), max_length);

	for (unsigned col = 0; col < max_length; col++) {
		for (unsigned row = 0; row < (aMatrix->iSize - 1); row++) {
			if (&(aMatrix->iVectors[row].iData[col]) == NULL) continue;
			aMatrix->iVectors[aMatrix->iSize - 1].iData[col] += aMatrix->iVectors[row].iData[col];
		}
	}
	
	return 0;
}

TErrCode MatrixDestroy(TMatrix * aMatrix)
{
	if (aMatrix == NULL) return EDataNullPointer;
	if (aMatrix->iVectors == NULL) return EDataAlreadyDeallocated;
	if (aMatrix->iSize == 0) return EDataArraySizeZero;

	for (unsigned u = 0; u < aMatrix->iSize; u++) {
		free(aMatrix->iVectors[u].iData);
	}

	free(aMatrix->iVectors);

	aMatrix->iVectors = NULL;
	aMatrix->iSize = 0;
	return EOk;
}
