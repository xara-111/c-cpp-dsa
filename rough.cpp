#include<stdio.h>

int valid(char *v)
{
    int i;
    for(i=0; v[i]!='\0'; i++)
    {
        if((v[i]>=65 && v[i]<=90) || (v[i]>=97 && v[i]<=122) || (v[i]>=48 && v[i]<=57))             
             return 0;
    }
    return 1;
}

int main()
{
    char v[]="anil123";
    if(valid(v))
    {
        printf("valid string\n");
    }
    else{
        printf("Invalid\n");
    }
}