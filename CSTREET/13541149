#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,p,n,m;
    scanf("%d",&t);
    while(t--)
    {
        int u,v,w;
        scanf("%d %d %d",&p,&n,&m);
        vector<pair<int,int> > V[1005];
        for(int i=0;i<m;i++)
        {
            scanf("%d %d %d",&u,&v,&w);
            V[u].push_back(make_pair(v,w));
            V[v].push_back(make_pair(u,w));
        }
        int chk[n+1];
        memset(chk,0,sizeof(chk));
        int d[n+1];
        for(int i=1;i<=n;i++)
            d[i]=INT_MAX;
        set<pair<int,int> > S;
        int src=1;
        for(int i=1;i<=n;i++)
            S.insert(make_pair(d[i],i));
        S.erase(S.find(make_pair(d[src],src)));
        d[src]=0;
        S.insert(make_pair(d[src],src));
        int ans=0;
        while(!S.empty())
        {
            pair<int,int> top=*S.begin();
            S.erase(S.begin());
            int x=top.second;
            chk[x]=1;
            if(x!=src)
                ans+=top.first;
            vector<pair<int,int> > :: iterator it;
            for(it=V[x].begin();it!=V[x].end();it++)
            {
                if(chk[it->first]==0)
                {
                if(d[it->first]>(it->second))
                {
                    S.erase(S.find(make_pair(d[it->first],it->first)));
                    d[it->first]=it->second;
                    S.insert(make_pair(d[it->first],it->first));
                }
                }
            }

        }
    printf("%d\n",ans*p);
    }
    return 0;
}
