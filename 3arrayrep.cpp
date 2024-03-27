
/*
//DECLARE AND DISPLAY ADDRESS OF ARRAY

#include<stdio.h>
#include<iostream>
int main()
{
    int A[5];
    for(int i=0; i<5; i++)
    {
        printf("%u \n",&A[i]);
    }
    return 0;
}
*/






/*
//ARRAY IN HEAP

#include<iostream>
#include<stdio.h>
#include<stdlib.h>   //malloc

using namespace std;
int main()
{
    int A[5];

//C
    int *p;
    p=(int *)malloc(5*sizeof(int));
    for(int i=0; i<5; i++)
    {
        printf("%d ",p[i]);
    }
//C++
    int *q;
    q=new int [5];
    for(int i=0; i<5; i++)
    {
        cout<<q[i]<<" ";
    }
}
*/






/*
//INCREASE SIZE OF ARRAY 

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
int main()
{
    int *p;
    p=(int *)malloc(5*sizeof(int));
    p[0]=3; p[1]=4; p[2]=5; p[3]=8; p[4]=2;

    for(int i=0;i<5;i++)
    {
        printf("%d ",p[i]);
    }

    printf("\n");

    int *q;
    q=(int *)malloc(10*sizeof(int));
    for(int i=0;i<5;i++)
    {
        q[i]=p[i];
    }
    free(p);
    p=q;
    q=NULL;
    for(int i=0;i<10;i++)
    {
        printf("%d ",p[i]);
    }
}
*/






//TYPES OF 2D ARRAY DECLARATION

#include <stdio.h>
#include <stdlib.h>
int main()
{
 int A[3][4]={{1,2,3,4},{2,4,6,8},{1,3,5,7}};    // 2D array in stack

 for(int i=0;i<3;i++)
 {
    for(int j=0;j<4;j++)
    {
        printf("%d ",A[i][j]);
    }
    printf("\n");
 }

printf("\n");

 int *B[3];    //ARRAY OF POINTERS IN STACK (ACTUAL ARRAY IN HEAP)

 int **C;      //ALMOST EVERYTHING IN HEAP(DOUBLE POINTER)

 int i,j;


 B[0]=(int *)malloc(4*sizeof(int));
 B[1]=(int *)malloc(4*sizeof(int));
 B[2]=(int *)malloc(4*sizeof(int));

for(i=0;i<3;i++)
{
    for(j=0;j<4;j++)
    {
        printf("%d ",B[i][j]);
    }
    printf("\n");
}
printf("\n");



 C=(int **)malloc(3*sizeof(int *));
 C[0]=(int *)malloc(4*sizeof(int));
 C[1]=(int *)malloc(4*sizeof(int));
 C[2]=(int *)malloc(4*sizeof(int));

 for(i=0;i<3;i++)
 {
 for(j=0;j<4;j++)
 printf("%d ",C[i][j]);
 printf("\n");
 }
 return 0;
}