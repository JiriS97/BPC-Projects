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

#include "sd.h"
#include <stdio.h>

int fsdM(int a, int b) {
	if (a == 0 || b == 0) return 0; //chyba
	for (int i = a < b ? a : b; i > 0; --i) {
		if ((a%i == 0) && (b%i == 0)) return i;
	}
	return 0;
}

int fsdE(int a, int b) {
	if (a == 0 || b == 0) return 0; //chyba
	while (b) {
		int r = a%b;
		a = b;
		b = r;
	}
	return a;
}

int fsd(int a, int b) {
	int pocet = 1;
	int delitel = a < b ? a : b;

	if (a == 0 || b == 0) {
		printf("0\n");
		return 0; //chyba
	}
	//printf("(%d;%d) -> ", a, b);

	while (delitel > 1) {
		if ((a%delitel == 0) && (b%delitel == 0)) {
			printf("%d; ", delitel);
			pocet++;
		}
		delitel--;
	}
	printf("%d\n", delitel);
	return pocet;
}
