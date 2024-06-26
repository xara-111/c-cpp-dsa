/*

//RECURSION - OUTPUT: 321 (TAIL RECURSION)

#include<iostream>
#include<stdio.h>

void fun1(int n)
{
    if(n>0)
    {
        printf("%d",n);
        fun1(n-1);
    }
}
int main()
{
    int x=3;
    fun1(x);
}
*/






/*
//RECURSION - OUTPUT: 123 (HEAD RECURSION)

#include<iostream>
#include<stdio.h>

void fun1(int n)
{
    if(n>0)
    {
        fun1(n-1);
        printf("%d",n);
    }
}
int main()
{
    int x=3;
    fun1(x);
}
*/






/*

//NORMAL RECURSION 

#include<stdio.h>

int fun(int n)
{
    if(n>0)
    {
        return fun(n-1)+n;
    }
    return 0;
}

int main()
{
    int a=5;
    printf("%d", fun(a));
}
*/






/*
//RECURSION USING STATIC VARIABLE X

#include<stdio.h>

int fun(int n)  //Could also be the code for finding square of a number
{
    static int x=0;
    if(n>0)
    {
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main()
{
    int a=5;
    printf("%d", fun(a));
}
*/







/*

//GLOBAL VARIABLE X

#include<stdio.h>

int x=0;
int fun(int n)
{
    if(n>0)
    {
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main()
{
    int a=5;
    printf("%d", fun(a));
}
*/







/*
//CALLING TWICE

#include<stdio.h>

int x=0;

int fun(int n)
{
    if(n>0)
    {
        x++;
        return fun(n-1)+x;
    }
    return 0;
}

int main()
{
    int a;  
    a=fun(5);            //For the first call, x increment upto 5
    printf("%d\n", a);   //DISPLAYS 25

    a=fun(5);            //For the second call, x increment from 6 upto 10.
    printf("%d\n", a);   //DISPLAYS 50
}
*/



/*

//TREE RECURSION

#include<stdio.h>

void fun(int n)
{
    if(n>0)
    {
    printf("%d ",n);
    fun(n-1);
    fun(n-1);
    }
}
int main()
{
    fun(3);

}
*/


/*
// INDIRECT RECURSION

#include<stdio.h>

void funB(int m);

void funA(int n)
{
    if(n>0)
    {
        printf("%d ",n);
        funB(n-1);
    }
}
void funB(int m)
{
    if(m>1)
    {
        printf("%d ",m);
        funA(m/2);
    }
}
int main()
{
    funA(20);
}
*/




//NESTED RECURSION

#include<stdio.h>

int fun(int n)
{
    if(n>100)
    {
        return n-10;
    }
    return fun(fun(n+11));
}
int main()
{
    int r;
    r=fun(27);
    printf("%d\n",r);
}
