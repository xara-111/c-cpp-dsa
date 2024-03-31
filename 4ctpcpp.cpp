#include<stdio.h>
#include<stdlib.h>

class Array
{
private:  //data members
    int *A;
    int size;
    int length;
    void swap(int *x, int *y);

public:   //functions
    Array()  //Constructor for array
    {
        size=10;
        length=0;
        A=new int[size];
    }
    Array(int sz)
    {
        size=sz;
        length=0;
        A=new int[size];
    }
    ~Array()
    {
        delete []A;
    }
    
    void Display();
    void Append(int x);
    int Delete( int index);
    int linearsearch(int key);
    int transposition(int key);
    int MoveToHead(int key);
    int Binarysearch(int key);
    int Recbin(int a[],int l, int h, int key);
    int get(int index);
    void Set(int index, int x);
    int Max();
    int Min();
    int Sum();
    int SumR();
    float Avg( int n);
    float avg();
    void Reverse();
    void Rev2();
    void leftshift();
    void rotateleft();
    void rightshift(); 
    void rshift();
    void rotateRight();
    void insertsort(int x);
    int isSort();
    void arrange();
    Array* Merge(Array *arr2);  
    Array* Union(Array *arr2);
    Array* Intersect(Array *arr2);  

};




void Array::Display()
{
    printf("\n Elements are\n");
    for(int i=0; i<length; i++)
    {
        printf("%d ",arr.A[i]);
    }
}


void Array::Append(int x)  
{
    if(length < size)   
        A[length++]=x;   
}



int Array::Delete( int index)
{
    int x=0;
    if(index >=0 && index < length)
    {
        x=A[index];
        for(int i=index; i<length-1;i++)
        {
            A[i]=A[i+1];
        }
        length--;
        return x;
    }
    return 0;
}







int Array::linearsearch(int key)
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










Array* Merge(Array arr2)  // Merge takes 2 arrays
{
    int i,j,k;
    i=j=k=0;

    Array *arr3=new Array(length+arr2.length);

    while(i<length && j<arr2.length)
    {
        if(A[i]<arr2.A[j])
                 arr3->A[k++]=A[i++];
        else
                arr3->A[k++]=arr2.A[j++];
    }
    for(; i<length; i++ )
        arr3->A[k++]=A[i];

    for(; j<arr2.length; j++)
        arr3->A[k++]=arr2.A[j];

    arr3->length=length+arr2.length;
    

    return arr3;
}











struct Array* Union(struct Array *arr1,struct Array *arr2)  
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])        
                 arr3->A[k++]=arr1->A[i++];

        else if(arr2->A[j] < arr1->A[i])  
                arr3->A[k++]=arr2->A[j++];

        else               
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










struct Array* Intersect(struct Array *arr1,struct Array *arr2)  
{
    int i,j,k;
    i=j=k=0;

    struct Array *arr3=(struct Array *)malloc(sizeof(struct Array));

    while(i<arr1->length && j<arr2->length)
    {
        if(arr1->A[i] < arr2->A[j])        
                i++;

        else if(arr2->A[j] < arr1->A[i])   
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





int main()
{
    //Should know the size of array
    //Because there's a pointer and i should dynamically create an array
    //And assign it to that pointer
    Array *arr1;
    int ch,sz;
    int x,index;

    printf("Enter size of array: ");
    scanf("%d",&sz);
    arr1=new Array(sz);

do
{

    printf("\n\nMenu\n");
    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Sum\n");
    printf("5. Display\n");
    printf("6.Exit\n");

    printf("enter you choice: ");
    scanf("%d",&ch);

    switch(ch)
    {
    case 1: printf("Enter an element and index");
    scanf("%d%d",&x,&index);
    arr1.Insert(index,x);
    break;

    case 2: printf("Enter index ");
    scanf("%d",&index);
    x=arr1.Delete(index);
    printf("Deleted Element is %d\n",x);
    break;

    case 3:printf("Enter element to search ");
    scanf("%d",&x);
    index=arr1.linearsearch(x);
    printf("Element index %d",index);
    break;

    case 4:printf("Sum is %d\n",arr1.Sum());
    break;

    case 5:arr1.Display();

 }
}while(ch<6);
return 0;
}