#include <stdio.h>
#include <string.h>
#include "definitions.h"

// 1 = name
// 2 = last name
// 3 = id
// 4 = city

void printStu (Stu *);

void searchStu (int mode, char * str)
{
    Stu * current = first;
    for (int i = 0; i < cnt; i++)
    {

        if (mode == 1 && !strcmp (current -> name, str))
            printStu (current);
        if (mode == 2 && !strcmp (current -> lastName, str))
            printStu (current);
        if (mode == 3 && !strcmp (current -> ID, str))
            printStu (current);
        if (mode == 4 && !strcmp (current -> city, str))
            printStu (current);
        current = current -> next;
    }
    return;
}

void printStu (Stu *output)
{
    printf ("Name: %s\t\t", output -> name);
    printf ("Last name: %s\t\t", output -> lastName);
    printf ("ID: %s\t\t", output -> ID);
    printf ("City: %s\t\t", output -> city);
    printf ("\n");
    return;
}
