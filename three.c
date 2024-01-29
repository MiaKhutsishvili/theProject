#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"

void addStu (int row, Stu * input)
{
    Stu * newStu = (Stu *) malloc (sizeof (Stu));
    strcpy (newStu -> name, input -> name);
    strcpy (newStu -> lastName, input -> lastName);
    strcpy (newStu -> ID, input -> ID); 
    strcpy (newStu -> city, input -> city); 

    // Addding to the Linked List 
    if (row <= 1)
    {
        newStu -> next = first;
        first -> prev = newStu;
        first = newStu;
    }
    else
    {
        Stu * current = first;
        for (int i = 0; i < row - 1 && current -> next != NULL; i++)
            current = current -> next;
        newStu -> prev = current;
        newStu -> next = current -> next;
        if (current != head)
            current -> next -> prev = newStu;
        current -> next = newStu;
    }

    cnt++;
    return;
}