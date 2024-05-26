#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Stack
{
    int size;
    int top;
    int *S;
};


void Display(struct Stack st)
{
    int i;
    for(i=st.top; i>=0; i--)
    {
        printf("%d ",st.S[i]);
    }
    printf("\n");
}

void push(struct Stack *st, char x)
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


int isBalanced(char *exp)
{
    struct Stack st;
    st.size=strlen(exp);
    st.top=-1;
    st.S=(int *)malloc(st.size*sizeof(int));

    for(int i=0; exp[i]!='\0'; i++)
    {
        if(exp[i]=='(')
           push(&st, exp[i]);
        else if(exp[i]==')')
        {
            if(isEmpty(st))
               return 0;
            pop(&st);
        }
    }
    if(isEmpty(st))
           return 1;
    return 0;
}
int main()
{
    
    struct Stack st;
    char *exp=(char *)"((a+b)*(c-d))";

    //create(&st,exp);
    
    
    printf("%d\n",isBalanced(exp));
}