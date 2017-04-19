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
#include "funkce_c.h"


int Pridej(int **aPole, int aVal, int aDelka)
{
	if ((aPole == NULL) && (aDelka != 0)) return -1; //kdyz je delka 0, tak to neni chyba
	int *novePole = malloc((aDelka+1) * sizeof(int));
	if (novePole == NULL) return -3;

	for (int i = 0; i < aDelka; i++) novePole[i] = (*aPole)[i]; //nakopiruju data
	novePole[aDelka] = aVal; //pridam nova
	if(aDelka) free(*aPole); //uvolnim stare pole, ale jen kdyz uz melo delku (tj. existovalo)
	*aPole = novePole; //predam nove
	return aDelka+1;
}

int NactiData(int **aData, FILE * aFile)
{
	if (aData == NULL || aFile == NULL) return -1;
	if (*aData != NULL) return -2;
	int *pointer = NULL;

	int num, pocet=0;

	while (fscanf(aFile, "%d", &num) == 1) {//nacitam cisla
		pocet=Pridej(&pointer, num, pocet); //pridam
		if (pocet < 0) { //nepovedlo se pridat, tam probiha take alokace
			*aData = pointer; //chyba
			return -3;
		}
	}
	//az budu tady tak neslo nacist cislo
	if (!feof(aFile)) return -4; //jestli to nebylo koncem radku tak to je chyba nacitani 

	*aData = pointer; //vse ok
	return pocet;
}
