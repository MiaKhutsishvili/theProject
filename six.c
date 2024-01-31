#include <stdio.h>
#include <string.h>
#include "definitions.h"

Stu * address[1000];

Stu * compare (Stu *, Stu *, int);


void selectionSort (int mode)
{
    for (int i = 1; i <= cnt; i++)
        for (int j = i + 1; j <= cnt; j++)
        {
            Stu * stu =  compare (address[i], address[j], mode);
            address[j] = compare (address[i], address[j], (mode + 1) % 2);
            address[i] = stu;
        }
    return;
}

void insertionSort (int mode)
{
    for (int i = 1; i <= cnt; i++)
        for (int j = i - 1; j > 0; j--)
        {
            Stu * stu =  compare (address[j + 1], address[j], mode);
            address[j + 1] = compare (address[j + 1], address[j], (mode + 1) % 2);
            address[j] = stu;
        }
    return;
}

void bubbleSort (int mode)
{
    for (int i = 1; i <= cnt; i++)
        for (int j = 1; j <= cnt - i; j++)
        {
            Stu * stu =  compare (address[j + 1], address[j], mode);
            address[j + 1] = compare (address[j + 1], address[j], (mode + 1) % 2);
            address[j] = stu;
        }
    return;
}

void quickSort (int mode, int start, int end)
{
    if (end - start < 1)
        return;
    Stu * pivot = address[end];
    int left = start; 
    int right = end - 1;
    while (left != right)
    {
        while (compare (address[left], pivot, mode) != pivot && left < right)
            left++;
        while (compare (address[left], pivot, mode) == pivot && right > left)
            right--;
        Stu * stu = address[left];
        address[left] = address[right];
        address[right] = stu; 
    }
    int mid = end;
    while (mid > start && compare (address[mid], address[mid - 1], mode) == address[mid])
    {
        pivot = address[mid];
        address[mid] = address[mid - 1];
        address[mid - 1] = pivot; 
        mid--;
    }   
    quickSort (mode, start, mid - 1);
    quickSort (mode, mid + 1, end);
    return;
}

Stu * compare (Stu * A, Stu * B, int mode)
{
    if (mode)
    {
        // Finding min
        if (strcmp (A -> lastName, B -> lastName) < 0)
            return A;
        else if (strcmp (A -> lastName, B -> lastName) > 0)
            return B;
        if (strcmp (A -> name, B -> name) < 0)
            return A;
        else if (strcmp (A -> name, B -> name) > 0)
            return B;
        if (strcmp (A -> ID, B -> ID) < 0)
            return A;
        else if (strcmp (A -> ID, B -> ID) > 0)
            return B;
    }
    else
    {
        // Finding max
        if (strcmp (A -> lastName, B -> lastName) > 0)
            return A;
        else if (strcmp (A -> lastName, B -> lastName) < 0)
            return B;
        if (strcmp (A -> name, B -> name) > 0)
            return A;
        else if (strcmp (A -> name, B -> name) < 0)
            return B;
        if (strcmp (A -> ID, B -> ID) > 0)
            return A;
        else if (strcmp (A -> ID, B -> ID) < 0)
            return B;
    }
}

