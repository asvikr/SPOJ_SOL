#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL modInvere(LL a,LL b)
{
   LL x=1,y=0,q,r,m,n;
   LL xLast=0,yLast=1;
   while(a!=0)
   {
        q=b/a;
        r=b%a;
       m=xLast-q*x;
       n=yLast-q*y;
       xLast=x;
       yLast=y;
       x=m;
       y=n;
       b=a;
       a=r;
   }
   return xLast;
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
                temp=(modInvere(i,p)+p)%p;
                ans=(ans*temp)%p;
            }
            printf("%lld\n",ans+p);
        }
    }
    return 0;
}
