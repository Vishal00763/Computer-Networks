#include<stdio.h>
#include<string.h>
int main()
{
char s[20][20];
char c[20][20];
char k[20][20];
int n,i,p=1,m=0;
printf("Enter the length of the code \n");
scanf("%d",&n);

for(i=0;i<n;i++)
scanf("%s",s[i]);


strcpy(c[0],"DLESTX");

for(i=0;i<n;i++)
{
if(strcmp("DLE",s[i])==0)
{
strcpy(c[p],"DLE");
p=p+1;
}

strcpy(c[p],s[i]);
p++;
}

strcpy(c[p],"DLEETX");

printf("The transmitted codeword is\n");

for(i=0;i<=p;i++)
printf("%s ",c[i]);


for(i=1;i<p;i++)
{
if(strcmp(c[i],"DLE")==0)
{
strcpy(k[m],c[i]);
m++;
i=i+1;
continue;
}
strcpy(k[m],c[i]);
m++;
}

printf("\nThe original code word is\n");

for(i=0;i<m;i++)
printf("%s ",k[i]);


}