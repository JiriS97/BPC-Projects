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

#define N 10

int mystrlen(char *string);
char *mystrrevcopy(char *src, char *dest);

int main(int argc, char *argv[]) {
	char buf[N];
	if (argc != 3) {
		printf("Nebyly zadany 2 retezce!\n");
		return 1;
	}
	printf("Delka prvniho retezce (tj. %s): %u\n", argv[1], mystrlen(argv[1]));
	printf("Delka druheho retezce (tj. %s): %u\n", argv[2], mystrlen(argv[2]));
	if ((mystrlen(argv[1]) + mystrlen(argv[2])) > N) {
		printf("Nedostatecna velikost pole!\n");
		return 2;
	}
	char *ptr = mystrrevcopy(argv[1], buf);
	mystrrevcopy(argv[2], ptr);
	printf("Vysledek revezovani a spojeni: %s\n", buf);
}

int mystrlen(char *string) {
	if (string == NULL) return -1;
	int counter = 0;
	while (string[counter] != '\0') counter++;
	return counter;
}

char *mystrrevcopy(char *src, char *dest) {
	if (src == NULL || dest == NULL) return NULL;
	unsigned size = mystrlen(src);
	for (unsigned u = 0; u < size; u++) {
		dest[u] = src[size - u - 1];
	}
	dest[size] = '\0';
	return &dest[size];
}
