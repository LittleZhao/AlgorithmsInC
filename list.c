#include <stdio.h>
#include <stdlib.h>
typedef struct node* link;
struct node
{
    /* data */
    int item;
    link next;
};
void creat_list(int, link);
void delete_item(int, link);
void print_list(link);

int main(void)
{
    int length;
    int i = 0;

    printf("The length of the list is-> ");
    scanf("%d", &length);
    link t = (link)malloc(sizeof(*t));
    t->next = NULL;

    creat_list(length, t);
    print_list(t->next);
    printf("Which one do you want to delete-> ");
    scanf("%d", &length);
    delete_item(length, t->next);
 return 0;
}

void creat_list(int length, link head)
{
    int i = 1;
    link t = head;
    for (; i <= length; i++)
    {
       t->next = (link)malloc(sizeof(*t));
       t->next->item = i;
       t->next->next = NULL;
       t = t->next;
   }
   return;

}

void print_list(link t)
{
    if (t != NULL)
    {
        printf("%d ", t->item);
        print_list(t->next);
    }
    else
    {
        return;
    }
    return;

}

void delete_item(int p, link t)
{
    if (p == t->item)
    {

    }

}