#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define M 1000000007
int chk[10005];
int prime[10000];
int cnt=1;
void sieve()
{
    prime[0]=2;
    for(int i=3;i<=sqrt(10001);i+=2)
    {
        if(chk[i]==0)
        for(int j=i*i;j<10000;j+=i*2)
        {
            chk[j]=1;
        }
    }
    for(int i=3;i<10000;i+=2)
    {
        if(chk[i]==0)
            prime[cnt++]=i;
    }
}
int main()
{
    int t;
    sieve();
    int sz=sizeof(prime)/sizeof(prime[0]);
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        LL ans=1;
        for(int i=0;i<cnt;i++)
        {
            LL k=1;
            while(k<=n)
            {
                k=k*prime[i];
            }
            k/=prime[i];
            //printf("%lld\n",k);
            ans=(ans*k)%M;
        }
        printf("%lld\n",ans%M);
    }
    return 0;
}
