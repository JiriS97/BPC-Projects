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
#include <stdio.h>
#include "funkce_a.h"

#include "check.h"

// zde bude funkce main
int main(int argc, char *argv[]) {
	if (argc != 2) return 2;

	FILE *f = fopen(argv[1], "r");
	if (f == NULL) {
		printf("Vstupni soubor se nepodarilo otevrit\n");
		return 5;
	}

	char *radek = NULL;
	int pocet_znaku = 0;
	fpos_t pos = 0;

	//zjistim si pocet znaku
	do {
		(void)fgetc(f);
		pocet_znaku++;
	} while (!feof(f));
	rewind(f); //vratim se na zacatek

	//a pak ho hlidam, feof by reagoval az na nepovedene cteni a zatim by fce hodily chybu
	while (pos < pocet_znaku) { //pos je typu pos_t, ten je definovany jako 64bit int
		int ret1 = NactiRadek(&radek, f);
		unsigned ret2 = PozpatkuTiskRet(&radek);
		if (ret1 != 0 || ret2 == 0) {
			fclose(f);
			stat();
			return 3;
		}
		fgetpos(f, &pos);
	}

	fclose(f);
	stat();
	return 0;
}