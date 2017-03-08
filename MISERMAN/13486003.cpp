#include<bits/stdc++.h>
using namespace std;
int dp[105][105];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int a[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            scanf("%d",&a[i][j]);
    }
     for(int i=0;i<=m+1;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=999;
        dp[i][m+1]=999;
    }
    int ans=INT_MAX;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i-1][j+1]))+a[i-1][j-1];
            //printf("%d ",dp[i][j]);
            if(i==n)
                ans=min(ans,dp[i][j]);
        }
   // printf("\n");
    }
    printf("%d\n",ans);
    return 0;
}
