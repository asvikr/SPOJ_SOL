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
            a[i][j]=99999999;
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
       if(a[i][k]+a[k][j]<a[i][j])
        a[i][j]=a[i][k]+a[k][j];
    /*for(int i=0;i<=7;i++){
        for(int j=0;j<=7;j++)
        printf("%d ",a[i][j]);
        printf("\n");
    }*/
    int src,dest,q;
    scanf("%d",&src);
    scanf("%d",&q);
    while(q--)
    {
    scanf("%d",&dest);
    if(a[src][dest]!=99999999)
        printf("%d\n",a[src][dest]);
    else
        printf("NO PATH\n");
    }
}
