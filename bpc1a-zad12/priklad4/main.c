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
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "muj.h"

int prevod(char * string, unsigned * result);

int main(int argc, char *argv[]) {
	unsigned krok, delka;
	if (argc < 2) {
		printf("Nezadany paramter\n");
		return 1;
	}

	if (prevod(argv[1], &krok) == -1) {
		printf("Parametr neni cislo\n");
		return 2;
	}

	//vypocet potrebneho poctu kroku
	unsigned num = 0;
	delka = 1;
	while (num < 180) {
		num += krok;
		delka++;
	}

	//alokace pameti
	double *pole1 = malloc(delka*sizeof(double));
	double *pole2 = malloc(delka*sizeof(double));

	//chyba alokace
	if ((pole1 == NULL) || (pole2 == NULL)) {
		printf("Chyba alokace pameti\n");
		return 3;
	}

	//naplneni pole
	for (unsigned i = 0; i < delka; ++i) {
		pole1[i] = krok*i;
	}
	if (pole1[delka - 1] > 180) pole1[delka - 1] = 180;

	f1(pole1, pole2, delka);
	tisk(pole2, delka);

	free(pole1);
	free(pole2);
	return 0;
}

void f1(double *in, double *out, unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		out[i] = sin(2 * in[i]) + 1;
	}
}

void tisk(double *arr, unsigned size) {
	for (unsigned i = 0; i < size; ++i) {
		printf("Hodnota prvku [%u] je %.2lf\n", i, arr[i]);
	}
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
