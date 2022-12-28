#include<stdio.h>
#include<stdlib.h>
#define True 1
#define Flase 0
typedef struct Node
{
    struct Node* pre;
    struct Node* next;
    int date;
}Node;
Node* initList()
{
    Node* list = (Node*)malloc(sizeof(Node));
    list->pre = list;
    list->next = list;
    list->date = 0;
    return list;
}
void headInsert(Node* list,int date)
{
    Node* node = (Node*)malloc(sizeof(Node));
    Node* head = list;
    if(head->next != list)
    {
        node->next = head->next;
        node->pre = head;
        head->next->pre = node;
        head->next = node;
    }
    else
    {
        head->next = node;
        head->pre = node;
        node->next = head;
        node->pre = head;
    }
    node->date = date;
    list->date++;
}
void tailInsert(Node* list,int date)
{
    Node* node = (Node*)malloc(sizeof(Node));
    list->pre->next = node;
    node->pre = list->pre;
    node->next = list;
    list->pre = node;
    node->date = date;
    list->date++;
}
int delete(Node* list,int date)
{
    Node* current = list->next;
    while(current != list)
    {
        if(current->date == date)
        {
            current->pre->next = current->next;
            current->next->pre = current->pre;
            free(current);
            list->date--;
            return 1;
        }
        current = current->next;
    }
    return 0;
}
void printlist(Node* list)
{
    Node* head = list->next;
    while(head != list)
    {
        printf("%d->",head->date);
        head = head->next;
    }
    printf("Null");
}
void invertPrintlist(Node* list)
{
    Node* head = list->pre;
    while(head != list)
    {
        printf("%d->",head->date);
        head = head->pre;
    }
    printf("Null");
    
}
int main()
{
    Node* list = initList();
    headInsert(list,1);
    tailInsert(list,2);
    tailInsert(list,3);
     tailInsert(list,4);
    delete(list,3);
    printlist(list);
    printf("\n");
    invertPrintlist(list);
    return 0 ;
}