#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int a=10;
    int *p;
    p=&a;

    printf("%d\n",a);   //display data
    printf("%d\n",*p);  //display data (dereferencing)
    printf("%p\n",p);   //display address of a(address of variable p is pointing to).
    printf("%p\n",&a);  //display address of a
    printf("%p\n",&p);  //display address of the pointer.

    int A[5]={2,4,6,8,10};
    int *pA;
    pA=A;

    //No need for & when giving array name to the pointer.
    //Because name of an array A itself is the starting adress of the array.
    //If you want to use &, write pA=&A[0];

    for(int i=0;i<5;i++)
    {
        cout<<pA[i]<<endl;
        //In case of arrays, pointer acts as name of an array.
    }


//Array in heap memory

    int *h;
    //h=(int *)malloc(5*sizeof(int));    //c
    h=new int[5];                        //c++
    h[0]=10;h[1]=15;h[2]=14;h[3]=21;h[4]=31;

    for(int i=0;i<5;i++)
    {
        cout<<h[i]<<endl;
    }

//We should delete the dynamically allocated memory when we're finished using it
    delete [ ] h; //c++
    //free(p);      //c

//It's not necessary to delete in small programs.
//because dynamic memory gets deleted autmatically one the program ends.


int *a1;
char *a2;
float *a3;
double *a4;
struct Rectangle *a5;


//All displays 8

cout<<sizeof(a1)<<endl;
cout<<sizeof(a2)<<endl;
cout<<sizeof(a3)<<endl;
cout<<sizeof(a4)<<endl;
cout<<sizeof(a5)<<endl;

//Whatever the datatype of pointer is, pointer take same amount of memory.
}