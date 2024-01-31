#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"

void removeStu (Stu * stu)
{
    stu -> prev -> next = stu -> next;
    stu -> next -> prev = stu -> prev;
    //In car
    if (stu == first)
        first = first -> next;
    cnt--;
    Stu * current = first;
    for (int i = 0; i < cnt - 1; i++)
        current = current -> next;
    head = current;
    //
    free (stu);
    return;
}
