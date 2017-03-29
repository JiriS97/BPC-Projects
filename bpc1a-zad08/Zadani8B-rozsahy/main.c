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
#include <limits.h>

#define DOLNI_LIMIT -3.0
#define HORNI_LIMIT 3.0

int main() {
	int i = 0;
	double cislo;
	double min = INT_MAX;
	double max = INT_MIN;

	printf("Zadej 5 cisel v rozsahu <%lf, %lf>", DOLNI_LIMIT, HORNI_LIMIT);
	while (i < 5) {
		if (scanf("%lf", &cislo) != 1) {
			printf("Chybne zadani\n");
			return 1;
		}
		if((cislo>=DOLNI_LIMIT) && (cislo<=HORNI_LIMIT)) i++;
		else printf("Zadane cislo je mimo povoleny rozsah\n");
		if (cislo < min) min = cislo;
		if (cislo > max )max = cislo;
	}
	printf("Nejmensi cislo je %lf\n", min);
	printf("Nejvetsi cislo je %lf\n", max);
	return 0;
}
