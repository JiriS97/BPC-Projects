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

int main() {
	double pole[N] = { 0, };
	double minimum, maximum, prumer=0;
	unsigned int i = 0;

	printf("Celkem zadej %u cisel.\n", N);

	for (i = 0; i < N; ++i) {
		printf("Ted zadavas cislo %u z %u: ", i+1, N);
		if (scanf("%lf", &pole[i]) != 1) {
			printf("Chybne zadani\n\a");
			return 1;
		}
	}

	minimum = maximum = pole[0];
	for (i = 0; i < N; ++i) {
		if (pole[i] < minimum) minimum = pole[i];
		if (pole[i] > maximum) maximum = pole[i];
		prumer += pole[i];
	}

	prumer /= N;
	printf("Maximum je %lf\n", maximum);
	printf("Minimum je %lf\n", minimum);
	printf("Stredni hodnota je: %lf\n", prumer);
	return 0;
}
