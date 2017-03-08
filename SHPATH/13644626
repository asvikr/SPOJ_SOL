#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > V[10005];
int dikstra(int src,int dest,int n)
{
    int dist[n];
    for(int i=1;i<=n;i++){
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
        if(x==dest)
            return -1*dist[x];
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
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            V[i].clear();
        string str,str1;
        int u,v,w,x;
        map<string,int> M;
        for(int i=1;i<=n;i++)
        {
            cin>>str;
            M[str]=i;
            scanf("%d",&x);
            while(x--){
            scanf("%d %d",&v,&w);
            V[i].push_back(make_pair(v,-1*w));
        }
        }
        int q;
        scanf("%d",&q);
        while(q--)
        {
            cin>>str>>str1;
            int cost=dikstra(M[str],M[str1],n);
            printf("%d\n",cost);
        }
    }
    return 0;
}
