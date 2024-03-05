/*

// MONOLITHIC STYLE OF PROGRAMMING

#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
    int length=0, breadth=0;
    //It's a good practice to initialize a variable when you declare it to avoid any problem.

    printf("Enter length and breadth: ");
    cin>>length>>breadth;

    int area=length*breadth;
    int peri=2*(length+breadth);

    printf("Area = %d and Perimeter = %d",area, peri);
    return 0;
}
*/





/*

//MODULAR/PROCEDULAR STYLE OF PROGRAMMING
// (processing in a separate func. and let the user interaction be done by main itself) 


#include<iostream>
#include<stdio.h>
using namespace std;

int area(int length, int breadth)
{
    return length*breadth;
}

int perimeter(int length, int breadth)
{
    int p;
    p=2*(length+breadth);
    return p;
}

int main()
{
    int length=0;
    int breadth=0;
    printf("Enter length and breadth: ");
    cin>>length>>breadth;

    int a=area(length,breadth);
    int peri=perimeter(length, breadth);

    printf("Area = %d and Perimeter = %d",a, peri);
    return 0;
}
*/





/*

// COMBINING AREA AND PERIMETER INTO STRUCT

#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

int area(struct Rectangle r)
{
    return r.length*r.breadth;
}

int perimeter(Rectangle r)     //c++ format: struct not necessary
{
    int p;
    p=2*(r.length+r.breadth);
    return p;
}

int main()
{
    Rectangle r={0,0};

    int length=0;
    int breadth=0;
    printf("Enter length and breadth: ");
    cin>>r.length>>r.breadth;

    int a=area(r);
    int peri=perimeter(r);

    printf("Area = %d and Perimeter = %d",a, peri);
    return 0;
}
*/




/*
//INITIALIZING THE VARIABLES(LENGTH AND BREADTH) USING FUNCTION 'INITIALIZE'

#include<iostream>
#include<stdio.h>
using namespace std;

struct Rectangle 
{
    int length;
    int breadth;
};

int area(struct Rectangle r)
{
    return r.length*r.breadth;
}

int perimeter(Rectangle r)     //c++ format: struct not necessary
{
    int p;
    p=2*(r.length+r.breadth);
    return p;
}


void initialize(struct Rectangle *r,int l, int b)
{
    r->length=l;
    r->breadth=b;
}

int main()
{
    Rectangle r={0,0};

    int l,b;
    printf("Enter length and breadth: ");
    cin>>l>>b;

    initialize(&r,l,b);

    int a=area(r);
    int peri=perimeter(r);

    printf("Area = %d and Perimeter = %d",a, peri);
    return 0;
}
*/





/*
//CREATING CLASS COMBINING ALL THE FUNCTIONS

#include<iostream>
#include<stdio.h>
using namespace std;

class Rectangle      // class and struct can be interchangably replaced, no need for private and public in struct.
{
    private:
    int length;
    int breadth;

public:
void initialize(int l, int b)
{

    length=l;
    breadth=b;
}


int area()
{
    return length*breadth;
}

int perimeter()     
{
    int p;
    p=2*(length+breadth);
    return p;
}

};


int main()
{
    Rectangle r;       //Direct initialization can't be done in class

    int l,b;
    printf("Enter length and breadth: ");
    cin>>l>>b;

    r.initialize(l,b);

    int a=r.area();
    int peri=r.perimeter();

    printf("Area = %d and Perimeter = %d",a, peri);
    return 0;
}
*/




/*

//CONSTRUCTOR (DECLARATION AND INITIALIZATION TOGETHER OF A CLASS)

#include<iostream>
#include<stdio.h>
using namespace std;

class Rectangle      
{
    private:
    int length;
    int breadth;

public:


Rectangle(int l, int b)
{
    length=l;
    breadth=b;
}


int area()
{
    return length*breadth;
}

int perimeter()     
{
    int p;
    p=2*(length+breadth);
    return p;
}

};

int main()
{

    int l,b;
    printf("Enter length and breadth: ");
    cin>>l>>b;

    Rectangle r(l,b);       //Direct initialization 


    int a=r.area();
    int peri=r.perimeter();

    printf("Area = %d and Perimeter = %d",a, peri);
    return 0;
}
*/
