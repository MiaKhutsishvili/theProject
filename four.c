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
    if (stu == first)
        first = first -> next;
    free (stu);
    return;
}
