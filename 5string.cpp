#include<stdio.h>
#include<string.h>

int valid(char *v)
{
    int i;
    for(i=0; v[i]!='\0'; i++)
    {
        if(!(v[i]>=65 && v[i]<=90) && !(v[i]>=97 && v[i]<=122) && !(v[i]>=48 && v[i]<=57))             
             return 0;
    }
    return 1;
}


int main()
{
    int i;
    int j;
    char S[]="welcome";
    char s[]="WELCOME";
    char t[]="WeLcOmE";

    for( i=0; i <S[i]!='\0'; i++)
    {

    }
    printf("length is %d\n",i);



    for(i=0; i<S[i]!='\0'; i++)
    {
        S[i]=S[i]-32;
    }
    printf("Upper case: %s\n",S);



    for(i=0; i<s[i]!='\0'; i++)
    {
        s[i]=s[i]+32;
    }
    printf("lower case: %s\n",s);




    for(i=0; i<t[i]!='\0'; i++)
    {
        if(t[i]>=65 && t[i]<=90)
        {
            t[i]=t[i]+32;
        }
        else if(t[i]>='a' && t[i]<=122)    //'a'=97 could be written like this
        {
            t[i]=t[i]-32;
        }
        
    }
    printf("change case: %s\n",t);  //Anything other than alphabet remain unmodified


    char u[]="How are   you? ";
    int vcount=0;
    int ccount=0;
    for(i=0;i<u[i]!='\0';i++)
    {
        if(u[i]=='a'||u[i]=='e'||u[i]=='i'||u[i]=='o'||u[i]=='u'||u[i]=='A'||u[i]=='E'||u[i]=='I'||u[i]=='O'||u[i]=='U')
        {
            vcount++;
        }
        else if(u[i]>=65 && u[i]<=90 || u[i]>=97 && u[i]<=122)
        {
            ccount++;
        }
    }
    printf("Vowels=%d Consonant=%d\n",vcount,ccount);

    int space=0;
    for(i=0; i<u[i]!='\0'; i++)
    {
        if(u[i]==' ' && u[i-1]!=' ')    //More than one, continuous space between words is WHITE SPACE, the second condition is for that reason.
        {
            space++;
        }
    }
    printf("words: %d\n",space);




    char v[]="Anil*?123";
    if(valid(v))
    {
        printf("valid string\n");
    }
    else{
        printf("Invalid\n");
    }




    char A[]="python\n";
    char B[7];
    
    for(i=0; A[i]!='\0'; i++)
    {

    }
    i=i-1;
    for(j=0; i>=0; i--,j++)
    {
        B[j]=A[i];
    }
    B[j]='\0';
    printf("%s\n ",B);



    for(j=0;A[j]!='\0';j++)
    {

    }
    j=j-1;
    for(i=0; i<j; i++,j--)
    {
        int t;
        t=A[i];
        A[i]=A[j];
        A[j]=t;
    }
    printf("%s\n ",A);



//For comparing strings, take same cases for all the strings because acc. to ascii, small letters have higher value than capital letters.
//So it will be declared as unequal and loop won't check rest of the string.
//String with Small case will be declared greater.
    char C[]="painter";
    char D[]="Painting";
    for(i=0,j=0; C[i]!='\0' && D[j]!='\0'; i++,j++)
    {
        if(C[i]!=D[j])
            break;
    }
    if(C[i]==D[j])
            printf("Equal\n");
    else if(C[i]<D[j])
            printf("1st string is Smaller\n");
    else
            printf("1st string is Greater\n");

    char P[]="civics";
    char R[6];
    for(i=0; P[i]!='\0'; i++)
    {

    }
    i=i-1;
    for(j=0; i>=0; i--,j++)
    {
        R[j]=P[i];
    }
    R[j]='\0';
    

    for(i=0,j=0; P[i]!='\0' && R[j]!='\0'; i++,j++)
    {
        if(P[i]!=R[j])
            break;
    }
    if(P[i]==R[j])
            printf("Palindrome\n");
    else
            printf("Not palindrome\n");



}