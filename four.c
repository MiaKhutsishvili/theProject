#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "definitions.h"

void removeStu (Stu * stu)
{
    stu -> prev -> next = stu -> next;
    stu -> next -> prev = stu -> prev;
    free (stu);

    cnt--;
    return;
}
