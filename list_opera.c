#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
    int date;
    struct Node* next;
}Node;
Node* initList()
{
    Node*list=(Node*)malloc(sizeof(Node));
    list -> date = 0;
    list -> next = NULL;
    return list;
}
void headInsert(Node*list,int date)
{
    Node*node=(Node*)malloc((sizeof(Node)));
    node -> date = date;
    node -> next = list->next;
    list -> next = node;
    list->date++;
}
void tailInsert(Node*list,int date)
{
    Node*head=list;
    Node*node=(Node*)malloc(sizeof(Node));
    node->date=date;
    node->next=NULL;
    list=list->next;
    while(list->next)
    {
        list=list->next;
    }
    list->next=node;
    head->date++;
}
void delet(Node*list,int date)
{
    Node*pre=list;
    Node*current=list;
    current=current->next;
    while(current)
    {
        if(current->date==date)
        {
            pre->next=current->next;
            free(current);
            break;
        }
        pre=current;
        current=current->next;
    }
    list->date--;

}
void printList(Node*list)
{
    list=list->next;
    while(list)
    {
        printf("%d ",list->date);
        list=list->next;
    }
    printf("%n");
    
}
int main()
{
    Node*list=initList();
    headInsert(list,1);
    headInsert(list,2);
    headInsert(list,3);
    headInsert(list,4);
    headInsert(list,5);
    tailInsert(list,6);
    tailInsert(list,7);
    tailInsert(list,8);
    tailInsert(list,9);
    tailInsert(list,10);
    delet(list,10);
    printList(list);
    return 0;
    

}