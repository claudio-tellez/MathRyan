/*
PROGRAM multiplication2332.c

Generates 50 multiplications
(by 23 or 32, randomly) 
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
    int number1[10];
    int number2[10];
	
    srand(time(NULL)); 
    FILE *textfile;

    if ((textfile = fopen("mults2332.txt", "w")) == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    for (line = 0; line < 5; line++) {
        for (i = 0; i < 10; i++) {
            number1[i] = rand() % 900 + 100; 
            printf("   %3d   ", number1[i]);
            fprintf(textfile, "   %3d   ", number1[i]);
        }
        printf("\n");
        fprintf(textfile, "\n");

        for (i = 0; i < 10; i++) {
            number2[i] = rand() % 2 == 0 ? 23 : 32;
            printf("X  %3d   ", number2[i]);
            fprintf(textfile, "X  %3d   ", number2[i]);
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
