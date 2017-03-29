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
#include "sd.h"

int main() {
	int a, b;

	if (scanf("%d,%d", &a, &b) != 2) {
		fprintf(stderr, "chybne zadani\n");
		return 2;
	}

	int resultFSDM, resultFSDE, resultFSD;
	resultFSDM = fsdM(a, b);
	resultFSDE = fsdE(a, b);

	if (resultFSDM == 0 || resultFSDE == 0) {
		fprintf(stderr, "chybne zadani\n");
	}

	printf("%d\n", resultFSDM);
	printf("%d\n", resultFSDE);

	resultFSD = fsd(a, b);
	if (resultFSD == 0) {
		fprintf(stderr, "chybne zadani\n");
		return 1;
	}

	printf("%d", resultFSD);
	return 0;
}
