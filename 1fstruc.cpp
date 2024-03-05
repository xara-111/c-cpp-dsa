/*
//CALL BY VALUE

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

void fun(struct Rectangle r1)
{
    r1.length=20;      //Won't modify the actual parameter.
    cout<<"length"<<r1.length<<endl<<"breadth"<<r1.breadth<<endl;
}
int main()
{
    struct Rectangle r={10,5};
    fun(r);
    printf("Length %d\nBreadth %d\n",r.length, r.breadth);
    return 0;
}

//When we have variable of type structure Rectangle and passing it as parameter by call by value
// we use dot operator for accessing the members.
*/




/*
//CALL BY ADDRESS

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

void fun(struct Rectangle *ptr)
{
    ptr->length=20;      
    cout<<"length"<<ptr->length<<endl<<"breadth"<<ptr->breadth<<endl;

    //But in call by address we pass the address of Retangle as parameter and pointer of type Rectangle passed as formal parameter.
    //So it's not variable of type rectangle but pointer of type rectangle
    //So for pointer, we use arrow (->) instead of dot(.)
}
int main()
{
    struct Rectangle r={10,5};
    fun(&r);  //passing the address
    printf("Length %d\nBreadth %d\n",r.length, r.breadth);
    return 0;
}

*/






/*
//ARRAY AS MEMBER INSIDE STRUCTURE
// (Could be passed as value)
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct test
{
    int A[5];
    int n;
};

void fun(struct test t1)
{
    t1.A[0]=10;
    t1.A[1]=9;
}

int main()
{
    struct test t={{2,4,6,8,10},5};
    fun(t);
}
*/






/*
//RETURNING STRUCTURE( Objects are created by function fun but could be accessed by other function as long as pointer is available)
//Returning address of a structure 
//Create a variable of type structure on heap inside function and return it's address.
//Function return a pointer to an object created in heap that can be accessed using main also.

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

//Create an object of type Rectangle in heap using pointer.
//return pointer of type Rectangle
struct Rectangle *fun(){
    struct Rectangle *p;
    p=new Rectangle;

    //  p=(struct Rectangle *)malloc(sizeof(struct Rectangle));    (c)
    
    p->length=17;
    p->breadth=15;

    return p;
}

int main()
{
    struct Rectangle *ptr=fun();
    cout<<"Length"<<ptr->length<<endl<<"Breadth"<<ptr->breadth<<endl;
}
*/