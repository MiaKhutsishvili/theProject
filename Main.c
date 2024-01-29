#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "definitions.h"

typedef struct stu Stu;

int cnt;
Stu * first = NULL;
Stu * head = NULL;

// Menu:
void fileRead (); //1 +
Stu * fileSearch (char *); //2 +
void stuAdd (int, Stu *); //3 + 
void stuRemove (char *); //4 +
void shuffle (); //5 +
void selectionSort (bool); //6 +     // Don't Forget to measure time taken!
void insertionSort (bool); //6 +
void bubbleSort (bool); //6 +
void quickSort (bool, Stu *, Stu *); //6 +
void fileWrite (); //7 +
void progEnd (); //8 +

/***/

void display (Stu *);

int main()
{

    return 0;
}

void display (Stu * stu)
{
    printf ("Name: %s\t\t", stu -> name);
    printf ("Last name: %s\t\t", stu -> lastName);
    printf ("ID: %s\t\t", stu -> ID);
    printf ("City: %s\t\t", stu -> city);
    printf ("\n");
    return;
}

void progEnd ()
{
    printf ("BYE.\n");
    exit (0);
    return;
}