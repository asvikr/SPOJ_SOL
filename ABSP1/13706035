#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        LL a[n+1];
        LL sum[n+1];
        LL ans=0;
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }
        for(int i=1;i<=n;i++)
        {
            ans+=(sum[n]-sum[i])-(a[i]*(n-i));
        }
        printf("%lld\n",ans);
    }
    return 0;
}
