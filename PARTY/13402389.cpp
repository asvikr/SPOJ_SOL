#include<bits/stdc++.h>
using namespace std;
int ans1=0;
int fun(int W,int wt[],int val[],int n)
{
   int ans=0;
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=W;j++)
        {
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(wt[i-1]<=j)
            {
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
            else
                dp[i][j]=dp[i-1][j];
            if(dp[i][j]>=ans)
            {
                if(dp[i][j]==ans)
                    ans1=min(j,ans1);
                else
                ans1=j;
                ans=dp[i][j];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int W,n;
    while(1)
    {
    scanf("%d %d",&W,&n);
    if(W==0 && n==0)
        return 0;
    int wt[105],val[105];
    for(int i=0;i<n;i++)
        scanf("%d %d",&wt[i],&val[i]);
    printf("%d %d\n",ans1,fun(W,wt,val,n));
    ans1=0;
    }
    return 0;
}
