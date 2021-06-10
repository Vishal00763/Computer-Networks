#include<stdio.h>

void calc_CRC(int [], int[], int, int, int);
int main()
{
    int m[30],g[10],c[40],r,sa=1;
    int i,n,p;

    printf("Enter the length of the message word to be transmitted\n");
    scanf("%d",&n);
    printf("Enter the message MSB first\n");
    for(i=0;i<n;i++)
    scanf("%d",&m[i]);
    printf("Enter the length of generator polynomial\n");
    scanf("%d",&p);
    printf("Enter the generator polynomial MSB first\n");
    for(i=0;i<p;i++)
    scanf("%d",&g[i]);

    for(i=0;i<n;i++)
    c[i]=m[i];

    r=p-1;

    for(i=0;i<p;i++)
    {
        if(g[i]==1)
            break;
        else
            r=r-1;
    }

    for(i=n;i<n+r;i++)
    c[i]=0;




    n=n+r;

    calc_CRC(c,g,n,p,sa);

    printf("\nEnter the length of received codeword to check for an error\n");
    scanf("%d",&n);
    printf("Enter the message MSB first\n");
    for(i=0;i<n;i++)
    scanf("%d",&m[i]);
    printf("Enter the length of generator polynomial\n");
    scanf("%d",&p);
    printf("Enter the generator polynomial MSB first\n");
    for(i=0;i<p;i++)
    scanf("%d",&g[i]);

    sa=0;

    calc_CRC(m,g,n,p,sa);



}


void calc_CRC(int c[], int g[], int n, int p, int sa)
{

    int pos=0,k=pos,count=0,l=p,div[60],newpos,i,h,res[20];
    newpos=l;
    while(count<n)
    {

    for(i=(pos+p-l);i<newpos;i++)
    div[i]=c[count++];

    k=0;
    for(i=pos;i<pos+p;i++)
    {

        div[i]=(div[i]==g[k])?0:1;
        k++;
    }
    l=0;
    for(i=pos;i<pos+p;i++)
    {

        if(div[i]==0)
        {
        l++;
        }
        else
        break;
    }

    pos=pos+l;
    newpos=newpos+l;

}
h=0;
for(i=pos-l;i<pos-l+p;i++)
{
    res[h]=div[i];
    h++;

}

if(sa==1)
{

for(i=p-1;i>=0;i--)
res[i+n-p]=res[i];

for(i=0;i<n-p;i++)
res[i]=0;

printf("\nThe error is at position\n");

for(i=0;i<n;i++)
printf("%d ",res[i]);

printf("\nThe codeword transmitted is\n");
for(i=0;i<n;i++)
printf("%d ",(res[i]==c[i]?0:1));
}

else{
        for(i=0;i<p;i++)
        {

            if(res[i]==1)
            {
            printf("The received codeword has an error\n");
            break;

            }
        }

        if(i==p)
        {

            printf("The received codeword has no error\n");
        }


}




}