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

#define RESENI1

int stat[256] = { 0, };

int main(int argc, char *argv[]) {
	if (argc != 2) { //overeni parametru
		printf("Neplatne parametry!\n");
		return 1;
	}

	FILE *input = fopen(argv[1], "r"); //vstup pro cteni
	if (input == NULL) {
		printf("Nepovedlo se otevrit vstup!\n");
		return 2;
	}

#ifdef RESENI1
	int c;
	long pocet = 0;
	while (c = fgetc(input), c != EOF) {
		stat[c]++;
		pocet++;
	}
#else
	long pocet = 0;
	unsigned char buffer[64];
	
	while (!feof(input)) {
		int nacteno = fread(buffer, 1, sizeof(buffer), input);
		for (int i = 0; i < nacteno; i++) {
			stat[buffer[i]]++;
			pocet++;
		}
	}
#endif

	for (int i = 0; i < 256; i++) printf("0x%X | %7d | %.2lf%%\n", i, stat[i], (double)stat[i] / pocet);
	printf("Celkem %ld znaku\n", pocet);
	fclose(input); //zavru a koncim
	return 0;
}