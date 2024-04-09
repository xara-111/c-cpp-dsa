#include<iostream>
using namespace std;
int j;
int i;
class lowerTri
{
    private:
      int n;
      int *A;
    public:
      lowerTri()
      {
        n=2;
        A=new int[2*(2+1)/2];
      }

      lowerTri(int  n)
      {
        this->n=n;
        A=new int[n*(n+1)/2];
      }

    ~lowerTri()
    {
        delete []A;
    }

    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    int getdimension()
    {
        return n;
    }

    

};

void lowerTri::set(int i, int j, int x)
{
    if(i>=j)
        A[i*(i-1)/2+j-1]=x;
        //  A[n*(j-1)-(j-2)*(j-1)/2+i-j]=x;   (COLUMN MAJOR FORMULA)
}

int lowerTri::get(int i, int j)
{
    if(i>=j)
       return A[i*(i-1)/2+j-1];
       //return A[n*(j-1)-(j-2)*(j-1)/2+i-j];  (COLUMN MAJOR FORMULA)
    else
       return 0;
}

void lowerTri::display()
{
    for(i=1; i<=n; i++)
    {
        for(j=1; j<=n; j++)
        {
            if(i>=j)
              cout<<A[i*(i-1)/2+j-1]<<" ";
              // cout<<A[n*(j-1)-(j-2)*(j-1)/2+i-j]<<" "; (COLUMN MAJOR FORMULA)
            else
              cout<<"0 ";
        }
        cout<<endl;
    }
}

int main()
{
    int d;
    cout<<"Enter dimension: ";
    cin>>d;


    lowerTri lm(4);
    
    int x;
    cout<<"Enter all element";
    for(int i=1; i<=d; i++)
    {
        for(int j=1; j<=d; j++)
        {
            cin>>x;
            lm.set(i,j,x);
        }
    }
    printf("\n\n");
    lm.display();
}