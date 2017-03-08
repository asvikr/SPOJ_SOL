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
const int N=40005;
const int sq=205;
const int MM=100005;
const int LN=19;
int a[N],b[N];
int n,m,k;
int in[N],out[N],id[N<<1],level[N];
int timer=0;
vector<int> V[N];
int dp[LN][N],ans[N],val[N];
struct node
{
	int idx,l,r,lc;
}Q[MM];

bool vis[N];
bool cmp(node x,node y)
{
	if(x.l/sq==y.l/sq) return x.r<y.r;
	return x.l<y.l;
}

void dfs(int cur,int prev)
{
	in[cur]=++timer;
	id[timer]=cur;
	for(int i=1;i<LN;i++) dp[i][cur]=dp[i-1][dp[i-1][cur]];
	for(int x:V[cur]){
		if(x!=prev){
			level[x]=level[cur]+1;
			dp[0][x]=cur;
			dfs(x,cur);
		}
	}
	out[cur]=++timer;
	id[timer]=cur;
}
int lca(int u,int v)
{
	if(level[u]>level[v]) swap(u,v);
	for(int i=LN-1;i>=0;i--)
		if(level[v]-(1<<i)>=level[u]) v=dp[i][v];
	if(u==v) return u;
	for(int i=LN-1;i>=0;i--){
		if(dp[i][u]!=dp[i][v]){
			u=dp[i][u];
			v=dp[i][v];
		}
	}
	return dp[0][u];
}
inline void check(int x,int &res)
{
	if((vis[x]) && (--val[a[x]]==0)) res--;
	else if((!vis[x]) && (val[a[x]]++==0)) res++;
	vis[x]^=1;
}
void compute()
{
	int curL = Q[0].l, curR = Q[0].l - 1, res = 0;
	
	for (int i = 0; i < m; i++){
		
		while (curL < Q[i].l) check(id[curL++], res);
		while (curL > Q[i].l) check(id[--curL], res);
		while (curR < Q[i].r) check(id[++curR], res);
		while (curR > Q[i].r) check(id[curR--], res);
		
		int u = id[curL], v = id[curR];
		
		// Case 2
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
		
		ans[Q[i].idx] = res;
		
		if (Q[i].lc != u and Q[i].lc != v) check(Q[i].lc, res);
	}

	for (int i = 0; i < m; i++) printf("%d\n", ans[i]);
}
int main()
{
	//scanf("%d %d",&n,&m);
	memset(vis,0,sizeof(vis));
	memset(val,0,sizeof(val));
	n=read();m=read();
	for(int i=1;i<=n;i++) {
		//scanf("%d",&a[i]);
		a[i]=read();
		b[i]=a[i];
	}

	sort(b+1,b+n+1);
	k=unique(b+1,b+n+1)-b-1;
	for(int i=1;i<=n;i++) a[i]=lower_bound(b+1,b+k+1,a[i])-b;
	int u,v;
	for(int i=0;i<n-1;i++){
		//scanf("%d %d",&u,&v);
		u=read();v=read();
		V[u].pb(v);
		V[v].pb(u);
	}
	dp[0][1]=1;
	dfs(1,-1);
	for(int i=0;i<m;i++){
		//scanf("%d %d",&u,&v);
		u=read();v=read();
		Q[i].lc=lca(u,v);
		if(level[u]>level[v]) swap(u,v);
		if(Q[i].lc==u) Q[i].l=in[u],Q[i].r=in[v];
		else Q[i].l=out[u],Q[i].r=in[v];
		Q[i].idx=i;
	}
	sort(Q,Q+m,cmp);
	compute();
	return 0;
}
