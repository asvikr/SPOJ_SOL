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
double dp[551][3301];
double solve(int n,int k)
{
    if(n==1 && k>6) return 0;
    if(k<0) return 0;
    if(n==1 && k<=6 && k>=1) return (double)1/6;
    if(dp[n][k]!=-1) return dp[n][k];
    dp[n][k]=0;
    for(int i=1;i<7;i++){
        dp[n][k]+=(double)solve(n-1,k-i)/6.0;
    }
   // cout<<dp[n][k]<<endl;
    return dp[n][k];
}
int main()
{
    for(int i=1;i<7;i++) dp[1][i]=(double)1/6;
    for(int i=2;i<=550;i++){
        for(int j=i;j<=6*i;j++){
            for(int k=1;k<7;k++)
            dp[i][j]+=dp[i-1][j-k]/6.0;
        }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        scanf("%d %d",&n,&k);
        if(k<n || n>550 || k>3300) printf("0\n");
        else
        {
            double ans=dp[n][k]*100;
            printf("%d\n",(int)ans);
        }
    }
    return 0;
}
