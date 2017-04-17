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
#include <stdio.h>
#include "funkce_d.h"

#include "check.h"

// zde bude funkce main
int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Nepodarilo se otevrit vstupni soubor!\n");
		return 1; //nemam nazev souboru
	}

	FILE *f = fopen(argv[1], "r");
	if (f == NULL) { //nepovedlo se otevrit soubor
		fprintf(stderr, "Nepodarilo se otevrit vstupni soubor!\n");
		return 1;
	}

	int pocet_cisel;
	if (fscanf(f, "%d", &pocet_cisel) != 1) { //nactu pocet cisel
		fclose(f); //nepovedlo se, chyba
		return 5;
	}

	int *pole = malloc((pocet_cisel+1) * sizeof(int)); //tohle se podle zadani nema osetrovat?, a musim si ulozit i pocet cisel do [0] pro fce
	pole[0] = pocet_cisel;
	for (int i = 1; i <= pocet_cisel; i++) {
		if (fscanf(f, "%d", &pole[i]) != 1) { //chyba pri nacitani pole
			fclose(f);
			free(pole);
			return 5;
		}
	}

	int *pole_limit1 = NULL;
	int *pole_limit2 = NULL;
	int delka1 = Vyber(pole, &pole_limit1, 10); //prvni s limitem 10
	int delka2 = Vyber(pole, &pole_limit2, 20); //druhe s limitem 20

	if (delka1 < 0 || delka2 < 0) {
		fclose(f);
		free(pole_limit1);
		free(pole_limit2);
		return 3; //chyba pri zpracovani
	}

	fclose(f);
	free(pole);
	free(pole_limit1);
	free(pole_limit2);
	stat();
	return 0; //vse ok
}

