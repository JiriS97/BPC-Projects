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

int main() {
	char pole[21] = { '\0', };
	unsigned int velka = 0;

	printf("Zadej string maximalne 20znaku: ");
	for (unsigned int i = 0; i < 20; i++) {
		if (scanf("%c", &pole[i]) != 1) {
			printf("Spatne zadani\n");
			return 1;
		}
		if (pole[i] == '\n') {
			pole[i] = '\0';
			break;
		}
	}


	unsigned int i = 0;
	while (pole[i] != '\0') {
		if ((pole[i] >= 'A') && (pole[i] <= 'Z')) {//nasel jsem velke pismeno
			velka++;//prictu pocet velkych pismen
			pole[i] -= ('A'-'a'); //pismeno nahradim malym
		}
		++i;
	}

	printf("Nalezeno %u velkych pismen\n", velka);
	printf("%s", pole);
	return 0;
}
