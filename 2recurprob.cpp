
/*
#include<stdio.h>
#include<iostream>

using namespace std;

int sum(int n)
{
    if(n==0)
      return 0;
    return sum(n-1)+n;
}
int main()
{
    int n;
    cout<<"enter n: ";
    cin>>n;

    int Sum=sum(n);
    cout<<"Sum is "<<Sum;
}
*/


/*
#include<iostream>
using namespace std;

int fact(int n)
{
    if(n==0)
     return 1;
    return fact(n-1)*n;
}

int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    int factorial=fact(n);
    cout<<"Factorial is "<<factorial;
}
*/


/*
#include<iostream>
#include<stdio.h>
using namespace std;
int pow(int m, int n)
{
    if(n==0)
      return 1;
    return pow(m,n-1)*m;
}
int main()
{
    int m,n;
    cout<<"Enter m and n: ";
    cin>>m>>n;

    int power=pow(m,n);
    cout<<"Result= "<<power;
}
*/


/*
#include<iostream>
#include<stdio.h>
using namespace std;

int pow(int m, int n)
{
    if(n==0)
       return 1;
    if(n%2==0)
       return pow(m*m,n/2);
    return m*pow(m*m,(n-1)/2);
}

int main()
{
    int m,n;
    cout<<"enter m amd n: ";
    cin>>m>>n;

    int power=pow(m,n);
    cout<<"Result= "<<power;
}
*/


/*
#include<iostream>
#include<stdio.h>
using namespace std;

double e(int x, int n)
{
    static double p=1, f=1;
    double r;
    if(n==0)
       return 1;
    else
       r=e(x,n-1);
       p=p*x;
       f=f*n;
       return r+p/f;
}

int main()
{
    double x;
    double n;
    cout<<"Enter x and n: ";   //Increase the no. of terms(n) to get more precise value
    cin>>x>>n;

    cout<<"Result= "<<e(x,n);

}
*/


/*
#include<stdio.h>
#include<iostream>

double e(int x, int n)
{
    double s=1;
    double num=1;
    double den=1;
    for(int i=1; i<=n; i++)
    {
        num=num*x;
        den=den*i;
        s=s+num/den;
    }
    return s;
}

int main()
{
    double x,n;
    printf("Enter x and n: ");
    scanf("%lf, %lf",&x,&n);
    printf("Result= %lf",e(x,n));
}
*/


/*
#include<stdio.h>
#include<iostream>
using namespace std;

double e(double x, double n)
{
    static double s=1;
    if(n==0)
       return s;
    s=1+(x/n)*s;            // s=1+x*s/n 
    return e(x, n-1);
}
int main()
{
    double x,n;
    printf("Enter x and n: ");
    scanf("%lf, %lf",&x,&n);

    printf("Result= %lf",e(x,n));
}
*/


/*
#include<stdio.h>
#include<iostream>
using namespace std;
double e(double x, double n)
{
    double s=1;
    for(; n>0; n--)
    {
        s=1+(x/n)*s;
    }
    return s;
}
int main()
{
    double x,n;
    printf("Enter x and n: ");
    scanf("%lf, %lf",&x,&n);

    printf("Result= %lf",e(x,n));
}
*/

/*
#include<stdio.h>
#include<iostream>
using namespace std;
int fib(int n)
{
    int t0=0,t1=1,s;
    if(n<=1)
       return n;
    for(int i=2; i<=n; i++)
    {
        s=t0+t1;
        t0=t1;
        t1=s;
    }
    return s;
}
int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;

    cout<<"Result= "<<fib(n);
}
*/


/*
#include<iostream>
#include<stdio.h>
using namespace std;

int fib(int n)
{
    if(n<=1)
       return n;
    return fib(n-2)+fib(n-1);
}
int main()
{
    int n;
    cout<<"Enter n: ";
    cin>>n;
    cout<<"Result: "<<fib(n);
}
*/


/*
#include<iostream>
#include<stdio.h>
using namespace std;

int F[10];

int fib(int n)
{
    if(n<=1)
    {
       F[n]=n;
      return n;
    }
    else
    {
        if(F[n-2]==-1)
        
            F[n-2]=fib(n-2);
        
        if(F[n-1]==-1)
        
            F[n-1]=fib(n-1);

        return F[n-2]+F[n-1];  
    }
   
    
}
int main()
{
    for(int i=0; i<10; i++)
    {
        F[i]=-1;    
    }

    cout<<"Result= "<<fib(10);
}
*/


/*
#include<iostream>
#include<stdio.h>
using namespace std;
int fact(int n)
{
    if(n==0)
     return 1;
    return fact(n-1)*n;
}
int c(int n, int r)
{
    int t1,t2,t3;
    t1=fact(n);
    t2=fact(r);
    t3=fact(n-r);
    return t1/(t2*t3);
}
int main()
{
    int n,r;
    cout<<"Enter n and r: ";
    cin>>n>>r;

    cout<<" Result: "<<c(n,r);
}
*/


/*
#include<iostream>
#include<stdio.h>
using namespace std;
int c(int n, int r)
{
    if(n==r || r==0)
        return 1;
    return c(n-1,r-1)+c(n-1,r);
}
int main()
{
    int n,r;
    cout<<"Enter n and r: ";
    cin>>n>>r;

    cout<<"Result= "<<c(n,r);
}
*/


#include<stdio.h>
#include<iostream>
void TOH(int n, int A, int B, int C)
{
    if(n>0)
    {
        TOH(n-1, A,C,B);
        printf("(from %d to %d)\n",A,C);
        TOH(n-1,B,A,C);
    }
}
int main()
{
    TOH(5,1,2,3);
    return 0;
}