#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define M 1000000007
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
int main()
{
  int t=read();
  for(int tt=1;tt<=t;tt++){
    printf("Case %d: ",tt);
    int n=read();
    if(n==3){
      printf("2 3\n");
      continue;
    }
    else if(n==2){
      printf("1 2\n");
      continue;
    }
    if(n&1) n-=1;
    printf("%d %d\n",n/2,n);
  }
}
