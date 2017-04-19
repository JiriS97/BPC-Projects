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

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "komplex.h"

void PrintKomplex(char *str, const Komplex_t komplex) { 
	if(str) printf("%s %g%+gi\n", str, komplex.Re, komplex.Im); //%g only prints used decimals
	else printf("%g%+gi\n", komplex.Re, komplex.Im);
}

void PrintKomplexP(char *str, const Komplex_t komplex[], int length) {
	for (int i = 0; i < length; i++) {
		if (str) printf("%s %g%+gi\n", str, komplex[i].Re, komplex[i].Im); //%g only prints used decimals
		else printf("%g%+gi\n", komplex[i].Re, komplex[i].Im);
	}
}

int SwapParts(const Komplex_t * const aIn, Komplex_t * const aOut) {
	if (aIn == NULL) return 1;
	if (aOut == NULL) return 2;
	float tmpRe = aIn->Re; //to allow use as SwapParts(&a, &a);
	aOut->Re = aIn->Im;
	aOut->Im = tmpRe;
	return 0;
}

Komplex_t Add(const Komplex_t aVal1, const Komplex_t aVal2) {
	Komplex_t sum;
	sum.Re = aVal1.Re + aVal2.Re;
	sum.Im = aVal1.Im + aVal2.Im;
	return sum;
}

int _KomplexCompare(void const *inA, void const *inB) {
	Komplex_t *a=(Komplex_t *)inA, *b=(Komplex_t *)inB;
	float mag1 = sqrtf(powf(a->Re, 2) + powf(a->Im, 2));
	float mag2 = sqrtf(powf(b->Re, 2) + powf(b->Im, 2));
	if (mag1 < mag2) return -1;
	if (mag1 > mag2) return 1;
	return 0;
}

int Sort(Komplex_t aValues[], const unsigned aLen) {
	if (aValues == NULL) return 1;
	if (aLen == 0) return 2;
	qsort(aValues, aLen, sizeof(*aValues), _KomplexCompare);
	return 0;
}


