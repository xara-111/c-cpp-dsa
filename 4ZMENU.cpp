#include<stdio.h>
#include<stdlib.h>
#include<iostream>

struct Array
{
    int *A;
    int length;
    int size;
};

void Display(struct Array arr)
{
    printf("The array is:\n");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

void Append(struct Array *arr, int x)
{
    if(arr->length<arr->size)
    {
        arr->A[arr->length]=x;
    }
}

void Insert(struct Array *arr, int x, int index)
{
    if(index>=0 && index<=arr->length)
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
    if(index>=0 && index<arr->length)
    {
        x=arr->A[index];
        for(int i=index; i<arr->length-1; i--)
        {
            arr->A[i]=arr->A[i+1];
        }
        arr->length--;
    }
    return x;
}

int linearsearch(struct Array arr, int key)
{
    for(int i=0; i<arr.length; i++)
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
    int i;
    for(i=0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i],&arr->A[i-1]);
        }
    }
    return i;
}

int movetohead(struct Array *arr, int key)
{
    for(int i=0; i<arr->length; i++)
    {
        if(key==arr->A[i])
        {
            swap(&arr->A[i], &arr->A[0]);
        }
    }
    return 0;
}


int binarysearch(struct Array arr, int key)
{
    int l=0;
    int mid;
    int h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
           return mid;
        else if(key<arr.A[mid])
        {
            h=mid-1;
        }
        else
           l=mid+1;
    }
    return mid;
}

int recbinary(struct Array arr, int l, int h, int key)
{
    int mid;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
           return mid;
        else if(key<arr.A[mid])
           return recbinary(arr,l,mid-1,key);
        else
           return recbinary(arr,mid+1,h,key);
    }
    return -1;
}

int get(struct Array arr, int index)
{
    if(index>=0 && index<arr.length)
    {
        for(int i=0; i<arr.length; i++)
        {
            return arr.A[index];
        }
    }
    return -1;
}


void set(struct Array *arr, int x,int index)
{
    if(index>=0 && index<arr->length)
    {
        arr->A[index]=x;
    }
}

int max(struct Array arr)
{
    int max=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]>max)
        {
            max=arr.A[i];
        }
    }
    return max;
}

int min(struct Array arr)
{
    int min=arr.A[0];
    for(int i=1;i<arr.length;i++)
    {
        if(arr.A[i]<min)
        {
            min=arr.A[i];
        }
    }
    return min;
}

int sum(struct Array arr)
{
    int total=0;
    for(int i=0;i<arr.length;i++)
    {
        total+=arr.A[i];
    }
    return total;
}

int Rsum(struct Array arr, int n)
{
    if(n<0)
       return 0;
    return Rsum(arr,n-1)+arr.A[n];

}

int avg(struct Array arr, int n)
{
    int total=0;
    for(int i=0;i<arr.length;i++)
    {
        total+=arr.A[i];
    }
    return total/n;
}



void Reverse(struct Array *arr)
{
    int j;
    struct Array arr2;
    arr2.A=(int *)malloc(sizeof(struct Array));
    for(int i=arr->length-1, j=0; i>=0; i--,j++)
    {
        arr2.A[j]=arr->A[i];
    }
    for(int i=0;i<arr->length;i++)
    {
        arr->A[i]=arr2.A[j];
    }

}









int main()
{
    int ch;
    int n;
    int x, index;
    int key;

    struct Array arr1;
    printf("Enter the size of the array1: ");
    scanf("%d",&arr1.size);
    
    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    arr1.length=0;

   do
   {
    printf("\nMenu\n");
    printf("1.Append\n");
    printf("2.Insert\n");
    printf("3.Delete\n");
    printf("4.linearsearch\n");
    printf("5.transposition\n");
    printf("6.movetohead\n");
    printf("7.binarysearch\n");
    printf("8.recbinary\n");
    printf("9. get\n");
    printf("10.set\n");
    printf("11.max\n");
    printf("12.min\n");
    printf("13.sum\n");
    printf("14.Rsum\n");
    printf("15.Average\n");
    printf("16.Reverse\n");

    printf("Enter your choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
        case 1:printf("Enter no. to add: ");
        scanf("%d",&x);
        Append(&arr1,x);
        break;

        case 2:printf("Enter element and index: ");
        scanf("%d%d",&x,&index);
        Insert(&arr1,x,index);
        break;

        case 3: printf("Enter index: ");
        scanf("%d", &index);
        printf("The deleted element is: %d ",Delete(&arr1, index));
        break;

        case 4: printf("Enter key: ");
        scanf("%d",&key);
        printf("The index would be %d\n",linearsearch(arr1,key));
        break;

        case 5:printf("Enter key: ");
        scanf("%d",&key);
        printf("The index would be %d\n",transposition(&arr1,key));
        break;

        case 6:printf("Enter key: ");
        scanf("%d",&key);
        printf("The index would be %d\n",movetohead(&arr1,key));
        break;

        case 7:printf("Enter key: ");
        scanf("%d",&key);
        printf("The index would be %d\n",binarysearch(arr1,key));
        break;

        case 8:printf("Enter key: ");
        scanf("%d",&key);
        printf("The index would be %d\n",recbinary(arr1,0,arr1.length-1,key));
        break;

        case 9:printf("Enter index: ");
        scanf("%d",&index);
        printf("Element at index %d is %d\n",index,get(arr1,index));
        break;

        case 10:printf("Enter element and index: ");
        scanf("%d%d",&x,&index);
        set(&arr1,x,index);
        break;

        case 11: printf("The maximum is %d",max(arr1));
        break;

        case 12: printf("The minimum is %d",min(arr1));
        break;

        case 13: printf("Sum is %d",sum(arr1));
        break;

        case 14: printf("The sum is %d",Rsum(arr1, arr1.length));
        break;

        case 15:printf("Average is %d",avg(arr1, arr1.length));
        break;

        case 16:Reverse(&arr1);


    }
   } while (ch<20);
   return 0;
   
}
