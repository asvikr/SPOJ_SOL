#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int a[10005];
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        int n;
        scanf("%d",&n);
        LL dp[n+1];
        dp[0]=0;
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        dp[1]=a[1];
        for(int i=2;i<=n;i++)
        {
            dp[i]=max(dp[i-1],dp[i-2]+a[i]);
        }
        printf("Case %d: %lld\n",k,dp[n]);
    }
    return 0;
}
