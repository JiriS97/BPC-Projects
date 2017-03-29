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

#define _USE_MATH_DEFINES //enable math PI

#include <stdio.h>
#include <math.h>

void polToKartez(double pruvodic, double fiRad, double *px, double *py);

int main() {
	double r, fiDeg, fiRad, x, y;

	printf("Zadej pruvodic r: ");
	if (scanf("%lf", &r) != 1) {
		printf("Spatne zadani\n\a");
		return 1;
	}

	printf("Zadej uhel fi ve stupnich: ");
	if (scanf("%lf", &fiDeg) != 1) {
		printf("Spatne zadani\n\a");
		return 1;
	}

	fiRad = fiDeg*(M_PI / 180.0);
	polToKartez(r, fiRad, &x, &y);
	printf("Tento bod ma souradnice x=%lf a y=%lf\n", x, y);
	return 0;
}

void polToKartez(double pruvodic, double fiRad, double *px, double *py) {
	*px = pruvodic*cos(fiRad);
	*py = pruvodic*sin(fiRad);
}
