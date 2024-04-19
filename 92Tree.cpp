#include<stdio.h>
#include<stdlib.h>
 
struct node
{
struct node *leftchild;
int data;
struct node *rightchild;
}*root=NULL;
 
struct queue
{
int size;
int front;
int rear;
struct node **Q;
};
 
void create(struct queue*p)
{
p->size=100;
p->rear=0;
p->front=0;
p->Q=(struct node**)malloc(p->size* sizeof(struct node*));
}
 
void enqueue(struct queue *p,struct node *x)
{
if((p->rear+1)%p->size==p->front)
{
printf("stack is full");
}
else
{
p->rear=(p->rear+1)%p->size;
p->Q[p->rear]=x;
}
}
 
struct node* dequeue(struct queue *p)
{
struct node* x=NULL;
if(p->rear==p->front)
{
printf("nothing to delete");
}
else
{
p->front=(p->front+1)%p->size;
x=p->Q[p->front];
 
}
return x;
}
 
int isempty(struct queue *p)
{
return p->front==p->rear;// condition was wrong
}
 
 
void treecreate()
{
int x;
struct node *p,*t;
struct queue q;
create(&q);
 
printf("eneter root value");
scanf("%d",&x);// no space after %d
root=(struct node*)malloc(sizeof(struct node));
root->data=x;
root->leftchild=NULL;
root->rightchild=NULL;
enqueue(&q,root);
 
while(!isempty(&q))
{
p=dequeue(&q);
 
printf("left_child to %d:",p->data);
scanf("%d",&x);
if(x!=-1)
{
t=(struct node*)malloc(sizeof(struct node));
t->data=x;
t->leftchild=NULL;
t->rightchild=NULL;
p->leftchild=t;
enqueue(&q,t);
}
 
printf("right_child to %d:",p->data);
scanf("%d",&x);
if(x!=-1)
{
t=(struct node*)malloc(sizeof(struct node));
t->data=x;
t->leftchild=NULL;
t->rightchild=NULL;
p->rightchild=t;
enqueue(&q,t);
}
}
 
 
}

void preorder1(struct node *p)
{
if(p)
{
printf("%d ,",p->data);
preorder1(p->leftchild);
preorder1(p->rightchild);
}
}



void inorder1(struct node *p)
{
if(p)
{

inorder1(p->leftchild);
printf("%d ,",p->data);
inorder1(p->rightchild);
}
}

void postorder1(struct node *p)
{
if(p)
{

postorder1(p->leftchild);
postorder1(p->rightchild);
printf("%d ,",p->data);
}
}


int main()
{
 
treecreate();
preorder1(root);
printf("Postorder:\n");
postorder1(root);
return 0;
}