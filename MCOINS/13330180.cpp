#include<bits/stdc++.h>
using namespace std;
int dp[1000005];
int main()
{
    int k,l,m;
    scanf("%d %d %d",&k,&l,&m);
    k=min(k,l);
    l=max(k,l);
    dp[1]=1;
    for(int i=2;i<=1000000;i++)
    {
       if(i-k<0)
        dp[i]=(dp[i-1]==0)?1:0;
       else if((i-k>=0) && (i-l<0))
        dp[i]=(dp[i-1]==0 || dp[i-k]==0)?1:0;
       else
        dp[i]=(dp[i-1]==0 || dp[i-k]==0 || dp[i-l]==0)?1:0;
        //printf("%d",dp[i]);
    }
    int x;
    while(m--)
    {
        scanf("%d",&x);
        printf("%c",dp[x]==1?'A':'B');
    }
    return 0;
}
