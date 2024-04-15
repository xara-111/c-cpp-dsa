#include<stdio.h>
#include<stdlib.h>

struct Stack
{
    int size;
    int top;
    int *S;
};

void create(struct Stack *st)
{
    printf("Enter size: ");
    scanf("%d",&st->size);
    st->top=-1;
    st->S=(int *)malloc(st->size * sizeof(int));
}

void Display(struct Stack st)
{
    int i;
    for(i=st.top; i>=0; i--)
    {
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, int x)
{
    if(st->top==st->size-1)
         printf("Stack Overflow\n");
    else
    {
        st->top++;
        st->S[st->top]=x;
    }
}

int pop(struct Stack *st)
{
    int x=-1;
    if(st->top==-1)
         printf("Stack Underflow\n");
    else
    {
        x=st->S[st->top--];
    }
    return x;
}

int peek(struct Stack st, int index)
{
    int x=-1;
    if(st.top-index+1 <0)
          printf("Invalid position\n");
    else
    {
        x=st.S[st.top-index+1];
    }
    return x;
}


int isEmpty(struct Stack st)
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

int stackTop(struct Stack st)
{
    if(!isEmpty(st))   //if not empty
           return st.S[st.top];
    return -1;
}
int main()
{
    
    struct Stack st;
    create(&st);
    push(&st,10);
    push(&st,20);
    push(&st,30);

    // printf("%d \n",pop(&st));
    printf("%d \n",peek(st,3));
    Display(st);

    //TRY MENU DRIVEN PROGRAM
}