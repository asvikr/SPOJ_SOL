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
#define inf (int)(2e+9)
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
const int N=205;
int a[N],n;
int dp[N][N];
int solve(int id,int bl,int wh)
{
    if(id==n+2) return 0;
    int &ret=dp[bl][wh];
    if(ret!=-1) return ret;
    ret=solve(id+1,bl,wh)+1;
    if(a[id]>a[bl]) ret=min(ret,solve(id+1,id,wh));
    if(a[id]<a[wh]) ret=min(ret,solve(id+1,bl,id));
    return ret;
}
int main()
{
    while(1){
        memset(dp,-1,sizeof(dp));
        scanf("%d",&n);
        if(n==-1) return 0;
        for(int i=2;i<n+2;i++) scanf("%d",&a[i]);
        a[0]=-1,a[1]=inf;
        printf("%d\n",solve(2,0,1));
    }
    return 0;
}
