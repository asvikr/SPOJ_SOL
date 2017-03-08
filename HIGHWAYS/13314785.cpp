#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> > V[100005];
int d[100005];
void dikstra(int st,int en,int n)
{
    for(int i=1;i<=n;i++)
            d[i]= -1000000007;
    priority_queue<pair<int,int> > Q;
    d[st]=0;
    Q.push(make_pair(d[st],st));
    while(!Q.empty())
    {
        int p1 = (Q.top()).second;
        if(en==p1)
            return;
        Q.pop();
        vector<pair<int,int> > :: iterator it;
        for(it=V[p1].begin();it!=V[p1].end();it++)
        {
                if(d[(*it).first]<d[p1]+(*it).second)
                {
                    d[(*it).first]=d[p1]+(*it).second;
                    Q.push(make_pair(d[(*it).first],(*it).first));
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
        int n,m,st,en;
        scanf("%d %d %d %d",&n,&m,&st,&en);
        int u,v,wt;
        while(m--)
        {
            scanf("%d %d %d",&u,&v,&wt);
            V[u].push_back(make_pair(v,-1*wt));
            V[v].push_back(make_pair(u,-1*wt));
        }
        dikstra(st,en,n);
        if(d[en]!=-1000000007)
        printf("%d\n",-1*d[en]);
        else
            printf("NONE\n");
    }
    return 0;
}
