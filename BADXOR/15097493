#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define M 100000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
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
LL dp[1025][1025];
int b[1025];
int main()
{
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        memset(dp,0,sizeof(dp));
        int a[n];
        for(int i=0;i<n;i++) scanf("%d",&a[i]);
        int x;
        memset(b,0,sizeof(b));
        for(int i=0;i<m;i++){
            scanf("%d",&x);
            b[x]=1;
        }
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=0;j<1024;j++){
                dp[i][j]=dp[i-1][j]+dp[i-1][j^a[i-1]];
                if(dp[i][j]>=M) dp[i][j]-=M;
            }
        }
        LL ans=0;

            for(int j=0;j<1024;j++){
                if(b[j]==0 && dp[n][j]!=0){
                    ans+=dp[n][j];
                    if(ans>=M) ans-=M;
                }
            }

        printf("Case %d: %lld\n",tt,ans);
    }
    return 0;
}

