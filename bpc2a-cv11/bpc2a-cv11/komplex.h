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

#ifndef KOMPLEX_H
#define KOMPLEX_H

#include <stdlib.h>

typedef struct {
	float Re;
	float Im;
}Komplex_t;

void PrintKomplex(char *str, const Komplex_t komplex);
void PrintKomplexP(char *str, const Komplex_t komplex[], int length);
int SwapParts(const Komplex_t * const aIn, Komplex_t * const aOut);
Komplex_t Add(const Komplex_t aVal1, const Komplex_t aVal2);
int Sort(Komplex_t aValues[], const unsigned aLen);

#endif