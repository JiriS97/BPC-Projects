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

#include <math.h>
#include "funkcepul.h"

double HodnotaFunkce(unsigned int aRad, double aKoef[], double aX) {
	double value = aKoef[0];
	for (; aRad; aRad--) value += aKoef[aRad] * pow(aX, aRad);
	return value;
}

double Prusecik(unsigned int aRad, double aKoef[], double aOkraje[2], double aTolerance) {
	for (long counter = 0; counter < MAX_KROKU; counter++) {
		double middle = (aOkraje[0] + aOkraje[1]) / 2;

		double low_f = HodnotaFunkce(aRad, aKoef, aOkraje[0]);
		double middle_f = HodnotaFunkce(aRad, aKoef, middle);
		double high_f = HodnotaFunkce(aRad, aKoef, aOkraje[1]);

		if (fabs(middle_f) < aTolerance) return middle;
		else if ((middle_f / low_f) > 0) aOkraje[0] = middle; //nizsi a stred maji stejna znamenka
		else aOkraje[1] = middle; //horni a stred maji stejna znamenka
	}
	return -1e-10;
}

double PrusecikRek(unsigned int aRad, double aKoef[], double aOkraje[2], double aTolerance) {
	static long counter = 0;
	counter++;

	double middle = (aOkraje[0] + aOkraje[1]) / 2;

	double low_f = HodnotaFunkce(aRad, aKoef, aOkraje[0]);
	double middle_f = HodnotaFunkce(aRad, aKoef, middle);
	double high_f = HodnotaFunkce(aRad, aKoef, aOkraje[1]);

	if (fabs(middle_f) < aTolerance) return middle;
	else if ((middle_f / low_f) > 0) aOkraje[0] = middle; //nizsi a stred maji stejna znamenka
	else aOkraje[1] = middle; //horni a stred maji stejna znamenka

	if (counter > MAX_KROKU) return -1e-10;
	return PrusecikRek(aRad, aKoef, aOkraje, aTolerance);
}
