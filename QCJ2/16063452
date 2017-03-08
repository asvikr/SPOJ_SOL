#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 761238923
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
LL dp[105][105];
int n;
LL solve(int cur,int idx,int cur_sum)
{
	if(cur_sum==n && idx==n+1) return 1;
	else if(idx==n+1) return 0;
	LL &ans=dp[idx][cur_sum];
	if(ans!=-1) return ans;
	ans=0;
	for(int i=0;i<=idx-cur_sum;i++){
		ans+=solve(i,idx+1,cur_sum+i);
		if(ans>=M) ans-=M;
	}
	return ans;
}
int main()
{
	while(1){
		memset(dp,-1,sizeof(dp));
		scanf("%d",&n);
		if(n==0) return 0;
		LL ans=solve(0,1,0);
		printf("%lld\n",ans);
	}
	return 0;
}
