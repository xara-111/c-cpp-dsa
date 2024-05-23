#include<stdio.h>
#include<stdlib.h>

int main()
{
  int *A;
  int n;
  int choice;
  int x;
  int i,j;
  printf("Enter dimension: ");
  scanf("%d",&n);

  A=(int *)malloc(n*sizeof(int));

  do
  {
    printf("\nMenu\n");
    printf("1.create\n");
    printf("2.get\n");
    printf("3.set\n");
    printf("4.display\n");
    

    printf("Enter your choice: ");
    scanf("%d",&choice);

    switch(choice)
    {
      case 1:for(i=1; i<=n; i++)
      {
        for( j=1; j<=n; j++)
        {
          printf("Enter elements in dimension [%d][%d]: ",i,j);
          scanf("%d",&A[(n*(j-1)-((j-2)*(j-1))/2)+(i-j)]);
        }
      }
      break;

      case 2:printf("Enter index: ");
      scanf("%d%d",&i,&j);
      if(i>=j)
      {
        printf("%d",A[(n*(j-1)-((j-2)*(j-1))/2)+(i-j)]);
      }
      else
      {
        printf("0");
      }
      break;

      case 3:printf("Enter row,column and element: ");
      scanf("%d%d%d",&i,&j,&x);
      if(i>=j)
      {
        A[(n*(j-1)-((j-2)*(j-1))/2)+(i-j)]=x;
      }
      break;

      case 4:for(i=1;i<=n;i++)
      {
        for(j=1;j<=n;j++)
        {
          if(i>=j)
              printf("%d ",A[(n*(j-1)-((j-2)*(j-1))/2)+(i-j)]);
          else
              printf("0 ");
        }
        printf("\n");
      }

    }
  } while (choice<5);
  return 0;
  
}