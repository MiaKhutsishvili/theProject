#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"

void removeStu (Stu * stu)
{
    if (stu != first)
        stu -> prev -> next = stu -> next;
    if (stu != head)
        stu -> next -> prev = stu -> prev;
    cnt--;
    if (stu == first)
        first = first -> next;
    Stu * current = first;
    for (int i = 0; i < cnt - 1; i++)
        current = current -> next;
    head = current;
    //
    free (stu);
    return;
}
