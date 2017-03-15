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
#include <stdbool.h>

int Vystup(FILE *aSoubor);

int main() {
	unsigned char soubor_vstup[] = "vstup.in";
	FILE *input = fopen(soubor_vstup, "r");
	if (input == NULL) {
		printf("Nepodarilo se otevrit vstupni soubor!\n");
		return 1;
	}
	int num = Vystup(input);
	if (num>0) {
		printf("Nacteno %d znaku\n", num);
		fclose(input);
		return 0;
	}
	fclose(input);
	return 2;
}

int Vystup(FILE *aSoubor) {
	char arr[25];
	int cnt = 0;
	enum {
		LINE_ERR = 0,
		LINE_OK,
		LINE_LAST
	}line_type = LINE_ERR;

	if (aSoubor == NULL) return -1;

	while (1) {
		for (int i = 0; i < 25; i++) {
			arr[i] = fgetc(aSoubor);
			if (arr[i] == EOF) {
				arr[i] = '\0';
				line_type = LINE_LAST;
			}
			if (arr[i] == '\n') {
				line_type = LINE_OK;
				if (i < 24) arr[i + 1] = '\0';
				break;
			}
		}
		if (line_type == LINE_ERR) return -2;
		cnt += printf("%s", arr);
		if (line_type == LINE_LAST) return cnt;
		line_type = LINE_ERR;
	}
}
