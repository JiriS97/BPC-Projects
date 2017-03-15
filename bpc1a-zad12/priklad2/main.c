/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2016 Jiří Šrámek (https://github.com/JiriS97/)
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
#include <string.h>
#include <math.h>

int prevod(char *ptr, unsigned *result);

int main(int argc, char *argv[]) {
	unsigned cislo;
	printf("Mam %i parametru:\n", argc);
	for (int i = 0; i < argc; ++i) {
		int result = prevod(argv[i], &cislo);
		printf("%s	Vysledek: %i Cislo: %u\n", argv[i], result, cislo);
	}
	return 0;
}

int prevod(char * string, unsigned * result) {
	unsigned delka = strlen(string);
	*result = 0;
	for (unsigned int i = 0; i < delka; ++i) {
		if ((string[i]<'0') || (string[i]>'9')) return -1;
		*result += (string[i] - '0') * (unsigned int)pow(10, delka - i - 1);
	}
	return 0;
}
