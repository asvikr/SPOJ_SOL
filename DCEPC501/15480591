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
LL dp[N],a[N];
int n;
LL solve(int l)
{
    if(l>n-1) return 0;
    if(dp[l]!=-1) return dp[l];
    LL one=0,two=0,three=0;
    one=a[l];
    if(l+1<n)
        two=one+a[l+1];
    if(l+2<n) three=two+a[l+2];
    dp[l]=max(one+solve(l+2),max(two+solve(l+4),three+solve(l+6)));
    return dp[l];
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        memset(dp,-1,sizeof(dp));
        LL sum=0;
        for(int i=0;i<n;i++) scanf("%lld",&a[i]),sum+=a[i];
        if(n<=3){
            printf("%lld\n",sum);
            continue;
        }
        printf("%lld\n",solve(0));
    }
    return 0;
}
