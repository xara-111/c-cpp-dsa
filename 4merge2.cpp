#include<stdio.h>
#include<stdlib.h>

struct Array
{
    int *A;
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

struct Array Merge(struct Array *arr1,struct Array *arr2)  // Merge takes 2 arrays
{
    int i,j,k;
    i=j=k=0;

    //We need 3rd array for storing the merged result(size should be 10)
    //Create an array from heap
    struct Array arr3;
    arr3.A=(int *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i]<arr2->A[j])
                 arr3.A[k++]=arr1->A[i++];
        else
                arr3.A[k++]=arr2->A[j++];
    }
    for(; i<arr1->length; i++ )
        arr3.A[k++]=arr1->A[i];

    for(; j<arr2->length; j++)
        arr3.A[k++]=arr2->A[j];

    arr3.length=arr1->length+arr2->length;
    //arr3.size=10;

    return arr3;
}
int main()
{
    struct Array arr1;
    struct Array arr2;

    int n;
    int m;
    int i;

    printf("Enter size of array1: ");
    scanf("%d",&arr1.size);

    arr1.A=(int *)malloc(arr1.size*sizeof(int));
    arr1.length=0;

    printf("Enter no. of elements in array1: ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i);
        scanf("%d",&arr1.A[i]);
    }
    arr1.length=n;




    printf("Enter size of array2: ");
    scanf("%d",&arr2.size);

    arr2.A=(int *)malloc(arr2.size*sizeof(int));
    arr2.length=0;

    printf("Enter no. of elements in array2: ");
    scanf("%d",&m);
    for(i=0;i<m;i++)
    {
        printf("Enter element %d: ",i);
        scanf("%d",&arr2.A[i]);
    }
    arr2.length=m;


    //Function Merge will create 3rd array and in main we'll take it's pointer
    struct Array *arr3;

    *arr3= Merge(&arr1, &arr2);
    Display(*arr3);
}