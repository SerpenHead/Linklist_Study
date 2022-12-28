#include <stdio.h>
#include <stdlib.h>
#define FLASE 0
#define TRUE 1
typedef struct Node
{
    int date;
    struct Node *next;
} Node;
Node *initList()
{
    Node *list = (Node *)malloc(sizeof(Node));
    list->date = 0;
    list->next = list;
    return list;
}
void headInsert(Node *list, int date)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->date = date;
    node->next = list->next;
    list->next = node;
    list->date++;
}
void printList(Node *list)
{
    Node *node = list->next;
    while (node != list)
    {
        printf("%d->", node->date);
        node = node->next;
    }
    printf("NULL\n");
}
void tailInsert(Node *list, int date)
{
    Node *node = (Node *)malloc(sizeof(Node));
    Node *pre = list;
    while (pre->next != list)
    {
        pre = pre->next;
    }
    node->date = date;
    node->next = list;
    pre->next = node;
    list->date++;
}
int delete(Node* list, int date)
{
    Node* pre = list;
    Node* current = list->next;
    while(current != list)
    {
        if(current->date == date)
        {
            //carry out operation delete
            pre->next = current->next;
            free(current);
            list->date--;
            return TRUE;
        }
        pre = current;
        current = current->next;
    }
    return FLASE;
}
int main()
{
    Node *list = initList();
    headInsert(list, 1);
    headInsert(list, 2);
    headInsert(list, 3);
    headInsert(list, 4);
    headInsert(list, 5);
    tailInsert(list, 6);
    tailInsert(list, 7);
    tailInsert(list, 8);
    tailInsert(list, 9);
    tailInsert(list, 10);
    delete(list,6);
    printList(list);
    return 0;
}