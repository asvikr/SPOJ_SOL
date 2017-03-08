#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
vector<int> V[100005];
int chk[100005];
int cnt=0;
void dfs1(int src)
{
    chk[src]=1;
    vector<int> :: iterator it;
    for(it=V[src].begin();it!=V[src].end();it++)
    {
        if(chk[*it]==0)
            dfs1(*it);
    }
}
void dfs(int n)
{
    for(int i=0;i<=n;i++)
        chk[i]=0;
    for(int i=0;i<n;i++)
    {
        if(chk[i]==0)
        {
            cnt++;
            dfs1(i);
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,u,v;
        scanf("%d %d",&n,&m);
        for(int i=0;i<n-1;i++)
            V[i].clear();
        for(int i=0;i<m;i++)
        {
            scanf("%d %d",&u,&v);
            V[u].push_back(v);
            V[v].push_back(u);
        }
        dfs(n);
        printf("%d\n",cnt);
        cnt=0;
    }
    return 0;
}
