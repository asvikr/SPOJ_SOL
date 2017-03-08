#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
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
int sum[2][505][505];
int dp[505][505];
int n,m;
void solve()
{
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            int tmp1=sum[0][i][j];
            int tmp2=sum[1][i][j];
            if(j>0) tmp1+=dp[i][j-1];
            if(i>0) tmp2+=dp[i-1][j];
            dp[i][j]=max(tmp1,tmp2);
        }
    }
    printf("%d\n",dp[n-1][m-1]);
}
int main()
{
    while(1){
    n=read();m=read();
    if(n==0 && m==0) break;
    int x;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                x=read();
                sum[1][i][j]=x;
                if(j>0) sum[1][i][j]+=sum[1][i][j-1];
            }
        }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
                x=read();
                sum[0][i][j]=x;
                if(i>0) sum[0][i][j]+=sum[0][i-1][j];
            }
        }
        solve();
    }
    return 0;
}

