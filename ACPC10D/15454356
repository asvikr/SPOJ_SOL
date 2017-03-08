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
const int N=123456;
LL a[N][3];
LL dp[N][3];
int main()
{
    int c=1;
    while(1){
        int n;
        scanf("%d",&n);
        if(n==0) break;
        for(int i=0;i<n;i++) for(int j=0;j<3;j++) scanf("%lld",&a[i][j]);
        dp[0][0]=inf,dp[0][1]=a[0][1],dp[0][2]=a[0][1]+a[0][2];
        for(int i=1;i<n;i++){
            for(int j=0;j<3;j++){
                if(j==0) dp[i][j]=min(dp[i-1][j],dp[i-1][j+1])+a[i][j];
                else if(j==1) dp[i][j]=min(min(dp[i-1][j],dp[i-1][j-1]),min(dp[i][j-1],dp[i-1][j+1]))+a[i][j];
                else dp[i][j]=min(min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+a[i][j];
            }
        }
        printf("%d. %lld\n",c++,dp[n-1][1]);
    }
    return 0;
}

