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
//#define inf (LL)(1e+18)
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
inline LL read()
{
	LL ret = 0;
	LL c = getchar_unlocked();
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
const int N=50005;
vector<pair<int,LL> > V[N];
int n,m;
LL d[N];
const LL inf=LONG_LONG_MAX;
LL solve()
{
    priority_queue<pair<LL,int> > Q;
    for(int i=1;i<=n;i++) d[i]=-1;
    d[1]=inf;
    Q.push(mp(d[1],1));
    while(!Q.empty()){
        pair<LL,int> p=Q.top();
        int u=p.sc;
        Q.pop();
        for(int i=0;i<V[u].size();i++){
            LL k=min(d[u],V[u][i].sc);
            if(d[V[u][i].f]<k){
            d[V[u][i].f]=k;
            Q.push(mp(d[V[u][i].f],V[u][i].f));
            }
        }
    }
    return d[n];
}
int main()
{
   int t,u,v;
   LL w;
   t=read();
   //scanf("%d",&t);
   while(t--){
   n=read();m=read();
   //scanf("%d %d",&n,&m);
   for(int i=1;i<=n;i++) V[i].clear();
   while(m--){
        u=read();v=read();w=read();
       //scanf("%d %d %lld",&u,&v,&w);
        V[u].pb(mp(v,w));
        V[v].pb(mp(u,w));
   }
    LL ans=solve();
    printf("%lld\n",ans);
   }
   return 0;
}
