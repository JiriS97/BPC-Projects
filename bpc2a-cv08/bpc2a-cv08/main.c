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

#include <stdio.h>
#include <string.h>

void changeDoubles(double *a, double *b);
void fill(int *arr, int size);
void printArray(int *arr, int *last);
void changeArays(int *arrA, int *arrB, int size);

int main() {
	double d1 = 10, d2 = 20; //variables to change

	//changing without pointers
	double tmp1 = d1;
	d1 = d2;
	d2 = tmp1;

	//changing back with pointers
	double *pd1=&d1, *pd2=&d2;
	double tmp2 = *pd1;
	*pd1 = *pd2;
	*pd2 = tmp2;

	//changing again using function
	changeDoubles(&d1, &d2);

	//printing array using function
	int pole10[10], pole15[15], pole20[20];
	fill(pole10, 10);
	fill(pole15, 15);
	fill(pole20, 20);
	printArray(pole10, &pole10[9]);
	printArray(pole15, &pole15[14]);
	printArray(pole20, &pole20[19]);

	//changing arrays using functions
	int poleA[10];
	int poleB[10];
	for (int i = 0; i < 10; i++) poleA[i] = 1;
	for (int i = 0; i < 10; i++) poleB[i] = 2;
	changeArays(poleA, poleB, 10);
	return 0;
}

void changeDoubles(double *a, double *b) {
	double tmp = *a;
	*a = *b;
	*b = tmp;
}

void fill(int *arr, int size) {
	for (int i = 0; i < size; i++) arr[i] = i;
}

void printArray(int *arr, int *last) {
	for (; arr <= last; arr++) {
		printf("%d ", *arr);
	}
	printf("\n");
}

void changeArays(int *arrA, int *arrB, int size) {
	for (int i = 0; i < size; i++) {
		int tmp = arrA[i];
		arrA[i] = arrB[i];
		arrB[i] = tmp;
	}
}