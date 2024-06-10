#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr)
{
    printf("\n Elements are\n");
    for(int i=0; i<arr.length; i++)
    {
        printf("%d ",arr.A[i]);
    }
}


//Append is gonna add a new element at the end of the array.
//As it's going to modify the array, it should be a call by address type
void Append(struct Array *arr, int x)  
{
    if(arr->length < arr->size)    //if length =size then where will you append the new element?? length should be atleast 1 less than size so that there is 1 index left to be filled
        arr->A[arr->length++]=x;   
}

void Insert(struct Array *arr, int index, int x)
{
    if(index >= 0 && index <= arr->length)
    {
        for(int i=arr->length; i>index; i--)
        {
            arr->A[i]=arr->A[i-1];
        }
        arr->A[index]=x;
        arr->length++;
    }
}

int Delete(struct Array *arr, int index)
{
    int x=0;
    if(index >=0 && index < arr->length)
    {
        x=arr->A[index];
        for(int i=index; i<arr->length-1;i++)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
        return x;
    }
    return 0;
}

int linearsearch(struct Array arr, int key)
{
    for(int i=0;i<arr.length;i++)
    {
        if(key==arr.A[i])
            return i;
    }
    return -1;
}

void swap(int *x, int *y)
{
    int temp;
    temp=*x;
    *x=*y;
    *y=temp;
}

int transposition(struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i], &arr->A[i-1]);
            return i;
        }
    }
    return -1;
}

int MoveToHead(struct Array *arr, int key)
{
    for(int i=0;i<arr->length;i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[0]);
            return 0;
        }
    }
    return -1;
}

int Binarysearch(struct Array arr,int key)
{
    int l,mid,h;
    l=0;
    h=arr.length-1;

    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
           return mid;
        else if(key<arr.A[mid])
            h=mid-1;
        else 
            l=mid+1;
    }
    return -1;
}

int Recbin(int a[],int l, int h, int key)
{
    int mid;
    if(l<=h)
    {
        mid=(l+h)/2;
        if(key==a[mid])
            return mid;
        else if(key<a[mid])
             return Recbin(a,l,mid-1,key);
        else
             return Recbin(a,mid+1,h,key);
    }
    return -1;
}

int get(struct Array arr, int index)
{
  if(index>=0 && index < arr.length)
           return arr.A[index];
    return -1;
    
}

void Set(struct Array *arr, int index, int x)
{
    if(index>=0 && index < arr->length)
    {
        arr->A[index]=x;
    }
}

int Max(struct Array arr)
{
    int max;
    max=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    return max;
}

int Min(struct Array arr)
{
    int min;
    min=arr.A[0];
    for(int i=0;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
    }
    return min;
}

int Sum(struct Array arr)
{
    int sum=0;
    for(int i=0; i<arr.length; i++)
    {
        sum=sum+arr.A[i];
    }
    return sum;
}

int SumR(struct Array arr, int n)
{
    if(n<0)
       return 0;
    return SumR(arr,n-1)+arr.A[n];
}


float Avg(struct Array arr, int n)
{
    int total=0;
    for(int i=0;i<arr.length;i++)
    {
        total+=arr.A[i];
    }
    return total/n;
}

float avg(struct Array arr)
{
    return (float)Sum(arr)/arr.length;
}


void Reverse(struct Array *arr)
{
    int i,j;
    int *B;
    B=(int *)malloc(arr->length*sizeof(int));

    for(i=arr->length-1,j=0; i>=0; i--,j++)
    {
        B[j]=arr->A[i];
    }

    for(i=0;i<arr->length;i++)
    {
        arr->A[i]=B[i];
    }
}


void Rev2(struct Array *arr)
{
    int i,j;
    int temp;
    for(i=0,j=arr->length-1; i<j; i++,j--)
    {
        temp=arr->A[i];
        arr->A[i]=arr->A[j];
        arr->A[j]=temp;
    }
}

void leftshift(struct Array *arr)
{
    int i;
    for(i=0;i<arr->length+1;i++)
    {
        arr->A[i-1]=arr->A[i];
    }
}

void rotateleft(struct Array *arr)
{
    int i;
    int temp;

    temp=arr->A[0];
    arr->A[0]=arr->A[arr->length];
    arr->A[arr->length]=temp;

    for(i=0;i<arr->length+1;i++)
    {
        arr->A[i-1]=arr->A[i];
    }
}


void rightshift(struct Array *arr)  
{
    int i;
    for(i=arr->length-1; i>=0; i--)
    {
        arr->A[i+1]=arr->A[i];
    }
    arr->A[0]=0;
}

void rshift(struct Array *arr)  
{
    int i;
    for(i=arr->length-1; i>=0; i--)
    {
        arr->A[i]=arr->A[i-1];
    }
    arr->A[0]=0;
}


void rotateRight(struct Array *arr)  
{
    int i;
    int temp;

    int last_element=arr->A[arr->length-1];

    // temp=arr->A[arr->length-1];
    // arr->A[arr->length-1]=arr->A[0];
    // arr->A[0]=temp;
    
    for(i=arr->length-1; i>=0; i--)
    {
        arr->A[i+1]=arr->A[i];
    }

    arr->A[0]=last_element;
   
}


void insertsort(struct Array *arr, int x)
{
    int i=arr->length-1;
    if(arr->length==arr->size)
           return;
    while(i>=0 && arr->A[i]>x)
    {
        arr->A[i+1]=arr->A[i];
        i--;
    }
    arr->A[i+1]=x;
    arr->length++;
}


int isSort(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i] > arr.A[i+1])
                return 0;   //false
    }
    return 1;  //true
}


void arrange(struct Array *arr)
{
    int i=0;
    int j=arr->length-1;
    while(i<j)
    {
        while(arr->A[i]<0)
        {
            i++;
        }
        while(arr->A[j]>=0)
        {
            j--;
        }
        if(i<j)
        {
            swap(&arr->A[i],&arr->A[j]);
        }
    }
}
int main()
{
    struct Array arr ={{2,-3,4,5,-7},10,5};

    // Append(&arr, 10);

    // Insert(&arr,4,9);

    // Delete(&arr,0);    //void

    // // printf("%d ",Delete(&arr,0)); //return 

    // // printf("%d\n",linearsearch(arr,5));

    // // printf("%d\n",transposition(&arr,3));

    // // printf("%d\n",MoveToHead(&arr,4));

    // printf("%d\n ",Binarysearch(arr,6));

    // printf("%d\n ",Recbin(arr.A, 0, arr.length, 3));

    // printf("%d\n",get(arr, 1));

    // Set(&arr,1,9);

    // printf("%d\n",Max(arr));

    // printf("%d\n",Min(arr));

    // printf("%d\n",Sum(arr));

    // printf("%d\n",SumR(arr, arr.length-1));

    // printf("%f\n",Avg(arr,arr.length));

    // printf("%f\n",avg(arr));

    // Reverse(&arr);

    // Rev2(&arr);

    // leftshift(&arr);

    // rotateleft(&arr);

    // rightshift(&arr);

    // rshift(&arr);

    // rotateRight(&arr);

    // insertsort(&arr,6 );

    // printf("%d\n ", isSort(arr));

    arrange(&arr);

    Display(arr);
}