#include<stdio.h>
#include<stdlib.h>

struct Node //Tree node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue  //This queue is going to store addresses of tree nodes,not int type data
{
    int size;
    int front;
    int rear;
    Node **Q;  //(Node *)For pointer of type node , (*Q)For array
};

void create(struct Queue *q, int size)
{
    q->size=size;
    q->front=q->rear=-1;
    q->Q=(Node **)malloc(q->size*sizeof(Node *));  //When creating an array, it's not int type pointer but node type pointer to a pointer.
}

void enqueue(struct Queue *q, Node * x)
{
    if(q->rear==q->size-1)
       printf("Queue is full\n");
    else
    {
        q->rear++;
        q->Q[q->rear]=x;
    }
}

Node* dequeue(struct Queue *q)
{
    Node* x=NULL;
    if(q->front==q->rear)
         printf("Queue is Empty\n");
    else
    {
        q->front++;
        x=q->Q[q->front];
    }
    return x;  
}

int isEmpty(struct Queue q)
{
    return q.front==q.rear;
}






struct Stack
{
    int size;
    int top;
    struct Node **S;
};

void stackcreate(struct Stack *st, int size)
{
    //printf("Enter size: ");
    //scanf("%d",&st->size);
    st->size=size;
    st->top=-1;
    st->S=(struct Node **)malloc(st->size * sizeof(struct Node *));
}


void push(struct Stack *st, Node *x)
{
    if(st->top==st->size-1)
         printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

struct Node *pop(struct Stack *st)
{
    struct Node *x=NULL;
    if(st->top==-1)
         printf("Stack Underflow\n");
    else
    {
        x=st->S[st->top--];
    }
    return x;
}

int isEmptystack(struct Stack st)
{
    if(st.top==-1)
          return 1;
    else
          return 0;
}

int isFull(struct Stack st)
{
    if(st.top==st.size-1)
            return 1;
    else
            return 0;
}

// int stackTop(struct Stack st)
// {
//     if(!isEmptystack(st))   //if not empty
//            return st.S[st.top];
//     return -1;
// }

int i;
struct Node *root=NULL;

void Treecreate()
{
    struct Node *p, *t;
    int x;
    struct Queue q;
    create(&q,100); //create queue of size 100
    printf("Enter root value: ");
    scanf("%d",&x);
    root=(struct Node *)malloc(sizeof(struct Node));  //create a root node
    root->data=x;
    root->lchild=root->rchild=NULL;
    enqueue(&q,root);
    
    while(!isEmpty(q))
    {
        p=dequeue(&q);
        printf("Enter left child of %d: ",p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->lchild=t;
            enqueue(&q,t);
        }
        printf("Enter right child of %d: ",p->data);
        scanf("%d", &x);
        if(x!=-1)
        {
            t=(struct Node *)malloc(sizeof(struct Node));
            t->data=x;
            t->lchild=t->rchild=NULL;
            p->rchild=t;
            enqueue(&q,t);
        }
    }
}

void preorder(struct Node *p)
{
    if(p)
    {
        printf("%d ",p->data);
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void inorder(struct Node *p)
{
    if(p)
    {
        inorder(p->lchild);
        printf("%d ",p->data);
        inorder(p->rchild);
    }
}

void postorder(struct Node *p)
{
    if(p)
    {
        postorder(p->lchild);
        postorder(p->rchild);
        printf("%d ",p->data);
    }
}

void Ipreorder(struct Node *p)
{
    struct Stack stk;
    stackcreate(&stk,100);
    while(p||!isEmptystack(stk))
    {
        if(p)
        {
            printf("%d ",p->data);
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            p=p->rchild;
        }
    }

}


void Iinorder(struct Node *p)
{
    struct Stack stk;
    stackcreate(&stk,100);
    while(p||!isEmptystack(stk))
    {
        if(p)
        {
            
            push(&stk,p);
            p=p->lchild;
        }
        else
        {
            p=pop(&stk);
            printf("%d ",p->data);
            p=p->rchild;
        }
    }

}

void Levelorder(struct Node *root)
{
    struct Queue q;
    create(&q,100);
    printf("%d ",root->data);
    enqueue(&q,root);

    while(!isEmpty(q))
    {
        root=dequeue(&q);
        if(root->lchild)
        {
            printf("%d ",root->lchild->data);
            enqueue(&q,root->lchild);
        }
        if(root->rchild)
        {
            printf("%d ",root->rchild->data);
            enqueue(&q,root->rchild);
        }
    }
}

int count(struct Node *root)
{
    if(root)
        return count(root->lchild)+count(root->rchild)+1;
    return 0;
}

int height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
         return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)
        return x+1;
    else
        return y+1;
}

int main()
{
    Treecreate();
    printf("preorder:\n");
    preorder(root);
    printf("\n Iterative preorder:\n");
    Ipreorder(root);
    printf("\n inorder:");
    inorder(root);
    printf("\n Iterative inorder:\n");
    Iinorder(root);
    printf("\n postorder:\n");
    postorder(root);
    printf("\n Level order:\n");
    Levelorder(root);

    printf("Count: %d , Height:%d ",count(root),height(root));

    
}