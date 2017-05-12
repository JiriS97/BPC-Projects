//
//  main.c
//  bpc2a-project-template
//
//  Based on: Created by: Petr Petyovsky on 20/04/17.
//  $Id: main.c 288 2017-04-20 11:40:27Z petyovsky $
//
/*
* The MIT License (MIT)
*
* Modified 2017 Jiøí Šrámek (https://github.com/JiriS97/)
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
#include "TVector.h"
#include "TMatrix.h"
#include "check.h"

int main(int argc, char *argv[]) {
	if (argc != 2) {
		fprintf(stderr, "Error: Missing vect parameters. Program ends!\n");
		return 1;
	}

	TVector vect = {0, NULL};

	if (VectorCreate(&vect, 10)) { //allocate vector
		fprintf(stderr, "Error: Something is wrong. Program ends!\n");
		return 2;
	}

	for (int i = 0; i < 10; i++) vect.iData[i] = i; //fill directly
	for (int i = 0; i < 10; i++) VectorSetAt(&vect, i, i); //fill using function

	//print directly
	printf("Printing vect: ");
	for (int i = 0; i < 10; i++) printf("%g ", vect.iData[i]);
	printf("\n");

	VectorStore(&vect, stdout); //print using function

	if(VectorDestroy(&vect)) //free memory
		fprintf(stderr, "Error: Unable dealocate vect data!\n");

	/*if(VectorDestroy(&vect))
		fprintf(stderr, "Error: Unable dealocate output data!!\n"); //second dealocation should not be possible
		*/

	// open files
	FILE *in = fopen("data.in", "r");
	FILE *out = fopen("data.out", "w");

	TMatrix mat = { 0, NULL }; //initialize

	MatrixLoad(&mat, in); //load data from file

	MatrixStore(&mat, stdout); //print them

	MatrixSummarize(&mat); //add sum

	MatrixStore(&mat, stdout); //print them again
	MatrixStore(&mat, out); //save to output

	MatrixDestroy(&mat); //free memory

	// close files
	fclose(in);
	fclose(out);
	stat();

	return 0;
} /* main() */
