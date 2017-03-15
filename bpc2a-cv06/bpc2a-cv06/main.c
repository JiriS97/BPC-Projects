#include <stdio.h>

#define RESENI1

int stat[256] = { 0, };

int main(int argc, char *argv[]) {
	if (argc != 2) { //overeni parametru
		printf("Neplatne parametry!\n");
		return 1;
	}

	FILE *input = fopen(argv[1], "r"); //vstup pro cteni
	if (input == NULL) {
		printf("Nepovedlo se otevrit vstup!\n");
		return 2;
	}

#ifdef RESENI1
	int c;
	long pocet = 0;
	while (c = fgetc(input), c != EOF) {
		stat[c]++;
		pocet++;
	}
#else
	long pocet = 0;
	unsigned char buffer[64];
	
	while (!feof(input)) {
		int nacteno = fread(buffer, 1, sizeof(buffer), input);
		for (int i = 0; i < nacteno; i++) {
			stat[buffer[i]]++;
			pocet++;
		}
	}
#endif

	for (int i = 0; i < 256; i++) printf("0x%X | %7d | %.2lf%%\n", i, stat[i], (double)stat[i] / pocet);
	printf("Celkem %ld znaku\n", pocet);
	fclose(input); //zavru a koncim
	return 0;
}