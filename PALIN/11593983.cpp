#include<stdio.h>
#include<string.h>
char k[1000005];
int flag;
int main()
{

    int i,t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",k);
        palin(k);
        printf("%s\n",k);
    }
    return 0;
}
void palin()
{
    int l,i,t,temp;
        l=strlen(k);
        flag=1;
        for(i=0;i<l;i++)
        {
            if(k[i]!='9')
            {
                flag=0;
                break;
            }
        }
        if(flag==1)
        {
            k[0]='1';
            for(i=1;i<l;i++)
                k[i]='0';
            k[l]='1';
            k[l+1]='\0';
            return;
        }
        if(flag==0)
        {
            for(i=0;i<l/2;i++)
            {
                if(k[i]>k[l-1-i])
                    flag=1;
                else if(k[i]<k[l-1-i])
                    flag=-1;
                k[l-1-i]=k[i];
            }
        }
        if(flag==-1 || flag==0)
        {
            if(l%2==0)
                temp=l/2-1;
            else
                temp=l/2;
                t=0;
            while(k[temp-t]=='9')
            {
                k[temp-t] = '0';
                k[l-1-temp+t] = '0';
                t ++;
            }
            k[temp-t]++;
            k[l-1-temp+t]=k[temp-t];
        }
        return;
    }
