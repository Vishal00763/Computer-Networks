#include<stdio.h>
#include<ctype.h>
#include<string.h>

int main()
{
    char m[60],c[60],dc[60];// m-message c- codeword dc-decrypted codeword
    int n,i,keyk,temp,l,key;
    printf("Enter the plain text\n");
    gets(m);
    n=strlen(m);
    printf("Enter the key\n");
    scanf("%d",&keyk);

    for(i=0;i<n;i++)
    {
        temp=(int)toupper(m[i]);
        key=keyk;
        if(m[i]!=' ')
        {
            temp=(int)toupper(m[i]);
            if((temp+key)>90)
            {
                l=temp+key-90;
                c[i]=(char)(l+64);
            }
             else if((temp>=48)&&(temp<58)) // 0-9
            {
                key=keyk%10;
                if((temp+key)>57)
                {
                    c[i]=(char)(temp+key-57+47);
                }
                else
                    c[i]=(char)(temp+key);// DIGITS
            }
            else
                c[i]=(char)(temp+key);// ALPHABETS
        }
        else
            c[i]='*'; // WHITESPACES

    }
    c[n]='\0';

    printf("The cipher-text is\n%s\n",c);
    l=0;
    temp=0;

for(i=0;i<n;i++)
{
    key=keyk;

    if(c[i]!='*')
    {
        temp=(int)c[i];
        if((temp>=48)&&(temp<58))//DIGITS
            {
                key=key%10;
                if(temp-key<48)
                {
                    l=48-(temp-key);
                    dc[i]=(char)(58-l);  
                }
                else
                    dc[i]=(char)(temp-key);
            }
        else if((temp-key)<65)
            {
                l=65-(temp-key);
                dc[i]=(char)(91-l);
            }

            else
                dc[i]=(char)(temp-key);
}
    else
        dc[i]=' ';

    }


dc[n]='\0';
printf("The original plain text is\n%s\n",dc);

}
