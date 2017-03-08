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
pair<int,int> ans[100005];
const int Input=100005;
void solve(int x,int y,int number)
{
    while(Input != number)
  {
   if(x>=0 && x<-y)
   {
    ++x;
    ans[++number]=mp(x,y);
    continue;
   }
   if(x<=0 && y>-x)
   {
    --x;
    ans[++number]=mp(x,y);
    continue;
   }
   if(x>=0 && x>=-y && y<1)
   {
    ++y;
    ans[++number]=mp(x,y);
    continue;
   }
   if(x<0 && y<=-x && y>0)
   {
    --y;
    ans[++number]=mp(x,y);
    continue;
   }
   if(x<0 && y<=0)
   {
    ++x;
    --y;
    ans[++number]=mp(x,y);
    continue;
   }
   if(x>0 && y>=1)
   {
    --x;
    ++y;
    ans[++number]=mp(x,y);
    continue;
   }
  }
}
int main()
{
    ans[1]=mp(0,0);
    solve(0,0,1);
    int x;
    while(scanf("%d",&x)!=EOF){
        printf("%d %d\n",ans[x].f,ans[x].sc);
    }
    return 0;
}

