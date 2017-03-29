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
#include <time.h>

unsigned long long faktnerek(unsigned long long num);
unsigned long long faktrek(unsigned long long num);
unsigned long long faktrektisk(unsigned long long num);

void timer_start();
void timer_stop(char* string);

//#define TISK_CAS

int main() {
	long long num;
	int option;

	if (scanf("%lld,%d", &num, &option) != 2 || (option!=0 && option!=1)) {
		printf("chybne zadani\n");
		return 1;
	}

	if (num < 0) {
		printf("chybne zadani\n");
		return 2;
	}

	//reseni smyckou
	timer_start();
	unsigned long long i, result = 1;
	for (i = num; i > 1; i--) result *= i;
	printf("%llu\n", result);
	timer_stop("smycka trvala");

	//nerekurzivni funkci
	timer_start();
	printf("%llu\n", faktnerek(num));
	timer_stop("nerekurzivni funkce trvala");

	//rekurzivni funkci
	timer_start();
	printf("%llu\n", faktrek(num));
	timer_stop("rekurzivni funkce trvala");

	if (option) {
		//rekurzivni funkce s tiskem
		timer_start();
		printf("%llu\n", faktrektisk(num));
		timer_stop("tisk s rekurzi trval");
	}
	return 0;
}

unsigned long long faktnerek(unsigned long long num) {
	unsigned long long i, result = 1;
	for (i = num; i > 1; i--) result *= i;
	return result;
}

unsigned long long faktrek(unsigned long long num) {
	unsigned long long retval;
	if (num == 0) return 1;
	return num * faktrek(num - 1);
}

unsigned long long faktrektisk(unsigned long long num) {
	unsigned long long retval;
	if (num == 0) retval = 1;
	else retval = num * faktrektisk(num - 1);

	printf("%10llu", num);
	printf("%30llu\n", retval);

	return retval;
}

///////// TIME ///////////
clock_t start;

void timer_start() {
	start = clock();
}

void timer_stop(char* string) {
	clock_t finish = clock();
#ifdef TISK_CAS
	printf("%s ", string);
	printf("%2.3fs\n", (double)(finish - start) / CLOCKS_PER_SEC);
#endif
}
