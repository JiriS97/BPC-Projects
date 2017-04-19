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

#include <math.h>
#include <stdio.h>
#include "komplex.h"

#define N 10

int main() {
	Komplex_t aa = { 1.1f, 2.2f }, bb;
	Komplex_t *pa, *pb;

	bb.Re = 3.3f;
	bb.Im = 3.4f;

	pa = &aa;
	pb = &bb;
	//print normally and using pointers
	printf("%g%+gi\n", aa.Re, aa.Im); //%g only prints used decimals
	printf("%g%+gi\n", pa->Re, pa->Im);
	printf("%g%+gi\n", bb.Re, bb.Im); //%g only prints used decimals
	printf("%g%+gi\n", pb->Re, pb->Im);

	//print using function
	PrintKomplex("Number a is:", aa);
	PrintKomplex(NULL, bb);
	PrintKomplexP("Number a is:", &aa, 1);

	PrintKomplex("Number a is:", aa);
	SwapParts(&aa, &aa);
	PrintKomplex("Swapped number a is:", aa);

	//calculate sum
	Komplex_t sum;
	sum = Add(aa, bb);
	PrintKomplex("Sum of aa and bb is:", sum);

	//create and fill array
	Komplex_t *pole = malloc(N * sizeof(Komplex_t));
	for (int i = 0; i < N; i++) {
		pole[i].Re = (float)(i - 5)*(i - 5);
		pole[i].Im = (float)i;
	}

	//and sort it
	PrintKomplexP("Unsorted array:", pole, N);
	Sort(pole, N);
	PrintKomplexP("Sorted array:", pole, N);
	free(pole);
	return 0;
}