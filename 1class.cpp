#include<iostream>
using namespace std;


//In c++, we write extra code. Even the code we're not using.
//So when we write the class for something, it should be complete class.
class Rectangle 
{
    private:
    int length;
    int breadth;

    public:
    Rectangle()    //Every c++ program should have constructor as good style of programming
    {
        length=0;
        breadth=0;
    }
    Rectangle(int l,int b)
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
        return 2*(length*breadth);
    }
    
    //MUTATOR
    void setlength(int l)
    {
        length=l;
    }
    void setbreadth(int b)
    {
        breadth=b;
    }

    //ACCESSOR
    int getlength()
    {
        return length;
    }
    int getbreadth()
    {
        return breadth;
    }
    ~Rectangle()
    {
        cout<<"Destructor";
    }
};

int main()
{
    Rectangle r(10,5);
    cout<<"Area"<<r.area()<<endl;
    cout<<"Perimeter"<<r.perimeter()<<endl;

}