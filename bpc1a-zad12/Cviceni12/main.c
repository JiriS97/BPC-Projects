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

void vymen(double *p1, double *p2);

int main() {
	double x = 1.5;
	double y = 3.3;

	printf("X=%lf @ %p\n", x, &x);
	printf("Y=%lf @ %p\n", y, &y);

	vymen(&x, &y);

	printf("X=%lf\n", x);
	printf("Y=%lf\n", y);
	return 0;
}

void vymen(double *p1, double *p2) {
	printf("Hodnota p1 je %p\n", p1);
	printf("Hodnota p2 je %p\n", p2);

	printf("p1 ukazuje na %lf\n", *p1);
	printf("p2 ukazuje na %lf\n", *p2);

	double tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
