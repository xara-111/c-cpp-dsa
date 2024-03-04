/*
//ARRAY AS PARAMETER

#include<iostream>
#include<stdio.h>
using namespace std;

//void fun(int *A, int n)   -> *A could also be written instead of A[]    

void fun(int A[], int n)
{
    cout<<sizeof(A)/sizeof(int)<<endl;
    
    //This should return the length of the array but returns 2.
    //Because sizeof(A) is not giving the size of existing array.
    //It's giving the size of pointer and pointer in latest compiler takes 8 bytes divided by 4 bytes(int).
    //So it's returning 2.

    A[0]=12; //Changes the value of original array cuz its pass by address

    for(int i=0;i<n;i++)
    {
        cout<<A[i]<<endl;
        //For each loop can't be used on pointer
    }
}
int main()
{
    int A[ ]={2,4,6,8,10};
    int n=5; 

    fun(A,n);

    for(int x:A)
    cout<<x<<" ";
    

    return 0;
}
*/








//RETURN ARRAY
#include<iostream>
#include <stdio.h>
using namespace std;


// Function fun is creating an array of given size.
//This is benefit of dynamic memory
//Array is created in hep and inside the function fun.
//But even main function can access it because it's getting it's pointer.
//So if you create anything in heap then it can be accessed anywhere in the program if pointer is available on it.

int * fun(int size)
{
    int *p;
    p=(int *)malloc(size*sizeof(int));

    //  p= new int[size]  (c++)

    for(int i=0;i<size;i++)
    {
        p[i]=i+1;
    }
    return p;
}
int main()
{
    int *ptr,sz=5;
    ptr=fun(sz);

    for(int i=0;i<sz;i++)
    {
        cout<<ptr[i]<<endl;
    }
}

