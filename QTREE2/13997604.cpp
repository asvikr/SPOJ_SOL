#include<bits/stdc++.h>
using namespace std;
#define N 10010
#define LN 15
typedef long long int LL;
vector<pair<int,int> > V[N];
int pa[LN][N],depth[N];
LL sum[N];
void dfs(int cur,int prev)
{
    pa[0][cur]=prev;
    depth[cur]=(prev==-1?0:depth[prev]+1);
    for(int i=0;i<V[cur].size();i++){
        if(V[cur][i].first!=prev){
                sum[V[cur][i].first]+=sum[cur]+V[cur][i].second;
            dfs(V[cur][i].first,cur);
        }
    }
}
  int LCA(int u,int v)
    {
        if(depth[u]<depth[v])
            swap(u,v);
            int LOG;
        for(LOG=1;(1<<LOG)<=depth[u];LOG++);
        LOG--;
        for(int i=LOG;i>=0;i--){
            if(depth[u]-(1<<i)>=depth[v]){
             u=pa[i][u];
            }
        }
        if(u==v)
            return u;
        for(int i=LOG;i>=0;i--){
            if(pa[i][u]!=-1 && pa[i][u]!=pa[i][v]){
                u=pa[i][u];
                v=pa[i][v];
            }
        }
        return pa[0][u];
    }
void solve(int u,int v)
{
    int lca=LCA(u,v);
    LL ans=sum[u]+sum[v]-2*sum[lca];
   printf("%lld\n",ans);
}
int find(int p, int t) {
	int i, stp;
	for(stp = 1; 1<<stp <= depth[p]; stp++); stp--;
	for(i = stp; i >= 0; i--)
		if(depth[p] - (1<<i) >= t)
			p = pa[i][p];
	return p;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,u,v,w;
        scanf("%d",&n);
        for(int i=1;i<=n;i++){
            V[i].clear();
            sum[i]=0;
            depth[i]=0;
        }
        for(int i=1;i<n;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            V[u].push_back(make_pair(v,w));
            V[v].push_back(make_pair(u,w));
        }
        memset(pa,-1,sizeof(pa));
        dfs(1,-1);
        for(int j=1;j<LN;j++){
            for(int i=1;i<=n;i++){
                if(pa[j-1][i]!=-1){
                    pa[j][i]=pa[j-1][pa[j-1][i]];
                }
            }
        }

        char str[10];
        int val;
        while(1){
         scanf("%s",str);
         if(str[1]=='O')
            break;
        scanf("%d %d",&u,&v);
         if(str[1]=='I'){
            solve(u,v);
         }
         else if(str[1]=='T')
         {
             scanf("%d",&val);
             int lca=LCA(u,v);
             int ans;
             if(depth[u]-depth[lca]+1 >= val) ans = find(u, depth[u]-val+1);
				else ans= find(v, 2*depth[lca]+val-depth[u]-1);
				printf("%d\n", ans);
         }
        }
    }
    return 0;
}
