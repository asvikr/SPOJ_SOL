#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define M 1000000007
LL dp[100005];
void solve()
{
    dp[1]=1;
    LL temp=1;
    for(int i=2;i<=100000;i++)
    {
        dp[i]=dp[i-1]*2+temp;
        if(dp[i]>=M)
            dp[i]%=M;
        temp=temp*2;
        if(temp>=M)
            temp%=M;
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    solve();
    for(int i=1;i<=t;i++)
    {
        LL n;
        scanf("%lld",&n);
        printf("Case %d: %lld\n",i,dp[n]);
    }
    return 0;
}
