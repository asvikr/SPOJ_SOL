#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define M 1000000007
LL fact[2000005];
LL power(LL a,LL b)
{
    LL ans=1;
    while(b>0)
    {
        if(b&1)
            ans=(ans*a)%M;
        a=(a*a)%M;
        b/=2;
    }
    return ans%M;
}
void solve()
{
    fact[0]=1;
    for(int i=1;i<=2000000;i++)
        fact[i]=((fact[i-1]%M)*i)%M;
}
int main()
{
    int t;
    //printf("%lld %lld\n",power(2,5),power(5,M-2));
    scanf("%d",&t);
    solve();
   // printf("%lld %lld\n",fact[4],fact[100000]);
    while(t--)
    {
        LL x,y;
        scanf("%lld %lld",&x,&y);
        LL ans=fact[x+y];
        //printf("%lld\n",ans);
        ans=(((ans*power(fact[x],M-2))%M)*(power(fact[y],M-2)))%M;
        printf("%lld\n",ans);
    }
    return 0;
}
