#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"

void stuRemove (char * ID)
{
    int line = 0;
    // Removing from the Linked List
    Stu * current = first;
    for (int i = 0; i < cnt; i++)
    {
        line++;
        if (!strcmp (current -> ID, ID))
            break;
        current = current -> next;
    }
    current -> prev -> next = current -> next;
    current -> next -> prev = current -> prev;
    free (current);

    cnt--;
    return;
}