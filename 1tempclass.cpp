#include<iostream>
using namespace std;

template<class T>

class Arithmatic
{
    private:
    T a;
    T b;


//If function implemented outside class, then we should have declaration of those functions inside class.

    public:
    Arithmatic(T a,T b);

    T add();
    T sub();
};

template<class T>
Arithmatic<T>::Arithmatic(T a, T b)
{
    this->a=a;
    this->b=b;
}

template<class T>
T Arithmatic<T>::add()
{
    T c;
    c=a+b;
    return c;
}

template<class T>
T Arithmatic<T>::sub()
{
    T c;
    c=a-b;
    return c;
}

int main()
{
    Arithmatic<int> ar(10,5);
    cout<<ar.add()<<endl;

    Arithmatic<float> ar1(1.5,1.2);
    cout<<ar1.sub();
}