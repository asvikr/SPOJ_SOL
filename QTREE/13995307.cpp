#include<bits/stdc++.h>
using namespace std;
#define N 10100
#define root 0
#define LN 14
vector<int> adj[N],costs[N],indexx[N];
int baseArray[N],ptr;
int chainNo,chainInd[N],chainHead[N],posInBase[N];
int depth[N],pa[LN][N],otherEnd[N],subsize[N];
int st[N*6],qt[N*6];
void dfs(int cur,int prev,int d=0)
{
    pa[0][cur]=prev;
    depth[cur]=d;
    subsize[cur]=1;
    for(int i=0;i<adj[cur].size();i++)
    {
        if(adj[cur][i]!=prev)
        {
            otherEnd[indexx[cur][i]]=adj[cur][i];
            dfs(adj[cur][i],cur,d+1);
            subsize[cur]+=subsize[adj[cur][i]];
        }
    }
}
void HLD(int curNode,int cost,int prev)
{
    if(chainHead[chainNo]==-1)
        chainHead[chainNo]=curNode;
    chainInd[curNode]=chainNo;
    posInBase[curNode]=ptr;
    baseArray[ptr++]=cost;

    int sc=-1,ncost;
    for(int i=0;i<adj[curNode].size();i++)
    {
        if(adj[curNode][i]!=prev)
        {
            if(sc==-1 || subsize[sc]<subsize[adj[curNode][i]]){
                sc=adj[curNode][i];
                ncost=costs[curNode][i];
            }
        }
    }
    if(sc!=-1)
    {
        HLD(sc,ncost,curNode);
    }
    for(int i=0;i<adj[curNode].size();i++)
    {
        if(adj[curNode][i]!=prev)
        if(sc!=adj[curNode][i]){
            chainNo++;
            HLD(adj[curNode][i],costs[curNode][i],curNode);
        }

    }
}
int LCA(int u, int v) {
	if(depth[u] < depth[v]) swap(u,v);
	int diff = depth[u] - depth[v];
	for(int i=0; i<LN; i++) if( (diff>>i)&1 ) u = pa[i][u];
	if(u == v) return u;
	for(int i=LN-1; i>=0; i--) if(pa[i][u] != pa[i][v]) {
		u = pa[i][u];
		v = pa[i][v];
	}
	return pa[0][u];
}
void make_tree(int cur,int s,int e)
{
    if(s==e-1)
    {
        st[cur]=baseArray[s];
        return;
    }
    int c1=(cur<<1),c2=c1|1,m=(s+e)>>1;
    make_tree(c1,s,m);
    make_tree(c2,m,e);
    st[cur]=st[c1]>st[c2]?st[c1]:st[c2];
}
void update_tree(int cur,int s,int e,int x,int val)
{
    if(s>x || e<=x) return;
    if(s==x && s==e-1){
        st[cur]=val;
        return;
    }
    int c1=(cur<<1),c2=c1|1,m=(s+e)>>1;
    update_tree(c1,s,m,x,val);
    update_tree(c2,m,e,x,val);
    st[cur]=st[c1]>st[c2]?st[c1]:st[c2];
}
void query_tree(int cur,int s,int e,int S,int E)
{
    if(s>=E || e<=S){
        qt[cur]=-1;
        return;
    }
    if(s>=S && e<=E){
        qt[cur]=st[cur];
        return;
    }
    int c1=(cur<<1),c2=c1|1,m=(s+e)>>1;
    query_tree(c1,s,m,S,E);
    query_tree(c2,m,e,S,E);
    qt[cur]=qt[c1]>qt[c2]?qt[c1]:qt[c2];
}
int query_up(int u,int v)
{
    if(u==v)
        return 0;
    int uchain,vchain=chainInd[v],ans=-1;
    while(1){
        uchain=chainInd[u];
        if(uchain==vchain){
            if(u==v)
                break;
            query_tree(1,0,ptr,posInBase[v]+1,posInBase[u]+1);
            if(qt[1]>ans) ans=qt[1];
            break;
        }
        query_tree(1,0,ptr,posInBase[chainHead[uchain]],posInBase[u]+1);
        if(qt[1]>ans) ans=qt[1];
        u=chainHead[uchain];
        u=pa[0][u];
    }
    return ans;
}
void query(int u,int v)
{
    int lca=LCA(u,v);
    int ans=query_up(u,lca);
    int temp=query_up(v,lca);
    if(temp>ans) ans=temp;
    printf("%d\n",ans);
}
void change(int i,int val)
{
    int u=otherEnd[i];
    update_tree(1,0,ptr,posInBase[u],val);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        ptr=0;
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            adj[i].clear();
            costs[i].clear();
            indexx[i].clear();
            chainHead[i]=-1;
            for(int j=0;j<LN;j++)
                pa[j][i]=-1;
        }
        for(int i=1;i<n;i++)
        {
            int u,v,c;
            scanf("%d %d %d",&u,&v,&c);
            u--;v--;
            adj[u].push_back(v);
            costs[u].push_back(c);
            indexx[u].push_back(i-1);
            adj[v].push_back(u);
            costs[v].push_back(c);
            indexx[v].push_back(i-1);
        }
        chainNo=0;
        dfs(root,-1);
        HLD(root,-1,-1);
        make_tree(1,0,ptr);
        for(int i=1;i<LN;i++)
            for(int j=0;j<n;j++)
            if(pa[i-1][j]!=-1)
               pa[i][j]=pa[i-1][pa[i-1][j]];
        while(1){
            char s[100];
            scanf("%s",s);
            if(s[0]=='D'){
                break;
            }
            int a,b;
            scanf("%d %d",&a,&b);
            if(s[0]=='Q')
            {
                query(a-1,b-1);
            }
            else
            {
                change(a-1,b);
            }
        }
    }
    return 0;
}
