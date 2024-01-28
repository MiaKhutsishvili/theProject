#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct stu
{
    char name[20];
    char lastName[20];
    char stuNum[20];
    char cityBorn[20];
    struct stu * next;
    struct stu * prev;

}
Stu;

Stu * Last = NULL;
Stu * First = NULL; 
bool checkIfReadIsDone;

// Menu
void read (); // 1
void search (); // 2
Stu addStu (int); // 3
void deleteStu (int); // 4
void randOrd (); // 5
void sort (); // 6
void write (); // 7
void end (); // 8

int main()
{

}

void read ()
{
    checkIfReadIsDone = 1;
    FILE * Fptr = fopen ("data.txt", "r");
    if (Fptr == NULL)
    {
        printf ("Error in the file opening.\n");
        return;
    }
    int n = 0;
    while (!feof (Fptr))
    {
        Stu newStu = addStu (n);
        n++;
    }
    printf ("Row:\t\tName:\t\tLast Name:\t\tStudent Number:\t\tMother City:\t\t\n");
    Stu * current = First;
    for (int i = 0; i < n; i++)
    {   
        printf ("%d\t\t", i);
        printf ("%s\t\t", current->name);
        printf ("%s\t\t", current->lastName);
        printf ("%s\t\t", current->stuNum);
        printf ("%s\t\t", current->cityBorn);
        current = current->next;
    }
    fclose (Fptr);
    return;
}

void search ()
{
    
}

Stu addStu (int row)
{

}

void deleteStu (int row)
{

}

void randOrd ()
{

}

void sort ()
{

}

void write ()
{

}

void end ()
{

}