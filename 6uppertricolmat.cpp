#include<stdio.h>
#include<stdlib.h>

struct Matrix
{
    int *A;
    int n;
};


void set(struct Matrix *m,int i, int j, int x)
{
    if(i<=j)
       m->A[(j*(j-1))/2+(i-1)]=x;
}

int get(struct Matrix m, int i, int j)
{
    if(i<=j)
       return m.A[(j*(j-1))/2+(i-1)];
    else
       return 0;
}

void display(struct Matrix m)
{
    int i,j;

    for(i=1; i<=m.n; i++)
    {
        for(j=1; j<=m.n; j++)
        {
            if(i<=j)
                printf("%d ",m.A[(j*(j-1))/2+(i-1)]);
            else
                printf("0 ");
        }
        printf("\n");
    }
}
int main()
{
    struct Matrix m;
    int i,j,x;

    printf("Enter dimension: ");
    scanf("%d",&m.n);

    m.A=(int *)malloc((m.n*(m.n+1))/2*sizeof(int));

    printf("Enter all element of the matrix:\n ");
    for(i=1; i<=m.n; i++)
    {
        for(j=1; j<=m.n; j++)
        {
            printf("Enter element in [%d][%d]: ",i,j);
            scanf("%d",&x);
            set(&m,i,j,x);
        }
    }
    display(m);
}