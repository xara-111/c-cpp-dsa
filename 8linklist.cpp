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
    printf("\n");
}

void Rdisplay(struct Node *p)
{
    if(p!=NULL)
    {
        printf("%d ",p->data);
        Rdisplay(p->next);
    }
}


void Rrevdisplay(struct Node *p)
{
    if(p!=NULL)
    {
        Rrevdisplay(p->next);
        printf("%d ",p->data);
    }
   
}


int count(struct Node *p)
{
    int c=0;
    while(p!=0)
    {
        c++;
        p=p->next;
    }
    return c;
}

int Rcount(struct Node *p)
{
    if(p==0)
        return 0;
    return count(p->next)+1;
}

int add(struct Node *p)
{
    int sum=0;
    while(p)
    {
        sum=sum+p->data;
        p=p->next;
    }
    return sum;
}

int Radd(struct Node *p)
{
    if(p==0)
        return 0;
    return Radd(p->next)+p->data;
}

int max(struct Node *p)
{
    int m=INT32_MIN;
    while(p)
    {
        if(p->data>m)
               m=p->data;
        p=p->next;
    }
    return m;
}

int Rmax(struct Node *p)
{
    int x=0;
    if(p==0)
         return INT32_MIN;
    else
         x=Rmax(p->next);
         if(x>p->data)
            return x;
        else
            return p->data;
}

int RTmax(struct Node *p)
{
    int x=0;
    if(p==0)
         return INT32_MIN;
    else
         x=RTmax(p->next);
         if(x>p->data)
            return x;
        else
            return p->data;
}

Node * search(struct Node *p, int key)
{
    while(p!=0)
    {
        if(key==p->data)
             return p;
        p=p->next;
    }
    return NULL;
}

Node * Rsearch(struct Node *p, int key)
{
    if(p==0)
        return 0;
    if(key==p->data)
        return p;
    return Rsearch(p->next, key);
}

Node * Search(struct Node *p, int key)  //Move to head operation used to search
{
    Node *q=NULL;
    while(p!=NULL)
    {
        if(key==p->data)
        {
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
    
}

void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if(index<0 || index>count(p))
            return;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;

    if(index==0)
    {
        t->next=first;
        first=t;
    }
    else
    {
        for(int i=0;i< index-1; i++)
        {
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }
}

int main()
{
    int A[]={3, 5, 7, 10, 15}; //create link list using these elements
    create(A,5);
    Display(first);
    Rdisplay(first);
    Rrevdisplay(first);
    printf("Length is %d\n ",count(first));
    printf("Length is %d\n ",Rcount(first));
    printf("Sum is %d\n",add(first));
    printf("Sum is %d\n",Radd(first));
    printf("Maximum is %d\n",max(first));
    printf("Maximum is %d\n",Rmax(first));
    printf("Maximum is %d\n",RTmax(first));

    printf("Key is at %p\n",search(first, 10));
    
    struct Node *temp;
    temp=Search(first,7);  //Replace different search funtions
    temp=Search(first,10); //Could be searched faster the 2nd time at constant time 
    if(temp)
    {
        printf("Key is found %d\n",temp->data);
    }
    else
    {
        printf("Key not found\n");
    }

    Display(first); //Notice the key move to front as first node

    Insert(first,3,2);  //We can call insert function multiple time for creating the whole link list
    Display(first);
    

}