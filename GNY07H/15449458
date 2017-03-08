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
LL x[1005],a[1005],b[1005];
int main()
{
    x[0]=1;a[0]=b[0]=0;
    x[1]=a[1]=b[1]=1;
    for(int i=2;i<=1000;i++){
        x[i]=x[i-1]+x[i-2]+2*a[i-1]+b[i-1];
        a[i]=x[i-1]+a[i-1];
        b[i]=x[i-1]+b[i-2];
    }
    int t;
    scanf("%d",&t);
    for(int tt=1;tt<=t;tt++){
        int n;
        scanf("%d",&n);
        printf("%d %lld\n",tt,x[n]);
    }
    return 0;
}
