#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "definitions.h"

void dfs (int);
Stu cash;
Stu cash1;
bool check[100000];
int order[100000];
Stu * address[100000];

void shuffle ()
{
    for (int i = 0; i < 1000000; i++)
        check[i] = 0;
    srand (time (NULL));
    for (int i = 0; i < cnt; i++)
    {
        do
            order[i] = rand() % cnt;
        while (check[order[i]] == 1);
    }

    // Changing the Linked List
    Stu * current = first;
    // Saving the addresses
    for (int i = 0; i < cnt; i++)
    {
        address[i] = current;
        current = current -> next;
    }
    for (int i = 0; i < 1000000; i++)
        check[i] = 0;
    for (int i = 0; i < cnt; i++)
    {
        if (!check[i])
            dfs (i);
        check[i] = 1;
    }

    return;
}

void dfs (int node)
{
    strcpy (cash1.name, address[node] -> name);
    strcpy (cash1.lastName, address[node] -> lastName);
    strcpy (cash1.ID, address[node] -> ID);
    strcpy (cash1.city, address[node] -> city);

    strcpy (address[node] -> name , cash.name);
    strcpy (address[node] -> lastName, cash.lastName);
    strcpy (address[node] -> ID, cash.ID);
    strcpy (address[node] -> city, cash.city);

    strcpy (cash.name, cash1.name);
    strcpy (cash.lastName, cash1.lastName);
    strcpy (cash.ID, cash1.ID);
    strcpy (cash.city, cash1.city);

    if (check[node])
        return;

    dfs (order[node]);
    return;
}