/*
* The MIT License (MIT)
*
* Copyright (c) 2017 Jiøí Šrámek (https://github.com/JiriS97/)
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
#include "check.h"

void printArrayINT(int *arr, int size);
void printArrayDOUBLE(double *arr, int size);
void changeArrays(void **arrA, void **arrB);

#define ARRAY_SIZE 8

int main() {
	int *poleINT1, *poleINT2;
	double *poleDOUBLE1, *poleDOUBLE2;

	//allocate INT arrays
	poleINT1 = malloc(ARRAY_SIZE * sizeof(int));
	poleINT2 = malloc(ARRAY_SIZE * sizeof(int));
	for (int i = 0; i < ARRAY_SIZE; i++) {
		poleINT1[i] = i;
		poleINT2[i] = 20 + i;
	}

	//allocate DOUBLE arrays
	poleDOUBLE1 = malloc(ARRAY_SIZE * sizeof(double));
	poleDOUBLE2 = malloc(ARRAY_SIZE * sizeof(double));
	for (int i = 0; i < ARRAY_SIZE; i++) {
		poleDOUBLE1[i] = i+0.3;
		poleDOUBLE2[i] = 20.3 + i;
	}

	printf("Playing with INT arrays..................\n");
	printArrayINT(poleINT1, ARRAY_SIZE);
	printArrayINT(poleINT2, ARRAY_SIZE);

	int *tmpINT = poleINT1;
	poleINT1 = poleINT2;
	poleINT2 = tmpINT;

	printf("Changed arrays:\n");
	printArrayINT(poleINT1, ARRAY_SIZE);
	printArrayINT(poleINT2, ARRAY_SIZE);

	changeArrays(&poleINT1, &poleINT2);

	printf("Changed back:\n");
	printArrayINT(poleINT1, ARRAY_SIZE);
	printArrayINT(poleINT2, ARRAY_SIZE);

	printf("\nPlaying with DOUBLE arrays..................\n");
	printArrayDOUBLE(poleDOUBLE1, ARRAY_SIZE);
	printArrayDOUBLE(poleDOUBLE2, ARRAY_SIZE);

	double *tmpDOUBLE = poleDOUBLE1;
	poleDOUBLE1 = poleDOUBLE2;
	poleDOUBLE2 = tmpDOUBLE;

	printf("Changed arrays:\n");
	printArrayDOUBLE(poleDOUBLE1, ARRAY_SIZE);
	printArrayDOUBLE(poleDOUBLE2, ARRAY_SIZE);

	changeArrays(&poleDOUBLE1, &poleDOUBLE2);

	printf("Changed back:\n");
	printArrayDOUBLE(poleDOUBLE1, ARRAY_SIZE);
	printArrayDOUBLE(poleDOUBLE2, ARRAY_SIZE);

	free(poleINT1);
	free(poleINT2);
	free(poleDOUBLE1);
	free(poleDOUBLE2);
	stat(); //checker
}

void printArrayINT(int *arr, int size) {
	printf("Array on address 0x%p: { ", arr);
	for (int i = 0; i < size; i++) printf("%d ", arr[i]);
	printf("}\n");
}

void printArrayDOUBLE(double *arr, int size) {
	printf("Array on address 0x%p: { ", arr);
	for (int i = 0; i < size; i++) printf("%.1lf ", arr[i]);
	printf("}\n");
}

void changeArrays(void **arrA, void **arrB) {
	int *tmp;
	tmp = *arrA;
	*arrA = *arrB;
	*arrB = tmp;
}
