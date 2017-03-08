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
#define inf (int)(1e+9)
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
int k,n,r;
struct node
{
    int v,w,m;
};
vector<node> V[105];
int dp[105][10005];
int solve(int i,int rem)
{
    if(rem<0) return inf;
    if(i==n-1 && rem>=0) return 0;
    if(dp[i][rem]!=-1) return dp[i][rem];
    int &ret=dp[i][rem];
    ret=inf;
    for(int j=0;j<V[i].size();j++){
        ret=min(ret,solve(V[i][j].v,rem-V[i][j].m)+V[i][j].w);
        //printf("%d\n",ret);
    }
    return ret;
}
int main()
{
    int t;
    t=read();
    while(t--){
        k=read();n=read();r=read();
        for(int i=0;i<=n;i++){
        V[i].clear();
        for(int j=0;j<=k;j++) dp[i][j]=-1;
        }

        int u,v,w,m;
        while(r--){
            u=read();v=read();w=read();m=read();
            --u,--v;
            V[u].pb({v,w,m});
        }
        int ans=solve(0,k);
        printf("%d\n",(ans==inf)?-1:ans);
    }
    return 0;
}

