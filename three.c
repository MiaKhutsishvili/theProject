#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>
#include "definitions.h"

void addStu (int row, Stu * input)
{
    Stu * current = first;
    for (int i = 0; i < cnt; i++)
    {
        if (!strcmp (input -> ID, current -> ID))
        {
            printf ("ERROR. Same ID had been already added.\n");
            return;
        }
        current = current -> next;
    }
    Stu * newStu = (Stu *) malloc (sizeof (Stu));
    for (int i = 0; i < strlen (input -> name); i++)    
        input -> name[i] = tolower (input -> name[i]);
    strcpy (newStu -> name, input -> name);
    
    for (int i = 0; i < strlen (input -> lastName); i++)    
        input -> lastName[i] = tolower (input -> lastName[i]);
    strcpy (newStu -> lastName, input -> lastName);
    
    strcpy (newStu -> ID, input -> ID); 
    
    for (int i = 0; i < strlen (input -> city); i++)    
        input -> city[i] = tolower (input -> city[i]);
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
        current = first;
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
