#include<stdio.h>
#include<stdlib.h>
struct Matrix
{
    int *A;
    int n;
};

void set(struct Matrix *m, int i, int j, int x)
{
    if(i>=j)
       m->A[i*(i-1)/2+j-1]=x;
       //  m->A[m->n*(j-1)+(j-2)*(j-1)/2+i-j]=x   (COLUMN MAJOR FORMULA)
}

int Get(struct Matrix m, int i,int j)
{
    if(i>=j)
       return m.A[i*(i-1)/2+j-1];
       // return m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]   (FOR COLUMN MAJOR)
    else 
        return 0;
}

void display(struct Matrix m)
{
    int i;
    int j;
    for(i=1;i<=m.n;i++)
    {
        for(j=1;j<=m.n;j++)
        {
            if(i>=j)
                  printf("%d ",m.A[i*(i-1)/2+j-1]);
                  // printf("%d ",m.A[m.n*(j-1)+(j-2)*(j-1)/2+i-j]);   (FOR COLUMN MAJOR)

            else
                  printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct Matrix m;
    int i,j;
    int x;
    printf("Enter dimension: ");
    scanf("%d",&m.n);

    m.A=(int *)malloc(m.n *(m.n+1)/2*sizeof(int));

    printf("Enter all elements");
    for(i=1; i<=m.n; i++)
    {
        for(j=1; j<=m.n; j++)
        {
            scanf("%d", &x);
            set(&m,i,j,x);
        }
    }
    printf("\n");
    display(m);
}

//UPPER TRIANGULAR MATRIX ALSO.
