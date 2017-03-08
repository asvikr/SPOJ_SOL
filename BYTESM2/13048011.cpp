#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<sstream>
using namespace std;
int a[105][105];
int dp[105][105];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int h,w;
    scanf("%d %d",&h,&w);
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
            scanf("%d",&a[i][j]);
    }
    for(int i=0;i<=h;i++)
   {
    dp[i][0]=0;
    dp[i][w+1]=0;
   }
   for(int i=0;i<=w;i++)
    dp[0][i]=0;
   int ans=0;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j+1],dp[i-1][j]))+a[i][j];
           if(i==h)
           {
                ans=max(ans,dp[i][j]);
               // printf("%d ",dp[i][j]);
           }
        }
    }
    printf("%d\n",ans);
}
return 0;
}
