#include <stdio.h>
#include <stdlib.h>
#include "definitions.h"

void fileRead ()
{
    FILE * fptr = fopen ("data.txt", "r");
    int i = 0;
    printf ("#\t\tName:\t\tLast name:\t\tID:\t\tCity:\t\t\n");
    while (i < fileCnt)
    {
        i++;
        char str[1000];
        fgets (str, 1000, fptr);
        printf ("%d\t\t%s", i, str);
    }
    fclose (fptr);
    return;
}
