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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
int dp[1234][1234];
int solve(int h,int a,int prev)
{
    if(h<=0 || a<=0){
        return 0;
    }
    int &ret=dp[h][a];
    if(ret!=-1) return ret;
    ret=0;
    if(prev==0){
        if(h>5 && a>10) ret=solve(h-5,a-10,1)+1;
        if(h>20) ret=max(ret,solve(h-20,a+5,2)+1);
    }
    else if(prev==1)
    {
        ret=solve(h+3,a+2,0)+1;
        if(h>20) ret=max(ret,solve(h-20,a+5,2)+1);
    }
    else
    {
        ret=solve(h+3,a+2,0)+1;
        if(h>5 && a>10) ret=max(ret,solve(h-5,a-10,1)+1);
    }
    return ret;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int h,a;
        scanf("%d %d",&h,&a);
        memset(dp,-1,sizeof(dp));
        int ans=0;
        for(int i=0;i<3;i++){
            ans=max(ans,solve(h,a,i));
            memset(dp,-1,sizeof(dp));
        }
        printf("%d\n",ans);
    }
    return 0;
}
