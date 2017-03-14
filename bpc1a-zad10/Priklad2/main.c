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

#define POUZIT_MAKRO //ma se pouzit makro

#define MODUL(X, Y) (sqrt((X)*(X)+(Y)*(Y)))

double modul(double aX, double aY);

int main() {
	double x, y, r;

	printf("Zadej souradnice X a Y v [] oddelene carkami: ");
	if (scanf("[%lf,%lf]", &x, &y) != 2) {
		printf("Spatne zadani\n\a");
		return 1;
	}

#ifdef POUZIT_MAKRO
	r = MODUL(x, y);
#else
	r = modul(x, y);
#endif

	//test
	//vzdalenost = MODUL(1 + 2, 3 + 4) * 2;

	printf("Vzdalenost bodu o souradnicich x=%lf a y=%lf od pocatku je %lf\n", x, y, r);
	return 0;
}

double modul(double aX, double aY) {
	return sqrt(aX*aX + aY*aY);
}
