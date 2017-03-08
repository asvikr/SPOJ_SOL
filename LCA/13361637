#include<bits/stdc++.h>
using namespace std;
int par[1005],visited[1005];
int lca(int x,int y,int n)
{
int i;
      for( i=1;i<=n;i++)
        visited[i] = 0;
        visited[x] = 1;
    while(par[x]!=x){
       visited[x] = 1;
       x = par[x];
       }
  visited[x] = 1;
   while(visited[y]!=1)
    y = par[y];
return y;
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int k=1;k<=t;k++)
    {
        printf("Case %d:\n",k);
        int n,m,x;
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            par[i]=i;
        for(int i=1;i<=n;i++)
        {
          scanf("%d",&m);
          while(m--)
          {
              int x;
              scanf("%d",&x);
              par[x]=i;
          }
        }
        int q,a,b;
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d %d",&a,&b);
           printf("%d\n",lca(a,b,n));
       }
    }
    return 0;
}
