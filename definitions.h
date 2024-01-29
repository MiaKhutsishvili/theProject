// Definitions

struct stu
{
    char name[20];
    char lastName[20];
    char ID[20];
    char city[20];
    struct stu * next;
    struct stu * prev;
};
typedef struct stu Stu;

extern Stu * first;
extern Stu * head;
extern int cnt;
