#include <stdio.h>
#include "definitions.h"

void fileWrite ()
{
    FILE * fptr = fopen ("data.txt", "w");
    Stu * current;
    for (int i = 0; i < cnt; i++)
    {
        fprintf (fptr, "Name: %s\t\t", current -> name);
        fprintf (fptr, "Last name: %s\t\t", current -> lastName);
        fprintf (fptr, "ID: %s\t\t", current -> ID);
        fprintf (fptr, "City: %s\t\t", current -> city);
        fprintf (fptr, "\n");
        current = current -> next;
    }
    fclose (fptr);
    return;
}