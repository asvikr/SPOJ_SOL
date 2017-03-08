#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int LL;
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
LL dp[105][105];
const int N=105;
const int K=105;
int main()
{
    //freopen("output1.txt","w",stdout);
    dp[0][0]=1;
    dp[1][0]=2;
    dp[1][1]=0;
    for(int i=2;i<101;i++) dp[i][0]=dp[i-1][0]+dp[i-2][0];
    for(int i=2;i<N;i++){
       for(int j=1;j<=i-1;j++){
          for(int k=1;k<=i;k++){
                int c;
                if(k<3) c=0;
                else c=k-2;
                if(j-c<0) break;
                dp[i][j]+=dp[i-k][j-c];
          }
          if(i-1==j) dp[i][j]+=1;
        //  printf("%d %d %d\n",i,j,dp[i][j]);
       }
    }
    int t;
    scanf("%d",&t);
    while(t--){
        int id,n,k;
        scanf("%d %d %d",&id,&n,&k);
        printf("%d %lld\n",id,dp[n][k]);
    }
    return 0;
}
