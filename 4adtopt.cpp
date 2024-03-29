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
int main()
{
    struct Array arr ={{2,3,4,5,6},10,5};

    // Append(&arr, 10);

    // Insert(&arr,4,9);

    // Delete(&arr,0);    //void

    // // printf("%d ",Delete(&arr,0)); //return 

    // // printf("%d\n",linearsearch(arr,5));

    // // printf("%d\n",transposition(&arr,3));

    // // printf("%d\n",MoveToHead(&arr,4));

    // printf("%d\n ",Binarysearch(arr,6));

    printf("%d\n ",Recbin(arr.A, 0, arr.length, 3));

    Display(arr);
}