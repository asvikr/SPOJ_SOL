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
int dp[605][605];
int chk[605][605];
int minh,minw;
int solve(int w,int h)
{
    if(w<minw || h<minh) return w*h;
    if(chk[w][h]==1) return 0;
    if(dp[w][h]!=-1) return dp[w][h];
    int &ret=dp[w][h];
    ret=inf;
    for(int i=1;i<w;i++){
        ret=min(ret,solve(w-i,h)+solve(i,h));
    }
    for(int i=1;i<h;i++){
        ret=min(ret,solve(w,h-i)+solve(w,i));
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        memset(chk,0,sizeof(chk));
        int w,h,n;
        scanf("%d %d",&w,&h);
        scanf("%d",&n);
        minh=inf,minw=inf;
        int x,y;
        for(int i=0;i<n;i++){
            scanf("%d %d",&x,&y);
            if(x<minw) minw=x;
            if(y<minh) minh=y;
            chk[x][y]=1;
        }
        int ans=solve(w,h);
        printf("%d\n",ans);
    }
    return 0;
}
