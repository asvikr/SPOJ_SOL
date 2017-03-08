#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
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
	int ret = 0;
	int c = getchar_unlocked();

	while(c<'0' || c>'9')
		c = getchar_unlocked();
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
const int N=1005;
int dp[N][N];
int a[N];
int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        memset(dp,0,sizeof(dp));
        int n,k;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        for(int i=0;i<=n;i++){
            for(int w=0;w<=k;w++){
                if(w==0 || i==0) dp[i][w]=0;
                else if(w>=a[i-1]){
                    if(i>1)
                    dp[i][w]=max(dp[i-2][w-a[i-1]]+a[i-1],dp[i-1][w]);
                    else dp[i][w]=dp[i-1][w-a[i-1]]+a[i-1];
                }
                else
                {
                    dp[i][w]=dp[i-1][w];
                }
            }
        }
        printf("Scenario #%d: %d\n",tt,dp[n][k]);
    }
    return 0;
}
