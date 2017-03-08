#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 100000000
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
	if(c=='-') temp=-1;
	while(c<'0' || c>'9'){
		c = getchar_unlocked();
		if(c=='-') temp=-1;
	}
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret*temp;
}
const int N=100005;
 int n;
 pair<int,int> a[N];
 int dp[N][2];
 void solve()
 {
     memset(dp,0,sizeof(dp));
     dp[0][1]=1;
     vector<int> V;
     V.pb(a[0].f);
     for(int i=1;i<n;i++){
        dp[i][0]=dp[i-1][0]+dp[i-1][1];
        if(dp[i][0]>=M) dp[i][0]-=M;
        int pos=upper_bound(V.begin(),V.end(),a[i].sc)-V.begin();
        --pos;
        if(pos<0) dp[i][1]=1;
        else
        {
            dp[i][1]=(1+dp[pos][0]+dp[pos][1]);
            if(dp[i][1]>=M) dp[i][1]-=M;
        }
        V.pb(a[i].f);
     }
     int ans=dp[n-1][0]+dp[n-1][1];
     if(ans>=M) ans-=M;
     printf("%08d\n",ans);
 }
int main()
{
   while(true){
    n=read();
    if(n==-1) break;
    for(int i=0;i<n;i++){
        a[i].sc=read();a[i].f=read();
    }
    sort(a,a+n);
    solve();
   }
   return 0;
}
