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
#include <stdlib.h>

#include "check.h"

typedef struct{
	unsigned iPocet;
	float *iData;
	float *iTime;
}TSignal;

int NactiHodnoty(FILE *aInput, TSignal *aVal);
int UrciMinMax(const TSignal *aVal, float *aTMin, float *aTMax);

int main(int argc, char *argv[])
{
	if (argc != 2) {
		fprintf(stderr, "Chyba, nezadano jmeno vstupnoho souboru!\n");
		return 1;
	}

	FILE *inFile = fopen(argv[1], "r");
	if (inFile == NULL) {
		fprintf(stderr, "Chyba, vstupni soubor se nepovedlo otevrit!\n");
		return 2;
	}

	TSignal signal = { 0, NULL, NULL };
	float tmax, tmin;

	int err = NactiHodnoty(inFile, &signal);
	fclose(inFile);

	if (err != 0) {
		fprintf(stderr, "Chyba %d pri cteni dat \n", err);
		stat();
		return 3;
	}

	UrciMinMax(&signal, &tmin, &tmax);
	printf("<%f;%f>\n", tmin, tmax);
	free(signal.iData);
	free(signal.iTime);
	stat();
	return 0;
}

int NactiHodnoty(FILE *aInput, TSignal *aVal) {
	if (aInput == NULL) return 1;
	if (aVal == NULL) return 2;
	if ((aVal->iData != NULL) || (aVal->iTime != NULL)) return 3;

	if (!fscanf(aInput, "%u", &aVal->iPocet)) return 4;
	aVal->iData = malloc(aVal->iPocet * sizeof(float));
	if (aVal->iData == NULL) {
		aVal->iPocet = 0;
		return 5;
	}
	aVal->iTime = malloc(aVal->iPocet * sizeof(float));
	if (aVal->iTime == NULL) {
		free(aVal->iData);
		aVal->iPocet = 0;
		return 5;
	}

	for (unsigned u = 0; u < aVal->iPocet; u++) {
		if (fscanf(aInput, "%f %f", &aVal->iTime[u], &aVal->iData[u]) != 2) {
			free(aVal->iData);
			free(aVal->iTime);
			return 6;
		}
	}
	return 0;
}

int UrciMinMax(const TSignal *aVal, float *aTMin, float *aTMax) {
	if (aVal == NULL || aTMin == NULL || aTMax == NULL) return -1;
	if (aVal->iData == NULL || aVal->iTime == NULL) return -2;

	float sigMin = aVal->iData[0];
	float sigMax = aVal->iData[0];
	for (unsigned u = 0; u < aVal->iPocet; u++) {
		if (aVal->iData[u] < sigMin) {
			sigMin = aVal->iData[u];
			*aTMin = aVal->iTime[u];
		}
		if (aVal->iData[u] > sigMax) {
			sigMax = aVal->iData[u];
			*aTMax = aVal->iTime[u];
		}
	}
	return 0;
}