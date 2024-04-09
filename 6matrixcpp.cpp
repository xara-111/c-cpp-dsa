#include<iostream>
using namespace std;
int j;
int i;
class diagonal
{
    private:
      int n;
      int *A;
    public:
      diagonal()
      {
        n=2;
        A=new int[2];
      }

      diagonal(int  n)
      {
        this->n=n;
        A=new int[n];
      }

    ~diagonal()
    {
        delete []A;
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();

    

};

void diagonal::set(int i, int j, int x)
{
    if(i==j)
        A[i-1]=x;
}

int diagonal::get(int i, int j)
{
    if(i==j)
       return A[i-1];
    else
       return 0;
}

void diagonal::display()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i==j)
              cout<<A[i-1]<<" ";
            else
              cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    diagonal d(4);
    d.set(1,1,5);
    d.set(2,2,8);
    d.set(3,3,9);
    d.set(4,4,12);
    d.display();
}