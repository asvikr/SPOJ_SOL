#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
const int N=30005;
const int INF = 1000000000; 
int n,m;
int s,t,d[N],ptr[N],q[N];
struct edge
{
	int a,b;
	LL cap,flow;
};
vector<edge> e;
vector<int> g[N];
void add_edge(int a,int b,int cap)
{
	edge e1={a,b,cap,0};
	edge e2={b,a,cap,0};
	g[a].pb(e.size());
	e.pb(e1);
	g[b].pb(e.size());
	e.pb(e2);
}
bool bfs()
{
	int qh=0,qt=0;
	q[qt++]=s;
	memset(d,-1,n*sizeof(d[0]));
	d[s]=0;
	while(qh<qt && d[t]==-1){
		int v=q[qh++];
		for(int i=0;i<g[v].size();i++){
			int id=g[v][i];
			int to=e[id].b;
			if(d[to]==-1 && e[id].cap-e[id].flow>0){
				d[to]=d[v]+1;
				q[qt++]=to;
			}
		}
	}
	//printf("%d\n",d[t]);
	return (d[t]!=-1);
}
LL dfs(int v,LL flow)
{
	if(!flow) return 0;
	if(v==t) return flow;
	for(;ptr[v]<g[v].size();++ptr[v]){
		int id=g[v][ptr[v]];
		int to=e[id].b;
		if(d[to]!=d[v]+1) continue;
		LL pushed=dfs(to,min(flow,e[id].cap-e[id].flow));
		if(pushed){
			e[id].flow+=pushed;
			e[id^1].flow-=pushed;
			return pushed;
		}
	}
	return 0;
}
LL dinic()
{
	LL flow=0;
	for(;;){
		if(!bfs()) break;
		memset (ptr, 0, n * sizeof ptr[0]);
		while(1){
			LL pushed=dfs(s,INF);
			if(!pushed)  break;
			flow+=pushed;
		}
	}
	return flow;
}
int main()
{
	scanf("%d %d",&n,&m);
	int u,v;
	LL w;
	for(int i=0;i<m;i++){
		scanf("%d %d %lld",&u,&v,&w);
		--u,--v;
		if(u>v) swap(u,v);
		if(u!=v)
			add_edge(u,v,w);
	}
	s=0,t=n-1;
	printf("%lld\n",dinic());
	return 0;
}
