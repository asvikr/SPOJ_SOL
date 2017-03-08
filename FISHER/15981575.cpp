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
int dp[51][1002];
int cost[51][51],toll[51][51];
int n,t;
int solve(int cur,int avail)
{
    if(avail<0) return inf;
    if(cur==n-1 && avail>=0) return 0;
    if(dp[cur][avail]!=-1) return dp[cur][avail];
    int &ret=dp[cur][avail];
    ret=inf;
    for(int i=0;i<n;i++){
        if(cur==i) continue;
        ret=min(ret,solve(i,avail-cost[cur][i])+toll[cur][i]);
    }
    return ret;
}
int main()
{
    while(true){
    memset(dp,-1,sizeof(dp));
    n=read();t=read();
    if(n==0 && t==0) return 0;
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cost[i][j]=read();
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) toll[i][j]=read();
     int k=solve(0,t);
     int st=1,en=t;
     while(st<en){
        int mid=(st+en)/2;
        memset(dp,-1,sizeof(dp));
        if(solve(0,mid)>k)
            st=mid+1;
        else en=mid;
     }
     printf("%d %d\n",k,st);
    }
    return 0;
}
