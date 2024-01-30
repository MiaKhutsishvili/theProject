#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "definitions.h"

void swap (Stu *, Stu *);

void selectionSort (bool mode)
{
    Stu * address[1000];
    Stu * current = first;
    for (int i = 0; i < cnt; i++)
    {
        address[i] = current;
        current = current -> next;
    }

    for (int i = 0; i < cnt; i++)
    {
        Stu * min = address[i];
        for (int j = i + 1; j < cnt; j++)
        {
            if (mode)
            {
                if (strcmp (min -> lastName, address[j] -> lastName) > 0)
                    swap (min, address[j]);

                if (!strcmp (min -> lastName, address[j] -> lastName) && 
                    strcmp (min -> name, address[j] -> name) > 0)
                    swap (min, address[j]);
            }
            else
            {
                if (strcmp (min -> lastName, address[j] -> lastName) < 0)
                    swap (min, address[j]);

                if (!strcmp (min -> lastName, address[j] -> lastName) && 
                    strcmp (min -> name, address[j] -> name) < 0)
                    swap (min, address[j]);
            }
        }
    }
    return;
}

void insertionSort (bool mode)
{
    Stu * address[1000];
    Stu * current = first;
    for (int i = 0; i < cnt; i++)
    {
        address[i] = current;
        current = current -> next;
    }

    for (int i = 0; i < cnt; i++)
    {
        current = address[i];
        for (int j = i - 1; j >= 0; j--)
        {
            if (mode)
            {
                if (strcmp (current -> lastName, address[j] -> lastName) < 0)
                    swap (current, address[j]);
                else if ((current -> lastName, address[j] -> lastName) > 0)
                    break;
                else
                {
                    if (!strcmp (current -> lastName, address[j] -> lastName) && 
                        strcmp (current -> name, address[j] -> name) < 0)
                        swap (current, address[j]);
                    else
                        break;
                }
            }
            else
            {
                if (strcmp (current -> lastName, address[j] -> lastName) > 0)
                    swap (current, address[j]);
                else if ((current -> lastName, address[j] -> lastName) < 0)
                    break;
                else
                {
                    if (!strcmp (current -> lastName, address[j] -> lastName) && 
                        strcmp (current -> name, address[j] -> name) > 0)
                        swap (current, address[j]);
                    else
                        break;
                }
            }
        }
    }
    return;
}

void bubbleSort (bool mode)
{
    Stu * address[1000];
    Stu * current = first;
    for (int i = 0; i < cnt; i++)
    {
        address[i] = current;
        current = current -> next;
    }

    for (int i = 0; i < cnt; i++)
    {
        for (int j = 1; j < cnt; j++)
        {
            if (mode)
            {
                if (strcmp (address[j - 1] -> lastName, address[j] -> lastName) > 0)
                    swap (address[j - 1], address[j]);

                if (!strcmp (address[j - 1] -> lastName, address[j] -> lastName) && 
                    strcmp (address[j - 1] -> name, address[j] -> name) > 0)
                    swap (address[j - 1], address[j]);
            }
            else
            {
                if (strcmp (address[j - 1] -> lastName, address[j] -> lastName) < 0)
                    swap (address[j - 1], address[j]);

                if (!strcmp (address[j - 1] -> lastName, address[j] -> lastName) && 
                    strcmp (address[j - 1] -> name, address[j] -> name) < 0)
                    swap (address[j - 1], address[j]);
            }
        }
    }
    return;
}

void quickSort (bool mode, Stu * start, Stu * end)
{
    if (start == end)
        return;
    Stu * pivot = end;
    Stu * left = start;
    Stu * right = end;
    while (left != right)
    {
        if (mode)
        {
            while (left != right &&
                (strcmp (right -> lastName, pivot -> lastName) <= 0 ||
                (!strcmp (right -> lastName, pivot -> lastName)  && strcmp (right -> name, pivot -> name)) <= 0) )
                    right = right -> prev;
            while (left != right && 
                (strcmp (right -> lastName, pivot -> lastName) > 0 ||
                (!strcmp (right -> lastName, pivot -> lastName)  && strcmp (right -> name, pivot -> name)) > 0) )
                    left = left -> next;
        }
        else
        {
            while (left != right &&
                (strcmp (right -> lastName, pivot -> lastName) > 0 ||
                (!strcmp (right -> lastName, pivot -> lastName)  && strcmp (right -> name, pivot -> name)) > 0) )
                    right = right -> prev;
            while (left != right && 
                (strcmp (right -> lastName, pivot -> lastName) <= 0 ||
                (!strcmp (right -> lastName, pivot -> lastName)  && strcmp (right -> name, pivot -> name)) <= 0) )
                    left = left -> next;
        }
        swap (left, right);
    }
    Stu * current = start;
    while (strcmp (current -> ID, pivot -> ID))
        current = current -> next;
    quickSort (mode, start, current);
    quickSort (mode, current, end);
    return;
}

void swap (Stu * A, Stu * B)
{
    Stu cash;
    strcpy (cash.name, A -> name);
    strcpy (cash.lastName, A -> lastName);
    strcpy (cash.ID, A -> ID);
    strcpy (cash.city, A -> city);

    strcpy (A -> name, B -> name);
    strcpy (A -> lastName, B -> lastName);
    strcpy (A -> ID, B -> ID);
    strcpy (A -> city, B -> city);

    strcpy (B -> name, cash.name);
    strcpy (B -> lastName, cash.lastName);
    strcpy (B -> ID, cash.ID);
    strcpy (B -> city, cash.city);

    return;
}
