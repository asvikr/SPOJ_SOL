#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
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
int a[25][25];
int dp[25][25];
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int x,y;
    scanf("%d %d",&x,&y);
    for(int i=1;i<=n;i++) for(int j=1;j<=m;j++) scanf("%d",&a[i][j]);
    dp[x][y]=0;
    for(int i=y+1;i<=m;i++) dp[x][i]=dp[x][i-1]+a[x][i];
    for(int i=x+1;i<=n;i++) dp[i][y]=dp[i-1][y]+a[i][y];
    for(int i=x+1;i<=n;i++){
        for(int j=y+1;j<=m;j++){
            dp[i][j]=min(dp[i-1][j],dp[i][j-1])+a[i][j];
        }
    }
    int ans=a[x][y]-dp[n][m];
    if(ans>=0) printf("Y %d\n",ans);
    else printf("N\n");
    return 0;
}
