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
#include <Windows.h>


int main(void) {
	double a, b, c, D;
	cplx_t x1, x2;

	printf("Reseni rovnice ve tvaru ax2+bx+c=0\n");
	printf("Zadej cisla a, b, c (oddeluj Enterem): ");
	if (scanf("%lf %lf %lf", &a, &b, &c) != 3) {
		printf("Tohle asi nebylo cislo...\n");
		return 1;
	}
	D = b*b - 4 * a*c;
	if (D >= 0) {//realne koreny
		x1.re = (-b + sqrt(D)) / (2*a);
		x2.re = (-b - sqrt(D)) / (2*a);
		x1.im = x2.im = 0;
	} else {//imaginarni koreny
		x1.re = x2.re = 0;
		x1.im = sqrt(-D) / (2 * a);
		x2.im = -x1.im;
	}
	printf("Koren x1: %lf%+lfj\n", x1.re, x1.im);
	printf("Koren x2: %lf%+lfj\n", x2.re, x2.im);
	return 0;
}
