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
        if (first != NULL)
            first -> prev = newStu;
        first = newStu;
        newStu -> prev = NULL;
    }
    else
    {
        Stu * current = first;
        for (int i = 0; i < row - 2 && i < cnt - 1; i++)
            current = current -> next;
        newStu -> prev = current;
        newStu -> next = current -> next;
        if (current != head)
            current -> next -> prev = newStu;
        current -> next = newStu;
    }

    cnt++;
    head = first;
    for (int i = 0; i < cnt - 1; i++)
        head = head -> next;
    return;
}
