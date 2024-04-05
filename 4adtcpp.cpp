#include<iostream>
using namespace std;
class Array //class should have data members and members functions
{
private:
     int *A; //Not a fixed size array but a pointer so that i can dynamically create an array
     int size;
     int length;
public:
//C++ class must have constructor and destructor 
     Array()  //non-parameterized constructor
     {
        size=10; //set the default size
        A=new int[10]; //create an array of default size
        length=0; //initially no element
     }
     Array(int sz) //parameterized constructor to create an array of desired size
     {
        size=sz;
        length=0;
        A=new int[size];
     }
     ~Array()
     {
        delete []A;
     }
     void Display();
     void Insert(int index, int x);
     int Delete(int index);
};

void Array::Display()
{
    for(int i=0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

void Array::Insert(int index, int x)
{
    if(index>=0 && index<=length)
    {
        for(int i=length-1;i>=index;i--)
        {
            A[i+1]=A[i];
        }
        A[index]=x;
        length++;
    }
}

int Array::Delete(int index)
{
    int x=0;
    if(index>=0 && index<length)
    {
        x=A[index];
        for(int i=index;i<length-1;i++)
        {
            A[i]=A[i+1];
        }
        length--;
    }
    return x;
}

int main()
{
    Array arr(10); //Create array object of same size
    arr.Insert(0,5);
    arr.Insert(1,6);
    arr.Insert(2,9);
    arr.Display();

    return 0;
}