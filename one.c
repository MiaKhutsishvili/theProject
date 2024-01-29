#include <stdio.h>
#include <stdlib.h>

void fileRead ()
{
    FILE * fptr = fopen ("data.txt", "r");
    int i = 0;
    printf ("#\t\tName:\t\tLast name:\t\tID:\t\tCity:\t\t\n");
    while (!feof (fptr))
    {
        i++;
        char str[100000];
        fgets (str, 100000, fptr);
        printf ("%d\t\t%s", i, str);
    }
    fclose (fptr);
    return;
}