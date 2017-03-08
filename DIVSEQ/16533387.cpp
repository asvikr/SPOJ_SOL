#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 1000000009
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
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
const int N=1005;
LL dp[N][N];
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    for(int i=1;i<=k;i++) dp[1][i]=1;

    for(int i=2;i<=n;i++){
      for(int j=1;j<=k;j++){
          for(int p=2;;p++){
            if(j*p>k) break;
           // printf("%d %d\n",j,j*p);
            dp[i][j]+=dp[i-1][j*p];
            if(dp[i][j]>=M) dp[i][j]-=M;
          }
          int sq=sqrt(j);
          for(int p=1;p<=sq;p++){
            if(j%p==0){
              //printf("%d %d\n",j,p);
                dp[i][j]+=dp[i-1][p];
                if(dp[i][j]>=M) dp[i][j]-=M;
            }
            if((j%(j/p)==0) && (p!=j/p)){
             // printf("%d %d\n",j,j/p);
              dp[i][j]+=dp[i-1][j/p];
                if(dp[i][j]>=M) dp[i][j]-=M;
            }
          }
      }
    }
    LL ans=0;
    for(int i=1;i<=k;i++){
      ans+=dp[n][i];
      //printf("%lld ",dp[n][i]);
      if(ans>=M) ans-=M;
    }
    printf("%lld\n",ans);
    return 0;
}
