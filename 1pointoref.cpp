/*

#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    Rectangle r={10,5};   // No need to write struct in c++ again once declared but in c you have to.
    cout<<r.length<<endl;
    cout<<r.breadth<<endl;  // When you have a normal variable you access using dot operator

    Rectangle *p=&r;        //Pointer p pointing at r and storing address of r

    cout<<p->length<<endl;  //Pointer variable accesed using arrow ->
    cout<<p->breadth<<endl;

}
*/



#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    Rectangle *p;   //Declare pointer

    p=(struct Rectangle *)malloc(sizeof(struct Rectangle));   // In c, creating an object of Rectangle in heap.
    p=new Rectangle;   //c++ 

    p->length=15;  //changing value of length and breadth
    p->breadth=7;

    cout<<p->length<<endl;
    cout<<p->breadth<<endl;   //Accessing the heap memory using pointer to structure
}

