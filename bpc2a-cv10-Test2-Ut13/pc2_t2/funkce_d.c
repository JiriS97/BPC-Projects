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

#include <stdlib.h>

#include "check.h"

int NadLimit(int *aData, int aLimit, int aDelka)
{
	if (aData == NULL) return -1;

	unsigned pocet = 0;
	for (int i = 0; i < aDelka; i++) {
		if (aData[i] > aLimit) pocet++;
	}
	return pocet;
}

int Vyber(int * aVstup, int ** aVystup, int aLimit, int aDelka)
{
	if (aVstup == NULL || aVystup == NULL) return -1;
	if (*aVystup != NULL) return -2;

	int pocet = NadLimit(aVstup, aLimit, aDelka);
	*aVystup = malloc(pocet * sizeof(int));
	if (*aVystup == NULL) return -3; //alokace se nepovedla

	int pocitadlo = 0;
	for (int i = 0; i < aDelka; i++) {
		if (aVstup[i] > aLimit) (*aVystup)[pocitadlo++] = aVstup[i];
	}

	return pocitadlo;
}