#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int A[11];
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

struct Array* Merge(struct Array *arr1,struct Array *arr2)  // Merge takes 2 arrays
{
    int i,j,k;
    i=j=k=0;

    //We need 3rd array for storing the merged result(size should be 10)
    //Create an array from heap
    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
                 arr3->A[k++]=arr1->A[i++];
        else
                arr3->A[k++]=arr2->A[j++];
    }
    for(; i<arr1->length; i++ )
        arr3->A[k++]=arr1->A[i];

    for(; j<arr2->length; j++)
        arr3->A[k++]=arr2->A[j];

    arr3->length=arr1->length+arr2->length;
    arr3->size=11; 

    return arr3;
}
int main()
{
    //Create 2 array and initialize them
    struct Array arr1={{2,6,10,15,25},11,5};
    struct Array arr2={{3,4,7,18,20,24},11,6};

    //Function Merge will create 3rd array and in main we'll take it's pointer
    struct Array *arr3;

    arr3= Merge(&arr1, &arr2);
    Display(*arr3);
}