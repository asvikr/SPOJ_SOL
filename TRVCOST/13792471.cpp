#include<bits/stdc++.h>
using namespace std;
 int a[505][505];
int main()
{
    int n;
    scanf("%d",&n);
    int u,v,w;
    for(int i=0;i<501;i++){
        for(int j=0;j<501;j++)
        {
        if(i==j)
            a[i][j]=0;
        else
            a[i][j]=9999999;
        }
    }
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d",&u,&v,&w);
        a[u][v]=w;
        a[v][u]=w;
    }
    for(int k=0;k<501;k++)
        for(int i=0;i<501;i++)
        for(int j=0;j<501;j++)
        a[i][j]=min(a[i][k]+a[k][j],a[i][j]);
    int src,dest,q;
    scanf("%d",&src);
    scanf("%d",&q);
    while(q--)
    {
    scanf("%d",&dest);
    if(a[src][dest]!=9999999)
        printf("%d\n",a[src][dest]);
    else
        printf("NO PATH\n");
    }
}
