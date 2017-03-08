#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL mod_pow(LL a,LL b,LL m)
{
    LL x=1,y=a;
    while(b>0)
    {
        if(b&1)
            x=(y*x)%m;
            y=(y*y)%m;
        b/=2;
    }
    return x;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n,p;
        scanf("%lld %lld",&n,&p);
        if(n>=p)
        {
            printf("0\n");
            continue;
        }
        else
        {
            LL ans=-1,temp;
            for(int i=n+1;i<p;i++)
            {
                temp=mod_pow(i,p-2,p);
                ans=(ans*temp)%p;
            }
            printf("%lld\n",ans+p);
        }
    }
    return 0;
}
