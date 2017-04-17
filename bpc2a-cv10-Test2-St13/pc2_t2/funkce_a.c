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

// include potrebnych hlavickovych souboru
#include <stdlib.h>
#include <string.h>

#include "check.h"
#include "funkce_a.h"

// zde bude zdrojovy kod pozadovanych funkci

unsigned PozpatkuTiskRet(char **aRadek) {
	if (aRadek == NULL || *aRadek == NULL) return 0;
	unsigned counter = 0;

	char *end = strchr(*aRadek, '\0')-1;//pointer na znak pred '\0'
	while (end >= *aRadek) {
		printf("%c", *end);
		end--;
		counter++;
	}
	printf("\n");
	free(*aRadek);
	*aRadek = NULL;
	return counter;
}

int NactiRadek(char **aRadek, FILE *aFile) {
	if (aRadek == NULL || aFile == NULL) return -1;
	if (*aRadek != NULL) return -2;

	int pocet;
	fscanf(aFile, "%d:", &pocet);
	
	char *buffer = malloc((pocet + 1) * sizeof(char));
	if (buffer == NULL) return -3;

	for (int i = 0;  i < pocet; i++) {
		if (fscanf(aFile, "%c", &buffer[i]) != 1) return -4;
	}
	buffer[pocet] = '\0'; //nechci \n ale \0
	*aRadek = buffer;
	return 0;
}
