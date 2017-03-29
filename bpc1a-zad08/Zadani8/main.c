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
	unsigned int rok;

	printf("Zadej rok: ");
	if (scanf("%u", &rok)!=1) {
		printf("Spatny vstup\n");
		return 1;
	}
	/*
	if (((rok % 4 == 0)&&(rok % 100))||(rok % 400 == 0)) {//(delitelny 4 a nedelitelny 100) nebo delitelny 400
		printf("Rok %u je prestupny\n", rok);
	}
	else {
		printf("Rok %u neni prestupny\n", rok);
	}*/
	if (rok % 4 == 0) {
		if (rok % 100 != 0) {
			printf("Rok %u je prestupny\n", rok);
		}
		else if (rok % 400 == 0) {
			printf("Rok %u je prestupny\n", rok);
		}
		else {
			printf("Rok %u neni prestupny\n", rok);
		}
	}
	return 0;
}
