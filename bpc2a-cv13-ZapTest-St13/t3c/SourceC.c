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

#include <stdio.h>
#include <stdlib.h>

#include "check.h"

#define MAX 10

typedef enum{
	ERR_OK = 0,
	ERR_BAD
}TErr;

typedef struct {
	unsigned iRad;
	float iKoef[MAX];
	//unsigned iErr;
	TErr iErr;
}TPoly;

int NactiPolynomy(FILE *aInput, TPoly  **aPole, unsigned *aPocet);

TPoly SectiPolynomy(const TPoly *aVal, unsigned aPocet);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Nezadano jmeno souboru s daty!\n");
		return 1;
	}

	FILE *inFile = fopen(argv[1], "r");
	if (inFile == NULL) {
		fprintf(stderr, "Chyba, vstupni soubor se nepovedlo otevrit!\n");
		return 2;
	}

	TPoly *polynomy=NULL;
	unsigned pocet;
	int err = NactiPolynomy(inFile, &polynomy, &pocet);
	fclose(inFile);
	if (err) {
		fprintf(stderr, "Chyba %d pri cteni dat!\n", err);
		stat();
		return 3;
	}

	TPoly soucet = SectiPolynomy(polynomy, pocet);
	printf("Souctem je polynom %u. radu, koeficienty: ", soucet.iRad);
	for (unsigned u = 0; u <= soucet.iRad; u++) printf("%g ", soucet.iKoef[u]); //%g abych vypsal jen pouzita mista
	printf("\n");

	free(polynomy);
	stat();
	return 0;
}

int NactiPolynomy(FILE *aInput, TPoly  **aPole, unsigned *aPocet) {
	if (aInput == NULL) return 1;
	if (aPocet == NULL) return 2;
	if (aPole == NULL) return 3;
	if (*aPole != NULL) return 4;

	if (!fscanf(aInput, "%u", aPocet)) return 5;
	//TPoly *tmp = malloc((*aPocet) * sizeof(TPoly));
	TPoly *tmp  = calloc(*aPocet, sizeof(TPoly)); //nuluji se i koeficienty
	if (tmp == NULL) {
		*aPocet = 0;
		return 5; //chyba alokace
	}

	for (unsigned row = 0; row < *aPocet; row++) {
		if (!fscanf(aInput, "%u", &(tmp[row].iRad))) { //chyba cteni
			*aPocet = 0;
			free(*aPole);
			return 8;
		}
		if (tmp[row].iRad > MAX) { //moc dlouhe
			*aPocet = 0;
			free(*aPole);
			return 7;
		}

		for (unsigned u = 0; u <= tmp[row].iRad; u++) { //nactiam koeficienty
			if (!fscanf(aInput, "%f", &(tmp[row].iKoef[u]))) { //chyba cteni
				*aPocet = 0;
				free(*aPole);
				return 8;
			}
		}
	}
	(*aPole) = tmp;
	return 0;
}

TPoly SectiPolynomy(const TPoly *aVal, unsigned aPocet) {
	TPoly ret = { 0, };
	ret.iErr = ERR_OK;

	if (aVal == NULL || aPocet == 0){
		ret.iErr = ERR_BAD;
		return ret;
	}

	for (unsigned u = 0; u < MAX; u++) { //scitam vsechny koeficienty
		for (unsigned v = 0; v < aPocet; v++) { //scitam aPocet polynomu
			ret.iKoef[u] += aVal[v].iKoef[u];
		}
	}

	for(unsigned u=0;u<aPocet;u++) if (aVal[u].iRad > ret.iRad) ret.iRad = aVal[u].iRad; //zjistim rad
	return ret;
}