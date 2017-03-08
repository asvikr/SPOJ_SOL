#include<bits/stdc++.h>
using namespace std;
int sum[105];
 int a[102];
 int dp[102][102];
 int solve(int l,int r)
 {
     if(l==r)
        return 0;
     if(dp[l][r]!=-1)
        return dp[l][r];
     int ret=dp[l][r];
     for(int k=l;k<r;k++)
     {
         int temp=solve(l,k)+solve(k+1,r)+((sum[k]-sum[l-1])%100)*((sum[r]-sum[k])%100);
         if(ret==-1 || ret>temp)
            ret=temp;
     }
     return (dp[l][r]=ret);
 }
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF)
    {
        sum[0]=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            sum[i]=sum[i-1]+a[i];
        }

       memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(1,n));

    }
    return 0;
}
