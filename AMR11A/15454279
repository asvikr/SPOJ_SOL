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
const int N=505;
int dp[N][N],a[N][N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int r,c;
        scanf("%d %d",&r,&c);
        for(int i=0;i<r;i++) for(int j=0;j<c;j++) scanf("%d",&a[i][j]);
        for(int i=c;i>=0;i--) dp[r][i]=INT_MIN;
        for(int i=0;i<=r;i++) dp[i][c]=INT_MIN;
        for(int i=r-1;i>=0;i--){
            for(int j=c-1;j>=0;j--){
                if(i==r-1 && j==c-1) dp[i][j]=0;
                else
                {
                    dp[i][j]=max(dp[i+1][j],dp[i][j+1])+a[i][j];
                    if(dp[i][j]>=0) dp[i][j]=0;
                }
            }
        }
        //printf("%d ",dp[0][0]);
        printf("%d\n",abs(dp[0][0])+1);
    }
    return 0;
}

