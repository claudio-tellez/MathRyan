/*
PROGRAM subtractions1.c

Generates 50 simple subtractions 
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

    if ((textfile = fopen("subtractions.txt", "w")) == NULL) {
        printf("Unable to open file.\n");
        return 1;
    }

    for (line = 0; line < 5; line++) {
        // Generate the first vector
        for (i = 0; i < 10; i++) {
            number1[i] = rand() % 90 + 10; 
            printf("   %3d   ", number1[i]);
            fprintf(textfile, "   %3d   ", number1[i]);
        }
        printf("\n");
        fprintf(textfile, "\n");

        // Generate the second vector with values less than the first vector
        for (i = 0; i < 10; i++) {
            number2[i] = rand() % number1[i];
			if (number2[i] == 0)
			{
		      printf("-  %3d   ", number2[i]+9);
              fprintf(textfile, "+  %3d   ", number2[i]+9);
			}
			else
			{
			  printf("-  %3d   ", number2[i]);
              fprintf(textfile, "+  %3d   ", number2[i]);
			}
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
