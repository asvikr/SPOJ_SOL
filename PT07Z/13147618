#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> V[10005];
int max1=-1;
int node;
void dfs(int src,int chk[],int d)
{
    chk[src]=1;
    if(max1<d)
    {
        max1=d;
        node=src;
        //max2=max1;
    }
    d+=1;
    vector<int> :: iterator it;
    for(it=V[src].begin();it!=V[src].end();it++)
    {
        if(chk[*it]==0)
            dfs(*it,chk,d);
    }
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    int u,v;
    for(int i=1;i<n;i++)
    {
        scanf("%d %d",&u,&v);
        V[u].push_back(v);
        V[v].push_back(u);
    }
    int chk[10005];
    for(int i=1;i<=n;i++)
        chk[i]=0;
    int d=0;
    dfs(1,chk,d);
    for(int i=1;i<=n;i++)
        chk[i]=0;
    d=0;
    max1=-1;
    dfs(node,chk,d);
    printf("%d\n",max1);
    return 0;

}
