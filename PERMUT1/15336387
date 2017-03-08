#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int dp[13][100];
int solve(int n,int k)
{
    if(n==0) return 0;
    if(k==0) return 1;
    if(dp[n][k]!=-1) return dp[n][k];
    int val=0;
    for(int i=0;i<n && k-i>=0;i++){
        val+=solve(n-1,k-i);
    }
    return (dp[n][k]=val);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        memset(dp,-1,sizeof(dp));
        printf("%d\n",solve(n,k));
    }
    return 0;
}
