#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    char x;
}r1;              //Declaring a variable of the structure could be written like this, here.(Gloabal variable)
//If you have more varible, declare all of them here like r1,r2,r3;

// struct Rectangle r1;  //Declaring a variable of the structure outside main can be done. (Global variable)

int main()
{
    //struct Rectangle r1;   //Declaring a variable of the structure inside main.(Local variable to main)

    struct Rectangle r1={10,5}; //Initialization

    r1.length=15;    //Changing values
    r1.breadth=7;

    cout<<"Length="<<r1.length<<endl;     //Members of structure can be accessed using .(dot) operator
    cout<<"Breadth="<<r1.breadth<<endl;

    printf("size= %lu\n", sizeof(r1));  //Long unsigned datatype (displays 12)
    

 
/*
Notes:-

Since there is 2 int and one char int the structure, no. of bytes should be 9 but sizeof is displaying 12.

Because it's easy for our machine to read 4,4 bytes at a time.

So for length , breadth its taking 4 bytes.

But for character also it's allocating 4 bytes but it will be using only 1 byte out of it.

At a time, it'll pick up 4 bytes but use only 1 byte

Same as we buy a strip of medicine but eat only 1.

This makes accesibility easy.

If you take float then it will take greater no. of bytes, depends on size of the data type.

So for character instead of taking 1 byte it will take the nearest bigger size (ie. integer).

So this adjustment in the memory is called PADDING.

Inside structures padding is done, means it'll take extra memory so that it's easy for our processor to read the structure at once.
*/


}