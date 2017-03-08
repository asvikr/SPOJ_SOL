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
inline LL power(LL x,LL y,LL m)
{
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%m;
        x=(x*x)%m;
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
const int N=100005;
vector<int> prime;
bool mark[N];
int main()
{
    for(int i=3;i*i<N;i+=2){
        if(!mark[i])
            for(int j=i*i;j<N;j+=2*i)
                mark[j]=1;
    }
    prime.pb(2);
    for(int i=3;i<N;i+=2)
        if(!mark[i]) prime.pb(i);
    LL p;
    int n;
    LL x;
    while(1){
        scanf("%lld %d",&p,&n);
        if(p==0 && n==0) return 0;
        for(int i=0;i<n;i++){
        scanf("%lld",&x);
        LL m=p-1;
        bool temp=false;
        for(int i=0;i<prime.size();i++){
            if(sqrt(m)<prime[i]) break;
            if(m%prime[i]==0){
                if(power(x,(p-1)/prime[i],p)==1){
                    temp=true;
                    break;
                }
                while(m%prime[i]==0) m/=prime[i];
            }
        }
            if(m>1 && power(x,(p-1)/m,p)==1)
                temp=true;
          if(temp==true) puts("NO");
          else puts("YES");
     }
  }
  return 0;
}
