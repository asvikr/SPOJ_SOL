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
#define inf (int)(1e+7)
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
int dp[105],p[105],n,k;
/*int solve(int wt)
{
    if(wt<0) return inf;
    if(wt==0) return 0;
    if(dp[wt]!=-1) return dp[wt];
    int ret=inf;
    for(int i=1;i<=k;i++){
        if(p[i]!=-1)
        ret=min(ret,solve(wt-i)+p[i]);
    }
    return dp[wt]=ret;
}*/
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,0,sizeof(dp));
        scanf("%d %d",&n,&k);
        for(int i=1;i<=k;i++){
            scanf("%d",&p[i]);
            dp[i]=inf;
        }
      /*  int ans=solve(k);
        if(ans==inf) printf("-1\n");
        else printf("%d\n",ans);*/
        dp[0]=0;
        for(int i=1;i<=k;i++){
            if(p[i]!=-1){
                for(int j=i;j<=k;j++){
                    dp[j]=min(dp[j],dp[j-i]+p[i]);
                }
            }
        }
        if(dp[k]==inf) printf("-1\n");
        else printf("%d\n",dp[k]);
    }
}
