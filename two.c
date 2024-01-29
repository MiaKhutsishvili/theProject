#include <stdio.h>
#include <string.h>
#include "definitions.h"

Stu * fileSearch (char * ID)
{
    Stu * current = first;
    for (int i = 0; i < cnt; i++)
    {
        if (!strcmp (current -> ID, ID))
            break;
        current = current -> next;
    }
    return current;
}