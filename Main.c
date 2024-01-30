#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"

typedef struct stu Stu;

int cnt, fileCnt;
int choice;
Stu * first = NULL;
Stu * head = NULL;

// Menu:
void fileRead (); //1 +
void searchStu (int, char *); //2 +
void addStu (int, Stu *); //3 + 
void removeStu (Stu *); //4 +
void shuffle (); //5 +
void selectionSort (bool); //6 +     // Don't Forget to measure time taken!
void insertionSort (bool); //6 +
void bubbleSort (bool); //6 +
void quickSort (bool, Stu *, Stu *); //6 +
void fileWrite (); //7 +
void progEnd (); //8 +

/***/

void displayStu (Stu *);
void displayAll ();

int main()
{
    bool firstOne = 0;
    while (true)
    {
    
    // Testing
    printf ("Enter:\n");
    printf ("1 -> read the file\n");
    printf ("2 -> search the file\n");
    printf ("3 -> add a studen\n");
    printf ("4 -> remove a student\n");
    printf ("5 -> shuffle the list\n");
    printf ("6 -> sort the list\n");
    printf ("7 -> write the file\n");
    printf ("8 -> exit the program\n");
    scanf ("%d", &choice);

    if (choice == 1)
    {
        /*if (!firstOne)
        {
            FILE * fptr = fopen ("data.txt", "r");
            for (int i = 0; i < 100; i++)
            {
                Stu  newStu;
                fscanf (fptr, "%s", newStu.name);
                fscanf (fptr, "%s", newStu.lastName);
                fscanf (fptr, "%s", newStu.ID);
                fscanf (fptr, "%s", newStu.city);
                addStu (i + 1, &newStu);
            }
            fclose (fptr);
            firstOne = 1;
        }*/
        fileRead ();
    }

    if (choice == 2)
    {
        printf ("What do you want to search?\n");
        printf ("Name -> 1\n");
        printf ("Last name -> 2\n");
        printf ("ID -> 3\n");
        printf ("City -> 4\n");
        int mode;
        scanf ("%d", &mode);
        char toBeSearched[20];
        scanf ("%s", toBeSearched);
        searchStu (mode, toBeSearched);
    }

    if (choice == 3)
    {
        printf ("enter the row to add: ");
        int row;
        scanf ("%d", &row);
        Stu newStu;
        printf ("Enter name: ");
        scanf ("%s", newStu.name);
        printf ("Enter last name: ");
        scanf ("%s", newStu.lastName);
        printf ("Enter ID: ");
        scanf ("%s", newStu.ID);
        printf ("Enter city: ");
        scanf ("%s", newStu.city);
        addStu (row, &newStu);
            
        displayAll();
    }

    if (choice == 4)
    {
        printf ("What do you want to remove?\n");
        printf ("Name -> 1\n");
        printf ("Last name -> 2\n");
        printf ("ID -> 3\n");
        printf ("City -> 4\n");
        int mode;
        scanf ("%d", &mode);
        char str[20];
        scanf ("%s", str);
        printf ("All students with %s in their information will be deleted.\n", str);
        Stu * current = first;
        for (int i = 0; i < cnt; i++)
        {
            if (mode == 1 && !strcmp (current -> name, str))
                removeStu (current);
            if (mode == 2 && !strcmp (current -> lastName, str))
                removeStu (current);
            if (mode == 3 && !strcmp (current -> ID, str))
                removeStu (current);
            if (mode == 4 && !strcmp (current -> city, str))
                removeStu (current);
            current = current -> next;
        }

        displayAll();
    }
    
    if (choice == 5)
    {
        shuffle();
        displayAll();
    }

    if (choice == 6)
    {
        int mode;
        printf ("Which algorithm?\n");
        printf ("Selection sort -> 1\n");
        printf ("Insertion sort -> 2\n");
        printf ("Bubble sort -> 3\n");
        printf ("Quick sort -> 4\n");
        scanf ("%d", &mode);
        bool way;
        printf ("Enter:\n");
        printf ("In a growing way -> 1\n");
        printf ("Else -> 0\n");
        scanf ("%d", way); 
        clock_t start, end;
        double takenTime;
        start = clock();
        if (mode == 1)
            selectionSort (way);
        if (mode == 2)
            insertionSort (way);
        if (mode == 3)
            bubbleSort (way);
        if (mode == 4)
            quickSort (way, first, head);
        end = clock();  
        takenTime = ((double) (end - start)) / CLOCKS_PER_SEC;
        displayAll();
        printf ("I took %lf seconds to sort.\n", takenTime);
    }

    if (choice == 7)
    {
        fileWrite ();
        FILE * fptr = fopen ("data.txt", "r");
        FILE * bptr = fopen ("Binary_data.bin", "rb");
        while (!feof (fptr))
        {
            char str[1000];
            fgets (str, 1000, fptr);
            fwrite (str, 1, 1000, bptr);
        }
    }

    if (choice == 8)
        progEnd();

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

void displayAll ()
{
    Stu * current = first;
    for (int i = 0; i < cnt; i++)
    {
        display (current);
        current = current -> next;
    }
    return;
}
