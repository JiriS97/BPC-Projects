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

// include potrebnych hlavickovych souboru
#include <stdlib.h>

#include "check.h"
#include "funkce_c.h"

// zde bude zdrojovy kod pozadovanych funkci

int Pridej(int **aPole, int aVal, int aDelka)
{
	if (aPole == NULL) return -1;
	int *novePole = malloc((aDelka+1) * sizeof(int));
	if (novePole == NULL) return -3;

	for (int i = 0; i < aDelka; i++) novePole[i] = (*aPole)[i]; //nakopiruju data
	novePole[aDelka] = aVal; //pridam nova
	free(*aPole); //uvolnim stare pole
	*aPole = novePole; //predam nove
	return aDelka+1;
}

int NactiData(int **aData, FILE * aFile)
{
	if (aData == NULL || aFile == NULL) return -1;
	if (*aData != NULL) return -2;
	int *pointer = malloc(1 * sizeof(int));
	if (pointer == NULL) return -3;

	int num, pocet=0;
	while (fscanf(aFile, "%d", &num) == 1) {//nacitam cisla
		pocet=Pridej(&pointer, num, pocet); //pridam
		if (pocet < 0) { //nepovedlo se
			*aData = pointer; //chyba
			return -4;
		}
	}

	*aData = pointer; //vse ok
	return pocet;
}
