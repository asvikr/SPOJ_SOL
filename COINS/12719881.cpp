#include<iostream>
#include<cstdio>
typedef long long int LL;
using namespace std;
LL dp[32][25];
LL solve(LL n,LL l,LL r)
{
    if(n<12)
        return n;
    LL a,b,c;
    if(dp[l][r]!=0)
        return dp[l][r];
    a=solve(n/2,l+1,r);
    b=solve(n/3,l,r+1);
    c=solve(n/4,l+2,r);
    dp[l][r]=a+b+c;
    return dp[l][r];
}
int main()
{
    LL n;
    while(scanf("%lld",&n)!=EOF)
    {
    for(int i=0;i<32;i++)
        for(int j=0;j<25;j++)
        dp[i][j]=0;
    LL cnt=solve(n,0,0);
    printf("%lld\n",cnt);
    }
    return 0;
}
