#include<stdio.h>
#include<stdlib.h>
#define True 1
#define Flase 2
typedef struct Node
{
    struct Node* pre;
    struct Node* next;
    int date;
}Node;
Node* initList()
{
    Node* L = (Node*)malloc(sizeof(Node));
    L->date = 0;
    L->pre = NULL;
    L->next = NULL;
    return L;
}
void headInsert(Node* list,int date)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->next = list->next;
    list->next->pre = node;
    list->next = node;
    node->pre = list;
    node->date = date;
    list->date++;
}
void tailInsert(Node* list,int date)
{
    Node* node = (Node*)malloc(sizeof(Node));
    list->date++;
    node->next = NULL;
    while(list->next)
    {
        list = list->next;
    }
    list->next = node;
    node->pre = list;
    node->date = date;
}
int delete(Node* list,int date)
{
    Node* head = list;
    list = list->next;
    while(list)
    {
        if(list->date = date)
        {
            head->date--;
            list->pre->next = list->next;
            list->next->pre = list->pre;
            free(list);
            return True;
        }
    }
    return Flase;
}
void printList(Node* list)
{
    list = list->next;
    while(list)
    {
        printf("%d->",list->date);
        list = list->next;
    }
    printf("NULL");
}
void invertPrintList(Node* list)
{
    while(list->next)
    {
        list = list->next;
    }
    while(list->pre)
    {
        printf("%d->",list->date);
        list = list->pre;
    }
    printf("Null");
}
int main()
{
    Node*list = initList();
    tailInsert(list,1);
    headInsert(list,2);
    headInsert(list,3);
    delete(list,3);
    printList(list);
    invertPrintList(list);
    return 0 ;
}