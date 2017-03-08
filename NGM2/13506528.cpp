#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL gcd(LL a,LL b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
LL lcm(LL a,LL b)
{
    return (a*b)/gcd(a,b);
}
int main()
{
    int n,k,a[16];
    scanf("%d %d",&n,&k);
    for(int i=0;i<k;i++)
    {
        scanf("%d",&a[i]);
    }
    LL ans=0;
    int p=1<<k;
    int cnt;
    for(int i=1;i<p;i++)
    {
        cnt=0;
        LL lc=1;
        for(int j=0;j<k;j++)
        {
            if(i&(1<<j))
            {
                cnt++;
                lc=lcm(lc,a[j]);
                if(lc>1000000000)
                    break;
            }
        }
        if(cnt%2)
            ans+=n/lc;
        else
            ans-=n/lc;
    }
    printf("%lld\n",n-ans);
    return 0;
}
