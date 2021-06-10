#include<stdio.h>
int main()
{
int a[20],b[50],s[20];
int n,i,j=8,count=0;
int p=0;
printf("Enter the length of codeword\n");
scanf("%d",&n);
for(i=0;i<n;i++)
scanf("%d",&a[i]);

printf("The transmitted code is\n");
b[0]=0;
for(i=1;i<=6;i++)
b[i]=1;
b[7]=0;

for(i=0;i<n;i++)
{
b[j]=a[i];
if(a[i]==1)
{
count=count+1;
if(count==5)
{
b[++j]=0;
count=0;
}
}
else if(a[i]==0)
count=0;
j++;
}
b[j]=0;
b[++j]=1;
b[++j]=1;
b[++j]=1;
b[++j]=1;
b[++j]=1;
b[++j]=1;
b[++j]=0;




for(i=0;i<=j;i++)
printf("%d ",b[i]);
printf("\n");


printf("%d",j);
printf("\n");
p=0;
count=0;
for(i=8;i<=(j-8);i++)
{
if(b[i]==1)
count=count+1;
if((count==5)&&(b[i]==0))
{
count=0;
continue;
}
if(b[i]==0)
count=0;
s[p]=b[i];
p++;

}

printf("The original codeword is\n");

for(i=0;i<p;i++)
printf("%d ",s[i]);





}