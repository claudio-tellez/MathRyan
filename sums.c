/*
PROGRAM sums.c

Generates 50 3-digits sums
for training my son Ryan.

Author: Claudio Andres Tellez Zepeda

Date: 01 nov 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char *argv[]) 
{
	int i = 0;
	int line = 0;
	int number1 = 0;
	int number2 = 0;
	
    srand(time(NULL)); 
    FILE *textfile;

    if ((textfile = fopen("sums.txt", "w")) == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    for (line = 0; line < 5; line++) {
        for (i = 0; i < 10; i++) {
            number1 = rand() % 900 + 100; 
            printf("   %3d   ", number1);
            fprintf(textfile, "   %3d   ", number1);
        }
        printf("\n");
        fprintf(textfile, "\n");

        for (i = 0; i < 10; i++) {
            number2 = rand() % 900 + 100; 
            printf("+  %3d   ", number2);
            fprintf(textfile, "+  %3d   ", number2);
        }
        printf("\n");
        fprintf(textfile, "\n");

        for (i = 0; i < 10; i++) {
            printf("______   ");
            fprintf(textfile, "______   ");
        }
        printf("\n");
        fprintf(textfile, "\n");

        if (line < 5) {
            printf("\n\n\n");
            fprintf(textfile, "\n\n\n");
        }
    }

    fclose(textfile);
    return 0;
}