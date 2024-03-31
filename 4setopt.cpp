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

struct Array* Union(struct Array *arr1,struct Array *arr2)  // Merge takes 2 arrays
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])        //if arr1 element is smaller
                 arr3->A[k++]=arr1->A[i++];

        else if(arr2->A[j] < arr1->A[i])   //if arr2 element is smaller 
                arr3->A[k++]=arr2->A[j++];

        else               // if both are equal, copy any one but increement both the array counters i and j. 
        {
                arr3->A[k++]=arr1->A[i++];
                j++;
        }
    }
    for(; i<arr1->length; i++ )
        arr3->A[k++]=arr1->A[i];

    for(; j<arr2->length; j++)
        arr3->A[k++]=arr2->A[j];

    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Intersect(struct Array *arr1,struct Array *arr2)  // Merge takes 2 arrays
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])        //if arr1 element is smaller
                i++;

        else if(arr2->A[j] < arr1->A[i])   //if arr2 element is smaller 
                j++;

        else if(arr1->A[i] == arr2->A[j])               
        {
                arr3->A[k++]=arr1->A[i++];
                j++;
        }
    }
    arr3->length=k;
    arr3->size=10;

    return arr3;
}

struct Array* Difference(struct Array *arr1,struct Array *arr2)  // Merge takes 2 arrays
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])        //if arr1 element is smaller
                 arr3->A[k++]=arr1->A[i++];

        else if(arr2->A[j] < arr1->A[i])   //if arr2 element is smaller 
                j++;

        else               
        {
            i++; 
            j++;
        }
    }
    for(; i<arr1->length; i++ )
    arr3->A[k++]=arr1->A[i];

    arr3->length=k;
    arr3->size=10;

    return arr3;
}
int main()
{
    struct Array arr1={{2,6,10,15,25},10,5};
    struct Array arr2={{3,6,7,15,20},10,5};

    struct Array *arr3;

    // arr3= Union(&arr1, &arr2);

    // arr3=Intersect(&arr1, &arr2);

    // arr3=Difference(&arr1, &arr2);
    Display(*arr3);
}