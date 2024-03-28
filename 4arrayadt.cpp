#include<stdio.h>
#include<stdlib.h>

// We need 3 members for array
struct Array
{
    int *A;
    int size;
    int length;
};

void display(struct Array arr)
{
    printf("\nThe elements are\n ");
    for(int i=0;i<arr.length;i++)
    {
        printf("%d ",arr.A[i]);
    }
}

int main()
{
    struct Array arr; // arr=name of array
    int n;
    int i;

    printf("Enter size of array: ");
    scanf("%d",&arr.size);

    arr.A=(int *)malloc(arr.size*sizeof(int));
    arr.length=0;

    printf("Enter no. of elements in array: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        printf("Enter element %d: ",i);
        scanf("%d",&arr.A[i]);
    }
    arr.length=n;

    display(arr);
}

