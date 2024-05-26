#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*first=NULL, *second=NULL, *third=NULL;  //Declaring a pointer here, it becomes a global pointer, it can be directly accessed or pass it as parameter.

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

void create2(int A[], int n)
{
    int i;
    struct Node *t, *last;  
    second=(struct Node *)malloc(sizeof(struct Node));
    second->data=A[0];  //Giving it the first element
    second->next=NULL;  //Since it's the first node, there's nothing beyond this one so null
    last=second;       //Making last point at first

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
    return Rcount(p->next)+1;
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


void Sortedinsert(struct Node *p, int x)
{
    struct Node *t, *q=NULL;
    t=(struct Node *)malloc(sizeof(struct Node));
    t->data=x;
    t->next=NULL;

//Is the first node created yet? If it's the first node, pointer first would be null
//Initially if there's no node at all, t should be the first node
    if(first==NULL)  //If the first node doesnt exist, make first point on t.
        first=t;
    else
    {
        while(p && p->data<x)
        {
            q=p;
            p=p->next;
        }
        //The place where we've stopped is it the first node?If it's first node, new node will be inserted on left hand side
        //If the element we're inserting is smallest then it'll come before the first node.
        //So if p is staying upon first node only we've to insert new node before first node
        if(p==first)
        {
            t->next=first;
            first=t;
        }
        else
        {
            t->next=q->next;
            q->next=t;
        }
    }
}

int Delete(struct Node *p, int index)
{
    Node *q;
    int x=-1;
    int i;

    if(index <1 || index > count(p))
          return -1;
    if(index==1)
    {
        //p=first;
        x=first->data;
        first=first->next;
        free(p);
        return x;
    }
    else
    {
        //p=first;
        q=NULL;
        for(i=0; i<index-1 && p; i++)
        {
            q=p;
            p=p->next;
        }
        if(p)
        {
            q->next=p->next;
            x=p->data;
            free(p);
        }
    }
    return x;
}

int isSorted(struct Node *p)
{
    int x=INT32_MIN;
    while(p!=NULL)
    {
        if(p->data <x)
            return false;
        x=p->data;
        p=p->next;
    }
    return true;
}


void Duplicate(struct Node *p)
{
    
    Node *q=first->next;
    while(q!=NULL)
    {
        if(p->data!=q->data)
        {
            p=q;
            q=q->next;
        }
        else
        {
            p->next=q->next;
            free(q);
            q=p->next;
        }
    }
}

void Reverse(struct Node *p)
{
    int *A;
    struct Node *q=p;
    int i=0;
    A=(int *)malloc(sizeof(int)*count(p));
    while(q!=NULL)
    {
        A[i]=q->data;
        q=q->next;
        i++;
    }
    q=p;
    i--;
    while(q!=0)
    {
        q->data=A[i];
        q=q->next;
        i--;
    }
}

void linkRev(struct Node *p)
{
    Node *q=NULL;
    Node *r=NULL;
    while(p!=NULL)
    {
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;

}

void Rrev(struct Node *q, struct Node *p)
{
    if(p!=NULL)
    {
        Rrev(p,p->next);
        p->next=q;
    }
    else
    {
        first=q;
    }
}


void concat(struct Node *p, struct Node *q)
{
    third=p; //pointer third point on first
    while(p->next!=NULL)
    {
        p=p->next;
    }
    p->next=q;
    //second=NULL;
}

void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if(p->data <q->data)
    {
        third=last=p;
        p=p->next;
        last->next=NULL;
    }
    else
    {
        third=last=q;
        q=q->next;
        last->next=NULL;
    }

    while(p && q)
    {
        if(p->data <q->data)
        {
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else
        {
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p)
    {
        last->next=p;
    }
    else
    {
        last->next=q;
    }
}

int isLoop(struct Node *f)
{
    struct Node *p, *q;
    p=q=f;
    do
    {
        p=p->next;
        q=q->next;
        q=q?q->next:q;
    } while (p && q && p!=q);

    if(p==q)
        return 1;
    else
        return 0;
    
}


int main()
{

    //struct Node *t1, *t2; //(Required for isLoop)
   

    int A[]={10, 20, 30, 40, 50}; //create link list using these elements
    int B[]={5, 15, 25, 35, 45};
    create(A,5);
    create2(B,5);

    printf("First\n");
    Display(first);
    printf("\n\n");
    printf("Second\n");
    Display(second);


    // Display(first);
    // Rdisplay(first);
    // Rrevdisplay(first);
    // printf("Length is %d\n ",count(first));
    // printf("Length is %d\n ",Rcount(first));
    // printf("Sum is %d\n",add(first));
    // printf("Sum is %d\n",Radd(first));
    // printf("Maximum is %d\n",max(first));
    // printf("Maximum is %d\n",Rmax(first));
    // printf("Maximum is %d\n",RTmax(first));

    // printf("Key is at %p\n",search(first, 10));
    
    // struct Node *temp;
    // temp=Search(first,7);  //Replace different search funtions
    // temp=Search(first,10); //Could be searched faster the 2nd time at constant time 
    // if(temp)
    // {
    //     printf("Key is found %d\n",temp->data);
    // }
    // else
    // {
    //     printf("Key not found\n");
    // }

    // Display(first); //Notice the key move to front as first node



    // Insert(first,3,2);  //We can call insert function multiple time for creating the whole link list
    // Display(first);

    // Sortedinsert(first,11);
    // printf("\n\n");
    // Display(first);


    // printf("Deleted Element is %d\n",Delete(first,1));
    // Display(first);

    // if(isSorted(first))
    // {
    //     printf("Sorted\n");
    // }
    // else
    // {
    //     printf("Not sorted\n");
    // }

    // Duplicate(first);
    // Display(first);


    // Reverse(first);
    // linkRev(first);
    // Rrev(NULL,first);
    // Display(first);

    // concat(first,second);
    // printf("Concatinated\n");
    // Display(third);

    // merge(first,second);
    // printf("Merged\n");
    // Display(third);




//Actually making a loop in linked list(Steps to form a loop)
    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;

    // if(isLoop(first))
    // {
    //     printf("Loop\n");
    // }
    // else
    // {
    //     printf("No loop\n");
    // }

}