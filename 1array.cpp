#include<iostream>
#include<stdio.h>

using namespace std;
int main()
{

    int n;
    cout<<"Enter size: ";
    cin>>n;
    int D[n]; //Variable sized arrays can't be initialized here. Either from keyboard or separately (Eg. D[2]=8).

    // for(int x:D)      //for each loop
    // {
    //     cout<<x<<endl;
    // }

    for(int i=0;i<n;i++)
    {
        cout<<D[i]<<" ";
    }
    cout<<endl;


    int A[5]={1,2};  //Declaring array like this returns 0 in index where value isn't initialized.
    int B[10]={2,4,6,8,10}; //This too return 0 in index where value isn't initialized.
    int C[5];
    
    C[1]=6;  //Declaring and initializing like this returns garbage value in index where value isn't initialized.
    C[2]=4;

    
    for(int i=0;i<10;i++)
    {
       printf("%d  ",B[i]);
    }
    cout<<endl;

    cout<<"Size of A: "<<sizeof(B)<<endl;  //4(int)*10=40

    cout<<"A[1]= "<<A[1]<<endl;  //Returns 2

    printf("A[3]= %d\n",A[3]);   //Returns 0

    cout<<"C[3]= "<<C[3]<<endl;  //Returns Garbage value

    return 0;
}



