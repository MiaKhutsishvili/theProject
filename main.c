#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

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
int numOfStu;

// Menu
void read (); // 1
void search (char *); // 2
void addStu (int); // 3
void deleteStu (int); // 4
void randOrd (); // 5
void sort (); // 6
void write (); // 7
void end (); // 8

void stuPrint (Stu *);

int main()
{
    int input;
    while (true)
    {
        //scanf ("%d", &input);
        switch (input)
        {
            case 1:
                read();
                break;

            case 2:
                char stu[20];
                printf ("Please enter the student's number: ");
                scanf ("%s", stu);
                search (stu);
                break;
            case 3:
                int row;
                printf ("Enter the row: ");
                scanf ("%d", &row);
                addStu (row--);
                read ();
                break;
        }
    }
    return 0;
}

void stuPrint (Stu * stu)
{
    printf ("%s\t\t", stu->name);
    printf ("%s\t\t", stu->lastName);
    printf ("%s\t\t", stu->stuNum);
    printf ("%s\t\t", stu->cityBorn);
    printf ("\n");
    return;
}

void read ()
{
    FILE * Fptr = fopen ("data.txt", "r");
    if (Fptr == NULL)
    {
        printf ("Error in the file opening.\n");
        return;
    }
    if (!checkIfReadIsDone)
    {
        int n = 0;
        while (!feof (Fptr))
        {
            addStu (n);
            n++;
        }
        numOfStu = n;
        checkIfReadIsDone = 1;
    }
    printf ("Row:\t\tName:\t\tLast Name:\t\tStudent Number:\t\tMother City:\t\t\n");
    Stu * current = First;
    for (int i = 0; i < numOfStu; i++)
    {   
        printf ("%d\t\t", i + 1);
        stuPrint (current);
        current = current->next;
    }
    fclose (Fptr);
    return;
}

void search (char * num)
{
    Stu * current = First;
    int i = 0;
    do 
    {
        i++;
        if (!strcmp (current->stuNum, num))
            break;
    }
    while (current->next != NULL);
    printf ("%d\t\t", i);
    stuPrint (current);
    return;
}

void addStu (int row)
{
    Stu * current = First;
    int i = 0; 
    while (i < row && current->next != NULL)
    {
        current = current->next;
        i++;
    }
    Stu * newStu = (Stu *) malloc (sizeof (Stu));
    printf ("Enter name: "); scanf ("%s", newStu->name);
    printf ("Enter last name: "); scanf ("%s", newStu->lastName);
    printf ("Enter student's number: "); scanf ("%s", newStu->stuNum);
    printf ("Enter mother city: "); scanf ("%s", newStu->cityBorn);
    if (row < 1)
    {
        newStu->next = current;
        current->prev = newStu;
        newStu->prev = NULL;
        return;
    }
    newStu->next = current->next;
    newStu->prev = current;
    if (current->next != NULL)
        current->next->prev = newStu;
    current->next = newStu;
    write (newStu);
    return;
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