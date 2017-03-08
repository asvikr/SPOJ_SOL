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
const int N=205;
int cnt[N],dp[N];
char str[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        memset(cnt,0,sizeof(cnt));
        memset(dp,0,sizeof(dp));
        scanf("%d",&n);
        scanf("%s",str);
        for(int i=1;i<=n;i++)
            cnt[i]=cnt[i-1]+(str[i-1]-'0');
        for(int i=1;i<=n;i++){
            dp[i]=dp[i-1];
            for(int j=i;j>=1;j--){
                if(cnt[i]-cnt[j-1]>(i-j+1)/2){
                    dp[i]=max(dp[i],dp[j-1]+(i-j+1));
                }
            }
           // printf("%d ",dp[i]);
        }
        printf("%d\n",dp[n]);
    }
    return 0;
}
