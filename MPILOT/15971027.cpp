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
#define inf (int)(1e+9)
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
const int N=10005;
int A[N],C[N];
LL dp[N][N];
/*dp[i][j] means the least cost after assigning pilots from 1 to i and you have j
assistants who are not yet having captains in their planes ( of course j <= i ) when you compute dp[i][j]
you have two situations that lead to it , either you had j+1 assistants and you made the
 i'th pilot a captain then he took one of the assistants available, or you had j-1 assistants and you made the i'th p
 ilot an assistant so he will be added to the j-1 assistants so the formula of dp is:
dp[i][j]=min(dp[i-1][j+1]+B[i],dp[i-1][j-1]+A[i])*/
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d %d",&C[i],&A[i]);
    }
    dp[1][0]=inf;
    for(int i=1;i<=n;i++) dp[0][i]=inf;
    for(int i=1;i<=n;i++) for(int j=i+1;j<=n;j++) dp[i][j]=inf;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            int cap=i-j;
            int c1=i-1-j;
            if(c1>j) dp[i-1][j]=inf;
            if(cap>j) dp[i][j]=inf;
            else dp[i][j]=min(dp[i-1][j]+C[i],dp[i-1][j-1]+A[i]);
           // printf("%d %d %d\n",i,j,dp[i][j]);
        }
    }
    printf("%d\n",dp[n][n/2]);
    return 0;
}
