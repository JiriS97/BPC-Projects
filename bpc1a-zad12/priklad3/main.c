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
#include <math.h>
#include "muj.h"

#define VEL 19

int main() {
	double pole1[VEL];
	double pole2[VEL];

	unsigned index = 0;
	for (double d = 0; d <= 180; d += 10) {
		pole1[index++] = d;
	}

	f1(pole1, pole2, VEL);
	tisk(pole2, VEL);
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
