/*
 * The MIT License (MIT)
 *
 * Copyright (c) 2017 Jiří Šrámek (https://github.com/JiriS97/)
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
#include "funkcepul.h"

#define RAD_POLYNOMU 3

int main() {
	double koef[RAD_POLYNOMU + 1];
	double tolerance, interval[2];

	for (int i = RAD_POLYNOMU; i; i--) {
		if (scanf("%lf;", &koef[i]) != 1) return 1;
	}
	if (scanf("%lf", koef) != 1) return 1;

	if (scanf("%lf;%lf;%lf", &interval[0], &interval[1], &tolerance) != 3) return 1;
	if (interval[0] > interval[1]) return 2;
	if (tolerance <= 0) return 3;

	printf("Vysledek (nerekurzivne) je %lf +- %lf\n", Prusecik(RAD_POLYNOMU, koef, interval, tolerance), tolerance);
	printf("Vysledek (rekurzivne) je %lf +- %lf\n", PrusecikRek(RAD_POLYNOMU, koef, interval, tolerance), tolerance);
	return 0;
}
