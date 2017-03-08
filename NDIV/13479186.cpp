#include<bits/stdc++.h>
using namespace std;
int prime[32000];
int chk[32000];
int cnt=1;
void sieve()
{
    for(int i=3;i<=180;i+=2)
    {
        if(!chk[i])
        {
            for(int j=i*i;j<=32000;j+=i)
                chk[j]=1;
        }
    }
    prime[0] = 2;
    int j=1;
    for(int i=3;i<=32000;i+=2)
    {
        if(!chk[i]){
            prime[cnt++]=i;
        }
    }
}
int main()
{
    int a,b,n;
    memset(chk,0,sizeof(chk));
    sieve();
    scanf("%d %d %d",&a,&b,&n);
    int cnt1=0,sum=1,ans=0;
    for(int i=a;i<=b;i++)
    {
        int p=i;
        int k=0;
            for(int j=prime[k];j*j<=p;j=prime[++k])
            {
                cnt1=0;
                //printf("%d\n",prime[j]);
                while(p%j==0)
                {
                    cnt1++;
                    p/=j;
                }
                 sum=sum*(cnt1+1);
            }
            if(p!=1)
                sum=sum*2;
            if(sum==n)
                ans++;
            sum=1;

    }
    printf("%d\n",ans);
    return 0;
}
