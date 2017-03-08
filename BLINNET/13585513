#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n,m;
    scanf("%d",&t);
    while(t--)
    {
        int u,v,w;
        string s;
        scanf("%d",&n);
        vector<pair<int,int> > V[10005];
        for(int i=1;i<=n;i++)
        {
            cin>>s>>m;
        for(int j=0;j<m;j++)
        {
            scanf("%d %d",&u,&w);
            V[i].push_back(make_pair(u,w));
        }
        }
        int chk[n+5];
        memset(chk,0,sizeof(chk));
        int d[n+5];
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
            //printf("%d\n",top.first);
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
    printf("%d\n",ans);
    }
    return 0;
}
