#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
vector<pair<int,int> > V[505];
LL dist[505];
int dijkstra(int src)
{
    for(int i=1;i<=501;i++){
        dist[i]=-1*INT_MAX;
    }
    dist[src]=0;
    priority_queue<pair<int,int> > Q;
    Q.push(make_pair(dist[src],src));
    while(!Q.empty())
    {
        pair<int,int> top=Q.top();
        Q.pop();
        int x=top.second;
        vector<pair<int,int> > :: iterator it;
        for(it=V[x].begin();it!=V[x].end();it++)
        {
                if(dist[it->first]<dist[x]+it->second)
                {
                    dist[it->first]=dist[x]+it->second;
                    Q.push(make_pair(dist[it->first],it->first));
                }
        }
    }
}
int main()
{
    int n,u,v,w;
    scanf("%d",&n);
  for(int j=0;j<505;j++)
        dist[j]=-1*INT_MAX;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
         V[u].push_back(make_pair(v,-1*w));
         V[v].push_back(make_pair(u,-1*w));
    }
    int src,q,dest;
    scanf("%d %d",&src,&q);
    dijkstra(src);
    while(q--)
    {
        scanf("%d",&dest);
    if(dist[dest]!=-1*INT_MAX)
        printf("%lld\n",-dist[dest]);
    else
        printf("NO PATH\n");
    }
    return 0;
}
