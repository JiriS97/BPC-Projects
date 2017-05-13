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

typedef struct{
	unsigned iCelek, iCit, iJmen;  //Promìnné pro složky zlomku 
}TZlomek;



int Uprav(TZlomek *aData);

int Nasob(FILE *aInp, TZlomek **aData);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Neni uvedno jmeno vstupniho souboru!\n");
		return 2;
	}

	FILE *input = fopen(argv[1], "r");
	if (input == NULL) {
		fprintf(stderr, "Nezdarilo se otevrit vstupni soubor %s!\n", argv[1]);
		return 1;
	}

	TZlomek *pzlomek = NULL;
	int err = Nasob(input, &pzlomek);
	fclose(input);

	if (err <= 0) {
		fprintf(stderr, "Chyba ve funkci Nasob: %d !\n", err);
		if(err == -5) free(pzlomek);
		stat();
		return err;
	}

	printf("%u/%u/%u [%d]\n", pzlomek->iCelek, pzlomek->iCit, pzlomek->iJmen, err);
	free(pzlomek);
	stat();
	return 0;
}

int Uprav(TZlomek * aData) {
	if (aData == NULL) return -1;
	if (aData->iCit < aData->iJmen) return 0;
	//option 1
	aData->iCelek += aData->iCit / aData->iJmen;
	aData->iCit %= aData->iJmen;
	/*
	//option 2
	while (aData->iCit >= aData->iJmen) {
		aData->iCit -= aData->iJmen;
		aData->iCelek++;
	}*/
	return 1;
}

int Nasob(FILE * aInp, TZlomek **aData) {
	if (aInp == NULL) return -1;
	if (aData == NULL) return -2;
	if ((*aData) == NULL) {
		(*aData) = malloc(sizeof(TZlomek));
		if ((*aData) == NULL) return -4;
		(*aData)->iCelek = 0;
		(*aData)->iCit = 1;
		(*aData)->iJmen = 1;
	}
	unsigned num_rows;
	if (!fscanf(aInp, "%u", &num_rows)) return -5;
	for (unsigned row = 0; row < num_rows; row++) {
		TZlomek read;
		if (fscanf(aInp, "%u/%u/%u", &read.iCelek, &read.iCit, &read.iJmen) != 3) return -6; //can not read numbers
		(*aData)->iCit += (*aData)->iCelek * (*aData)->iJmen;  //convert to impropper fractions
		read.iCit += read.iCelek * read.iJmen;
		(*aData)->iCelek = read.iCelek = 0;

		(*aData)->iCit *= read.iCit; //multiply
		(*aData)->iJmen *= read.iJmen;	
	}
	Uprav(*aData); //normalize
	return (int)num_rows;
}
