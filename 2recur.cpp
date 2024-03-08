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

int fun(int n)
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