#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL;  //Declaring a pointer here, it becomes a global pointer, it can be directly accessed or pass it as parameter.

void create(int A[], int n)
{
    int i;
    struct Node *t, *last;  
    //t=temporary pointer, helps creating new node
    //last=points on last node, and helps to add a new node at the end of link list
    first=(struct Node *)malloc(sizeof(struct Node));
    first->data=A[0];  //Giving it the first element
    first->next=NULL;  //Since it's the first node, there's nothing beyond this one so null
    last=first;       //Making last point at first

    for(i=1; i<n; i++)
    {
        t=(struct Node *)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}

void Display(struct Node *p)
{
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
}
int main()
{
    int A[]={3, 5, 7, 10, 15}; //create link list using these elements
    create(A,5);
    Display(first);
}