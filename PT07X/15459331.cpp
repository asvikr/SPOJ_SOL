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
const int N=100005;
vector<int> V[N];
int dp[N][2];
void dfs(int cur,int prev)
{
    int sum1=0;
    int sum2=1;
    for(int i=0;i<V[cur].size();i++){
        if(V[cur][i]!=prev){
            dfs(V[cur][i],cur);
            sum1+=dp[V[cur][i]][1];
            sum2+=min(dp[V[cur][i]][0],dp[V[cur][i]][1]);
        }
    }
    dp[cur][0]=sum1;
    dp[cur][1]=sum2;
}
int main()
{
    int n,u,v;
    scanf("%d",&n);
    for(int i=1;i<n;i++){
        scanf("%d %d",&u,&v);
        V[u].pb(v);
        V[v].pb(u);
    }
    dfs(1,-1);
    printf("%d\n",min(dp[1][0],dp[1][1]));
    return 0;
}

