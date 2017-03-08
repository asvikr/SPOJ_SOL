#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
LL max(LL a,LL b,LL c){return max(a,max(b,c));}
inline LL power(LL x,LL y)
{
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        y/=2;
    }
    return ans;
}
inline int read()
{
	int ret = 0,temp=1;
	int c = getchar_unlocked();
	while(c<'0' || c>'9'){
		c = getchar_unlocked();
	}
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
LL dp[105][305][105];
int n,k,p;
//memoization gets TLE
LL solve(int maxi,int id,int up)
{
    if(id==n && up==p+1) return 1;
    if(id==n && up!=p+1) return 0;
    if(dp[maxi][id][up]!=-1) return dp[maxi][id][up];
    LL cnt=0;
    for(int i=1;i<=k;i++){
        if(maxi<i)
        cnt+=solve(i,id+1,up+1);
        else cnt+=solve(maxi,id+1,up);
        if(cnt>=M) cnt-=M;
    }
    return dp[maxi][id][up]=cnt;
}
LL sum[101][301][101];
int main()
{
    // dp
   for(int i=1;i<301;i++){
    dp[0][i][0]=1;
    sum[0][i][0]=sum[0][i-1][0]+1;
   }
   for(int i=1;i<101;i++){
    for(int j=1;j<301;j++){
        for(int k=0;k<101;k++){
            dp[i][j][k]=dp[i-1][j][k]*j;
            if(j!=1){
                dp[i][j][k]+=sum[i-1][j-1][k-1];
                //for(int l=1;l<j;l++)
                  //  dp[i][j][k]+=dp[i-1][l][k-1];
            }
            sum[i][j][k]=sum[i][j-1][k]+dp[i][j][k];
            if(sum[i][j][k]>=M) sum[i][j][k]%=M;
            dp[i][j][k]%=M;
        }
    }
   }
   int t;
   t=read();
   while(t--){
   // memset(dp,-1,sizeof(dp));
    n=read();k=read();p=read();
  //  LL ans=solve(0,0,0);
    LL ans=0;
    for(int i=1;i<=k;i++)
        ans+=dp[n-1][i][p];
    printf("%lld\n",ans%M);
   }
   return 0;
}

