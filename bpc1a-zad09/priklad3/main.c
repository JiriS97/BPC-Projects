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

#define N 8

void prehod(int *a, int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	int pole[N] = { 0, };
	unsigned int minimum = 0;

	printf("Celkem zadej %u cisel.\n", N);

	for (unsigned int i = 0; i < N; ++i) {
		printf("Ted zadavas cislo %u z %u: ", i + 1, N);
		if (scanf("%i", &pole[i]) != 1) {
			printf("Chybne zadani\n\a");
			return 1;
		}
	}

	for (unsigned int j = 0; j < N; ++j) {
		minimum = j;
		for (unsigned int i = j; i < N; ++i) {
			if (pole[i] < pole[minimum]) minimum = i;//ulozim si pozici nejmensiho cisla
		}
		prehod(&pole[j], &pole[minimum]);//prvni bude nejmensi
	} //pak uz prvni neresim a pokracuju od druheho atd az na konec pole

	//ted mam setridene pole, uz ho jen vypsat
	printf("Setridene pole je: {");
	for (unsigned int i = 0; i < N; ++i) {//vypis cele pole
		if (i == (N - 1)) printf("%i", pole[i]); //pokud je to posledni prvek, uz za nej nepis carku
		else printf("%i, ", pole[i]);//jinak ho napis i s carkou, at to trochu vypada
	}
	printf("}\n");
	return 0;
}
