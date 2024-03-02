#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

int main()
{
    int a=10;
    int &r=a;
    r=25;     //Both a and r becomes 25
//Reference doesn't consume memory, it uses the same memory as a.

    int b=30;
    r=b;   //Both a and r becomrs 30

    cout<<r<<endl;
    cout<<a<<endl;
}