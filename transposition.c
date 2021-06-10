#include<stdio.h>
#include<math.h>
#include<string.h>
#include<ctype.h>
int main()
{
    char s[20],m[100],c[50][50],h,cp[100],dc[50][50],s1[20];
    int i,n,j,rows,col,len,pos,p=0;
    double cal=0.0;
    printf("Enter the secret key in upper case\n");
    gets(s);
    n=strlen(s);
    for(i=0;i<n;i++)
    s1[i]=s[i];
    printf("Enter the plain-text\n");
    gets(m);
    col=n;
    len=n;
    cal=(double)strlen(m)/n;
    rows=ceil(cal);
    printf("The matrix is \n");
    for(i=0;i<rows;i++)
    {
        for(j=0;j<col;j++)
        {

            c[i][j]=m[p];
            if(p>=strlen(m))
            c[i][j]=' ';
            printf("%c ",c[i][j]);
            p++;
        }
        printf("\n");
    }
    p=0;
    printf("The cipher text is\n");

    while(len!=0)
    {
        h='[';
        for(i=0;i<n;i++)
        {
            if(s[i]=='_')
            continue;
            if(s[i]<h)
            {
                h=s[i];
                pos=i;
            }
        }
            s[pos]='_';
            len--;
            for(i=0;i<rows;i++)
            {
                cp[p]=c[i][pos];
                printf("%c",cp[p]);
                p++;
            }

    }
    len=n;
    p=0;
    printf("\nThe decrypted text is\n");
    while(len!=0)
    {

        h='[';
        for(i=0;i<n;i++)
        {
            if(s1[i]=='_')
            continue;
            if(s1[i]<h)
            {
                h=s1[i];
                pos=i;
            }
        }
            s1[pos]='_';
            len--;
            for(i=0;i<rows;i++)
            {
            dc[i][pos]=cp[p];
            p++;
            }
    }

    for(i=0;i<rows;i++)
    {

        for(j=0;j<col;j++)
        printf("%c",dc[i][j]);
    }
}
