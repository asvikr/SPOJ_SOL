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
int a[N];
int dp[N][N];
int solve(int l,int r)
{
    if(l==r) return a[l];
    if(l>r) return 0;
    if(dp[l][r]!=-1) return dp[l][r];
    int val1,val2;
    if(a[r]>a[l+1])
        val1=a[l]+solve(l+1,r-1);
    else
        val1=a[l]+solve(l+2,r);
    if(a[l]>=a[r-1])
        val2=a[r]+solve(l+1,r-1);
    else
        val2=a[r]+solve(l,r-2);
    return (dp[l][r]=max(val1,val2));
}
int main()
{
    int c=1;
    while(1){
    int n;
    memset(dp,-1,sizeof(dp));
    scanf("%d",&n);
    if(n==0) break;
    int sum=0;
    for(int i=0;i<n;i++) {
        scanf("%d",&a[i]);
        sum+=a[i];
    }
    int ans=solve(0,n-1);
    printf("In game %d, the greedy strategy might lose by as many as %d points.\n",c++,2*ans-sum);
    }
    return 0;
}
