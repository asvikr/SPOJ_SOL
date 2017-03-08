#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
vector<pair<int,int> > V[505];
LL d[505];
void dijkstra(int s)
{
    for(int i=0;i<505;i++)
    {
        d[i]=-1*LONG_LONG_MAX;
    }
    d[s]=0;
    priority_queue<pair<int,int> > Q;
    Q.push(make_pair(0,s));
    while(!Q.empty())
    {
        vector<pair<int,int> >:: iterator it;
        int p = (Q.top()).second;
        Q.pop();
        //visited[p]=true;
        for(it=V[p].begin();it!=V[p].end();it++)
        {
            if(d[(*it).first]<d[p]+(*it).second)
            {
                d[(*it).first]=d[p]+(*it).second;
                Q.push(make_pair(d[(*it).first],(*it).first));
            }
        }
    }
}
int main()
{
    int n,u,v,w;
    scanf("%d",&n);
  for(int j=0;j<505;j++)
        d[j]=-1*LONG_LONG_MAX;
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
    if(d[dest]!=-1*LONG_LONG_MAX)
        printf("%lld\n",-d[dest]);
    else
        printf("NO PATH\n");
    }
    return 0;
}
