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

void removeComments(FILE *in, FILE *out);

int main(int argc, char *argv[]) {
	FILE *in, *out;

	if (argc != 3) {
		printf("Chybne parametry\n");
		return 1;
	}

	in = fopen(argv[1], "r");
	if (in == NULL) {
		printf("Nelze otevrit vstup\n");
		return 2;
	}
	out = fopen(argv[2], "w");
	if (out == NULL) {
		printf("Nelze otevrit vystup\n");
		fclose(in);
		return 3;
	}

	removeComments(in, out);

	fclose(in);
	fclose(out);
	return 0;
}

typedef enum {
	TEXT, //text v souboru
	LOMITKO, //lomitko ve textu
	KOMENT_CPP, // tj. //
	KOMENT_C, // tj. /* */
	HVEZDICKA,  //hvezdicka v C komentu
	STEJNY_RADEK_CPP_KOMENT, //rozdeleni radku CPP komentu pomoci '\'
	STRING, //napr. "abc"
	STRING_SPECIAL //znak ve stringu po '\' tj. "abc\n \"def\" "
}stav_t;

/*TODO: Detect this as a comment:
/\
/ j(); // part of a two-line comment
*/
void removeComments(FILE *in, FILE *out) {
	stav_t stav = TEXT;
	while (!feof(in)) {
		char c = fgetc(in);
		if (c == EOF) return;

		switch (stav) {
		case TEXT: //jakykoliv text
			if (c == '/') stav = LOMITKO;
			else {
				if (c == '"') stav = STRING;
				fprintf(out, "%c", c);
			}
			break;

		case STRING: //jsem ve stringu, tady nehledam komenty
			if (c == '"') stav = TEXT;
			else if (c == '\\') stav = STRING_SPECIAL; //bude specialni znak po '\'
			fprintf(out, "%c", c);
			break;

		case STRING_SPECIAL: //znak po '\' napr \n, \", jinak by \" ukoncilo string
			fprintf(out, "%c", c);
			stav = STRING;
			break;

		case LOMITKO: //bylo lomitko v textu
			if (c == '/') stav = KOMENT_CPP;
			else if (c == '*') stav = KOMENT_C;
			else {
				stav = TEXT;
				fprintf(out, "/%c", c); //vypsat minule lomitko i znak
			}
			break;

		case KOMENT_CPP: //komentar s // ukonceny \n
			if (c == '\n') {
				fprintf(out, "%c", c);
				stav = TEXT;
			}
			else if (c == '\\') stav = STEJNY_RADEK_CPP_KOMENT; //radek pokracuje po '\'
			break;

		case STEJNY_RADEK_CPP_KOMENT:
			if (c == '\n') stav = KOMENT_CPP; //skoncil radek s CPP komentem ukonceny '\', pokracuje CPP koment
			break;

		case KOMENT_C: //jsem v komentari /*
			if (c == '*') stav = HVEZDICKA;
			break;

		case HVEZDICKA: //narazil jsem na * kdyz jsem byl v komentar /*
			if (c == '/') {
				fprintf(out, " "); //nahradim komentar mezerou
				stav = TEXT;
			}
			else if (c != '*') stav = KOMENT_C;
			break;
		}
	}
}