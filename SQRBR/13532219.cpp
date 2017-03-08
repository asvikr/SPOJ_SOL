#include<bits/stdc++.h>
using namespace std;
int dp[50][50];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        memset(dp,0,sizeof(dp));
        set<int> S;
        int x;
        for(int i=0;i<k;i++)
        {
            scanf("%d",&x);
            S.insert(x);
        }
        for(int i=1;i<=2*n;i++)
        {
            for(int j=0;j<=i;j++)
            {
                if(i==1)
                {
                    if(j==1)
                        dp[i][j]=1;
                    else
                       dp[i][j]=0;
                }
                else
                {
                    if(S.find(i)!=S.end())
                    {
                        dp[i][j]=((j==0)?0:dp[i-1][j-1]);
                    }
                    else
                    {
                        dp[i][j]=dp[i-1][j+1]+((j==0)?0:dp[i-1][j-1]);
                    }
                }
            }
        }
        printf("%d\n",dp[2*n][0]);
    }
}
