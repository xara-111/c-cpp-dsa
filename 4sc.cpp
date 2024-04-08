//Student Challenge

//FINDING MISSING ELEMENT IN ARRAY
//Single missing element in sorted array(first n natural no.s)

#include<stdio.h>
#include<iostream>
using namespace std;

struct Array 
{
    int A[100];
    int size;
    int length;
};

void Display(struct Array arr)
{
    cout<<"The array is- "<<endl;

    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

int max(struct Array arr4)
{
    int max=arr4.A[0];
    for(int i=0;i<arr4.length;i++)
    {
        if(arr4.A[i]>max)
        {
            max=arr4.A[i];
        }
    }
    return max;
}

int missing1(struct Array arr)
{
    int sum=0;  //The sum we get from missing element array
    int s=0;    //Actual sum of n natural no.s
    int missing_no;

    for(int i=0; i<arr.length; i++)
    {
        sum=sum+arr.A[i];
    }
    int n=arr.A[arr.length-1];
    s=(n*(n+1))/2;

    if(s==sum)
         printf("There's no missing element\n");
    else
        missing_no=s-sum;
        return missing_no;
    
}

int missing2(struct Array arr2)
{

    int lower=arr2.A[0];
    int higher=arr2.A[arr2.length-1];
    int n=arr2.length;
    int difference=lower-0;

    for(int i=0; i<n; i++)
    {
        if(arr2.A[i]-i!=difference)
        
            return difference+i;
       
    }
    return -1;
    
}


void missing3(struct Array arr3)
{
    int Missing;
    int l=arr3.A[0];
    int diff=l-0;
    for(int i=0; i<arr3.length; i++)
    {
        if(arr3.A[i]-i != diff)
        {
            while(diff<arr3.A[i]-i)
            {
                printf("%d ",i+diff);
                diff++;
            }
        }
    }
    printf("\n");
}

void missing32(struct Array arr3)
{
    int j=0;
    for(int i=arr3.A[0]; i<arr3.A[arr3.length-1]; i++)
    {
        if(i==arr3.A[j])
        {
            j++;
        }
        else
        {
             printf("%d ",i);
        }
       
    }
    printf("\n");
}

void missing4(struct Array arr4, struct Array H)
{
    for(int i=0;i<arr4.length;i++)
    {
        H.A[arr4.A[i]]++;
    }
    for(int i=1; i<H.length; i++)
    {
        if(H.A[i]==0)
        {
            printf("%d ",i);
        }
    }
    printf("\n");
    
}

//FIND DUPLICATE ELEMENT IN ARRAY
int Duplicate(struct Array arr5)
{
    int duplicate=0;
    for(int i=0;i<arr5.length;i++)
    {
        if(arr5.A[i]==arr5.A[i+1] && arr5.A[i]!=duplicate)
        {
            duplicate=arr5.A[i];
        }
    }
    return duplicate;
}

void duplicate2(struct Array arr6)
{
    int i;
    int j;
    for(i=0;i<arr6.length-1;i++)
    {
        if(arr6.A[i]==arr6.A[i+1])
        {
            j=i+1;
        
        while(arr6.A[j]==arr6.A[i])
        {
            j++;
        }
        printf("%d appearing %d times \n ",arr6.A[i],j-i);
        i=j-1;
    } 
}
}

void duplicate22(struct Array arr6, struct Array H)
{
    for (int i = 0; i < arr6.length-1; i++)
    {
        H.A[arr6.A[i]]++;
    }
    for(int i=0; i<H.length; i++)
    {
        if(H.A[i]>1)
        {
            printf("%d appears %d times\n", i,H.A[i]);
        }
    }    
}

void duplicate3(struct Array arr7)
{
    int i;
    int count;
    for(i=0; i<arr7.length-1; i++)
    {
        count=1;
        if(arr7.A[i]!= -1)
        {
            for(int j=i+1; j<arr7.length; j++)
            {
                if(arr7.A[i]==arr7.A[j])
                {
                    count++;
                    arr7.A[j]=-1;
                }
            }
        }
        if(count>1)
         printf("%d appears %d times\n ",arr7.A[i],count);
    }
    
}

void duplicate32(struct Array arr7, struct Array H)
{
    for(int i=0; i<arr7.length; i++)
    {
        H.A[arr7.A[i]]++;
        
    }
    for(int j=1; j<H.length; j++)
    {
        if(H.A[j]>1)
        {
            printf("%d appears %d times. ",j,H.A[j]);
        }
    }
    
}

//FIND A PAIR WITH SUM K 
void pair1(struct Array arr8, int k)
{
    for(int i=0; i<arr8.length-1; i++)
    {
        for(int j=i+1; j<arr8.length; j++)
        {
            if(arr8.A[i]+arr8.A[j]==k)
            {
                printf("%d + %d = %d\n", arr8.A[i],arr8.A[j],k);
            }
        }
    }
}

void pair2(struct Array arr8,struct Array H, int k)
{
    for(int i=0; i<arr8.length; i++)
    {
        if(H.A[k-arr8.A[i]]!=0)
        {
            printf("%d + %d = %d\n ", arr8.A[i],k-arr8.A[i],k);
        }
        H.A[arr8.A[i]]++;
    }
}

void pair3(struct Array arr9, int k)
{
    int i=0;
    int j=arr9.length-1;
    while(i<j)
    {
        if(arr9.A[i]+arr9.A[j]==k)
        {
            printf("%d + %d=%d\n",arr9.A[i], arr9.A[j],k);
            i++;
            j--;
        }
        else if(arr9.A[i]+arr9.A[j]<k)
             i++;
        else
             j--;
    }
}

//FINDING MAX AND MIN IN A SINGLE SCAN
void mm(struct Array arr9)
{
    int max=arr9.A[0];
    int min=arr9.A[0];
    for(int i=1; i<arr9.length; i++)
    {
        if(arr9.A[i]<min)
        {
            min=arr9.A[i];
        }
        else if (arr9.A[i]>max)
        {
            max=arr9.A[i];
        }
        
    }
    printf("max=%d ",max);
    printf("min=%d ",min);
    
}
int main()
{
    // struct Array arr={{1,2,3,4,5,6,8,9,10,11,12},100,11};
    // struct Array arr2={{6,7,8,9,10,11,13,14,15,16,17},100,11};
    // struct Array arr3={{6,7,8,9,11,12,15,16,17,18,19},100,11};
    // struct Array arr4={{3,2,6,1,4,8},100,6};
    // struct Array H={{},100,max(arr4)};
    // struct Array arr5={{1,2,3,3,4,5},100,6};
    // struct Array arr6={{1,2,3,3,4,5,6,6,6,6,7},100,11};
    // struct Array H={{},100,max(arr6)};
    // struct Array arr7={{1,8,6,4,6,8,5},100,7};
    // struct Array H={{},100,max(arr7)};
    // struct Array arr8={{3,7,5,2,8},100,5};
    // struct Array H={{},100,max(arr8)}
    struct Array arr9={{1,3,4,5,6,9},100,6};

    // printf("The missing element is %d\n ",missing1(arr));
    // printf("The missing element in arr2 is %d\n ",missing2(arr2));
    // missing3(arr3);
    // missing32(arr3);
    // printf("max is %d\n ",max(arr4));
    // missing4(arr4,H);
    //printf("The missing element in arr4 is %d\n ",missing4(arr4,H));

    // printf("The duplicate is %d\n",Duplicate(arr5));
    // duplicate2(arr6);
    // duplicate22(arr6,H);
    // duplicate3(arr7);
    // duplicate32(arr7,H);
    // pair1(arr8,10);
    // pair2(arr8,H,10);
    // pair3(arr9,10);
    mm(arr9);
}