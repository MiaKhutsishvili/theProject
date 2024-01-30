#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include "definitions.h"

typedef struct stu Stu;

int cnt;
int choice;
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
    bool firstOne = 0;
    switch (choice)
    {
        case 1:
            if (!firstOne)
            {
                FILE * fptr = fopen ("data.txt", "r");
                for (int i = 0; i < 100; i++)
                {
                    Stu  newStu;
                    fscanf (fptr, "%s", newStu.name);
                    fscanf (fptr, "%s", newStu.lastName);
                    fscanf (fptr, "%s", newStu.ID);
                    fscanf (fptr, "%s", newStu.city);
                    stuAdd (i + 1, &newStu);
                }
                fclose (fptr);
                firstOne = 1;
            }
            else
            {
                Stu  newStu;
                int row;
                printf ("Enter name: ");
                scanf ("%s", newStu.name);
                printf ("Enter last name: ");
                scanf ("%s", newStu.lastName);
                printf ("Enter ID: ");
                scanf ("%s", newStu.ID);
                printf ("Enter city: ");
                scanf ("%s", newStu.city);
                printf ("Enter row: ");
                scanf ("%d", &row);
                stuAdd (row, &newStu);
            }
            break;
        
    }
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
