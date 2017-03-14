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
#include <string.h>

char table[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/"; //dekodovaci tabulka

int Pozice(char PrevadenyZnak) {
	/*for (int i = 0; i < strlen(table); i++) {
		if (table[i] == PrevadenyZnak) return i;
	}
	return -1;*/
	char *ptr;
	ptr = strchr(table, PrevadenyZnak);
	if (ptr) return (ptr - table);
	return -1;
}

//dekoduje 4B v Base64 na 3 znaky
int decB64(char in[4], char out[3]) {
	char tmp[4]; //neprepisovat vstup

	int mode = 3; //prevedu vse (ABCD)
	if (in[3] == '=') mode = 2; //prevedu 2 (ABC=)
	if (in[2] == '=') mode = 1; //prevedu 1 (AB==)

	//prevod znaku na index v dekodovaci tabulce (adresa znaku v poli - adresa pole = index)
	tmp[0] = Pozice(in[0]);
	tmp[1] = Pozice(in[1]);
	tmp[2] = Pozice(in[2]);
	tmp[3] = Pozice(in[3]);

	if ((tmp[0] < 0) || (tmp[1] < 0) || (tmp[2] < 0) || (tmp[3] < 0)) return -1;//jeden ze znaku neni v tabulce, chyba

	//samotny prevod
	out[0] = ((tmp[0] << 2) & 0xFC) | ((tmp[1] >> 4) & 0x3);
	out[1] = (mode != 1) ? ((tmp[1] << 4) & 0xF0) | ((tmp[2] >> 2) & 0xF) : 0;
	out[2] = (mode == 3) ? ((tmp[2] << 6) & 0xC0) | (tmp[3] & 0x3F) : 0;
	return mode; //vse ok, v out je vysledek
}

//zakoduje 3 znaky na 4B v Base64
int encB64(char in[3], char out[4]) {
	//samotny prevod
	out[0] = (in[0] >> 2) & 0x3F;
	out[1] = ((in[0] << 4) & 0x30) | ((in[1] >> 4) & 0xF);
	out[2] = ((in[1] << 2) & 0x3C) | ((in[2] >> 6) & 0x3);
	out[3] = in[2] & 0x3F;

	//pro dany znak nemame tabulku, chyba
	if ((out[0] >= strlen(table)) || (out[0] < 0) || (out[1] >= strlen(table)) || (out[1] < 0) || (out[2] >= strlen(table)) || (out[2] < 0) || (out[3] >= strlen(table)) || (out[3] < 0)) return -1;

	//do out ulozim znaky odpovidajici podle dekodovaci tabulky a indexu
	out[0] = table[out[0]];
	out[1] = table[out[1]];
	out[2] = table[out[2]];
	out[3] = table[out[3]];
	return 0; //vse ok, v out je vysledek
}

int dekodovat(char in[], char out[]) {
	int j = 0;
	for (int i = 0; in[i]; i += 4) {
		if (decB64(&in[i], &out[j]) == 0) return -1;
		j += 3;
	}
	return 0;
}

int main(int argc, char *argv[]) {
	char enc[65536];
	char dec[65536] = { '\0', };

	if (argc != 3) {
		printf("Program se spousti program.exe in.txt out.txt\n");
		return -1;
	}

	FILE *input = fopen(argv[1], "r");
	FILE *output = fopen(argv[2], "w");
	if (input == NULL) {
		fclose(input);
		fclose(output);
		printf("Vstupni soubor neexistuje!\n");
		return -2;
	}

	if (input == NULL) {
		fclose(input);
		fclose(output);
		printf("Vystupni soubor nelze zalozit!\n");
		return -3;
	}

	//nactu si soubor do pole, soubor max delky ENC
	for (int i = 0; i < sizeof(enc); i++) {
		char c = fgetc(input);
		if (c == EOF) break;
		enc[i] = c;
	}

	printf("Dekoduji zpravu... ");
	if (dekodovat(enc, dec) == -1) {
		fclose(input);
		fclose(output);
		printf("Neplatny format!\n");
		return -4;
	}

	printf("OK\n");
	fprintf(output, "%s", dec);
	printf("Zprava je ulozena v %s\n", argv[2]);
	fclose(input);
	fclose(output);
	return 0;
}
