#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 100000
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
LL mulmod(LL a,LL b) {
   long double res = a;
   res *= b;
   LL c = (LL)(res / M);
   a *= b;
   a -= c * M;
   a %= M;
   if (a < 0) a += M;
   return a;
}
char str[205];
LL dp[205][205];
bool vis=false;
LL solve(int l,int r)
{
  if(l>r) return 1;
  LL &ret=dp[l][r];
  if(ret!=-1) return ret;
  ret=0;
  int val=1;
  for(int i=l+1;i<=r;i+=2){
    if(str[l]=='{' && str[i]=='}') val=1;
    else if(str[l]=='(' && str[i]==')') val=1;
    else if(str[l]=='[' && str[i]==']') val=1;
    else if(str[l]=='(' && str[i]=='?') val=1;
    else if(str[l]=='{' && str[i]=='?') val=1;
    else if(str[l]=='[' && str[i]=='?') val=1;
    else if(str[l]=='?' && str[i]==')') val=1;
    else if(str[l]=='?' && str[i]=='}') val=1;
    else if(str[l]=='?' && str[i]==']') val=1;
    else if(str[l]=='?' && str[i]=='?') val=3;
    else val=0;
    ret+=val*1LL*solve(l+1,i-1)*solve(i+1,r);
    if(ret>M){
    ret%=M;
    vis=true;
  }
  }
  return ret;
}
int main()
{
  memset(dp,-1,sizeof(dp));
  int n;
  scanf("%d",&n);
  scanf("%s",str);
  int l=strlen(str);
  LL ans=solve(0,l-1);
  if(vis) printf("%05lld\n",ans);
  else printf("%lld\n",ans);
  return 0;
}
