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
void selectionSort (int); //6 +     // Don't Forget to measure time taken!
void insertionSort (int); //6 +
void bubbleSort (int); //6 +
void quickSort (int, int, int); //6 +
void fileWrite (); //7 +
void progEnd (); //8 +

/***/

void displayStu (Stu *);
void displayAll ();
void addressing ();
void update ();

void Main()
{
    //bool firstOne = 0;

    if (state == 0)
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
        printf ("File read.\n");
    }

    if (state == 1)
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

    if (state == 2)
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

    if (state == 3)
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
        int newCnt = cnt;
        for (int i = 0; i < cnt; i++)
        {
            if (mode == 1 && !strcmp (current -> name, str))
            {
                newCnt--;
                removeStu (current);
            }
            if (mode == 2 && !strcmp (current -> lastName, str))
            {
                newCnt--;
                removeStu (current);
            }
            if (mode == 3 && !strcmp (current -> ID, str))
            {
                newCnt--;
                removeStu (current);
            }
            if (mode == 4 && !strcmp (current -> city, str))
            {
                newCnt--;
                removeStu (current);
            }
            current = current -> next;
        }
        cnt = newCnt;
        current = first;
        for (int i = 0; i < cnt - 1; i++)
            current = current -> next;
        head = current;

        displayAll();
    }
    
    if (state == 4)
    {
        shuffle();
        displayAll();
    }

    if (state == 5)
    {
        int mode;
        printf ("Which algorithm?\n");
        printf ("Selection sort -> 1\n");
        printf ("Insertion sort -> 2\n");
        printf ("Bubble sort -> 3\n");
        printf ("Quick sort -> 4\n");
        scanf ("%d", &mode);
        int way;
        printf ("Enter:\n");
        printf ("Up growing -> 1\n");
        printf ("Down growing -> 0\n");
        scanf ("%d", &way); 
        addressing();
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
            quickSort (way, 1, cnt);
        end = clock();  
        takenTime = ((double) (end - start)) / CLOCKS_PER_SEC;
        update();
        displayAll();
        printf ("I took %lf seconds to sort.\n", takenTime);
    }

    if (state == 6)
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
        printf ("File updated.\n");
    }

    if (state == 7)
        progEnd();

    return;
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

void addressing ()
{
    address[0] = NULL;
    address[cnt + 1] = NULL;
    Stu * current = first;
    for (int i = 1; i <= cnt; i++)
    {
        address[i] = current;
        current = current -> next;
    }
    return;
}
void update ()
{
    first = address[1];
    head = address[cnt];
    Stu * current = first;
    for (int i = 1; i <= cnt; i++)
    {
        current -> prev = address[i - 1];
        current -> next = address[i + 1];
        current = current -> next;
    }
    return;
}
