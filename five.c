#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "definitions.h"

bool check[1000];
Stu * before[1000];
Stu * after[1000];

void shuffle ()
{
    for (int i = 0; i < 1000; i++)
        check[i] = 0;
    srand (time (NULL));
    
    Stu * current = first;
    for (int i = 1; i <= cnt; i++)
    {
        before[i] = current;
        current = current -> next;
    }
    for (int i = 1; i <= cnt; i++)
    {
        int shuffle;
        do
            shuffle = rand() % cnt + 1;
        while (check[shuffle]);
        check[shuffle] = 1;
        after[i] = before[shuffle];
    }
    after[0] = NULL;
    after[cnt + 1] = NULL;
    first = after[1];
    head = after[cnt];
    current = first;
    for (int i = 1; i <= cnt; i++)
    {
        current -> prev = after[i - 1];
        current -> next = after[i + 1];
        current = current -> next;
    }
    return;
}
