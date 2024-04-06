//WRITING A CLASS IN C++
//USING TEMPLATE FOR VARIOUS DATATYPES


#include<iostream>
using namespace std;

//This is an Array of type integer.
//If we want a float type array then it's possible to make a generic class in c++
template<class T>    //Generic array

class Array //class should have data members and members functions
{
private:
     T *A; //Not a fixed size array but a pointer so that i can dynamically create an array.
    //Inside the class wherever i want generic datatype i should write T there.
     int size; 
     int length;
public:
//C++ class must have constructor and destructor 
     Array()  //non-parameterized constructor
     {
        size=10; //set the default size
        A=new T[10]; //create an array of default size
        length=0; //initially no element
     }
     Array(int sz) //parameterized constructor to create an array of desired size
     {
        size=sz;
        length=0;
        A=new T[size];
     }
     ~Array()
     {
        delete []A;
     }
     void Display();
     void Insert(int index, T x);
     T Delete(int index);
};

template <class T> //For each function, we should write it and use it.
void Array<T>::Display() //Write T here since class is template type
{
    for(int i=0;i<length;i++)
    {
        cout<<A[i]<<" ";
    }
    cout<<endl;
}

template <class T>
void Array<T>::Insert(int index, T x)
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

template <class T>
T Array<T>::Delete(int index)
{
    T x=0;
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
    //Create array object of same size
    Array<float> arr(10); //In bracket write any datatype to use(now, float)
    arr.Insert(0,5);
    arr.Insert(1,6.4);
    arr.Insert(2,9);
    arr.Display();
    cout<<arr.Delete(0)<<endl;
    arr.Display();

    return 0;
}