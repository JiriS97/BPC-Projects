/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Jiří Šrámek (https://github.com/JiriS97/)
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
#include <stdbool.h>

int CtiData(FILE *aVstup, unsigned *aPocSlov, unsigned *aPocRadku);
int Vystup(FILE *aInput, FILE *aOutput, unsigned aPocRadku, unsigned aUlozRadku);

int main() {
	unsigned char fname[256] = { '\0', };
	unsigned char output[256] = { '\0', };

	scanf("%s", fname); //nacteni prvniho nazvu
	scanf("%s", output); //nacteni druheho nazvu

	FILE *f_input = fopen(fname, "r");
	if (f_input == NULL) {
		printf("Nepodarilo se otevrit vstupni soubor: %s\n", fname);
		return 1;
	}

	FILE *f_output = fopen(output, "w");
	if (f_output == NULL) {
		printf("Nepodarilo se otevrit vystupni soubor: %s\n", output);
		return 2;
	}

	unsigned pocSlov, pocRadku;
	if (CtiData(f_input, &pocSlov, &pocRadku)!=0) {
		printf("Chyba pri volani funkce CtiData\n");
		return 3;
	}
	printf("V souboru %s je %d radku a %d slov\n", fname, pocRadku, pocSlov);
	rewind(f_input);

	int prekopirovatRadku;
	scanf("%d", &prekopirovatRadku);

	if (Vystup(f_input, f_output, pocRadku, prekopirovatRadku) != 0) {
		printf("Chyba pri volani funkce Vystup\n");
		return 4;
	}

	fclose(f_input);
	fclose(f_output);
	return 0;
}

int CtiData(FILE *aVstup, unsigned *aPocSlov, unsigned *aPocRadku) {
	*aPocRadku = 0;
	*aPocSlov = 0;

	if (aVstup == NULL) return 1;

	bool byloPismeno = false;
	while (1) {
		char c = fgetc(aVstup);
		switch (c) {
		case '-':
		case ' ':
		case '\t':
			byloPismeno = false;
			(*aPocSlov)++;
			break;

		case '\n':
			byloPismeno = false;
			(*aPocRadku)++;
			(*aPocSlov)++;
			break;

		case EOF:
			if(byloPismeno) (*aPocSlov)++;
			return 0;

		default:
			byloPismeno = true;
		}
	}
}

int Vystup(FILE *aInput, FILE *aOutput, unsigned aPocRadku, unsigned aUlozRadku) {
	if ((aInput == NULL) || (aOutput == NULL)) return -1;

	int preskocRadku = aPocRadku - aUlozRadku;
	if (preskocRadku < 0) preskocRadku = 0;
	for (int i = 0; i < preskocRadku; i++) while (fgetc(aInput) != '\n');
	while (1) {
		char c = fgetc(aInput);
		if (c == EOF) return 0;
		fprintf(aOutput, "%c", c);
	}
}
