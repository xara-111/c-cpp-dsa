#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*top=NULL;  //Global variable, it could even be declared inside main function and passed as parameters.
//If you have one stack in the program go for variable method.
//But it's not prefferable , we should have a pointer inside main function.
//If i'm not taking top as global variable then all these functions will take 'struct stack st' as parameter.
void push(int x)
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
         printf("Stack is full\n");
    else
    {
        t->data=x;
        t->next=top;
        top=t;
    }
}

int pop()
{
    struct Node *t;
    int x=-1;
    if(top==NULL)
        printf("Stack is Empty\n");
    else
    {
        t=top;
        top=top->next;
        x=t->data;
        free(t);
    }
    return x;
}


void Display()
{
    struct Node *p;
    p=top;
    while(p!=NULL)
    {
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int peek (int index)
{
    struct Node *p;
    int x=-1;
    p=top;
    for(int i=0; p!=NULL && i<index-1; i++)
    {
        p=p->next;
    }
    if(p!=NULL)
       return p->data;
    return -1;
}

int stacktop()
{
    if(top)
       return top->data;
    return -1;
}

int isempty()
{
    if(top==NULL)
       return 1;
    return 0;
}

int isfull()
{
    struct Node *t;
    t=(struct Node *)malloc(sizeof(struct Node));
    if(t==NULL)
        return 1;
    return 0;
}
int main()
{
    push(10);
    push(20);
    push(30);

    Display();
    printf("%d\n ",pop());

    printf("%d\n ",peek(1));

    printf("%d", stacktop());
    
}