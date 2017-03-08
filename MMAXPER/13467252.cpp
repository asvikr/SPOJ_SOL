#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    pair<int,int> a[1005];
    int x,y;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        a[i].first=x;
        a[i].second=y;
    }
    int dp[n][2];
    dp[0][0]=a[0].first;
    dp[0][1]=a[0].second;
    for(int i=1;i<n;i++)
    {
        dp[i][0]=a[i].first+max(dp[i-1][0]+abs(a[i].second-a[i-1].second),dp[i-1][1]+abs(a[i].second-a[i-1].first));
        dp[i][1]=a[i].second+max(dp[i-1][0]+abs(a[i].first-a[i-1].second),dp[i-1][1]+abs(a[i].first-a[i-1].first));
    }
    printf("%d\n",max(dp[n-1][0],dp[n-1][1]));
    return 0;
}
