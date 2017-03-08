#include<iostream>
#include<cstdio>
using namespace std;
int a[10005];
int main()
{
    int n,m;
    int temp=1;
    scanf("%d%d",&n,&m);
    int x,y;
    for(int i=1;i<=m;i++)
    {
        scanf("%d%d",&x,&y);
        if(a[x]==1 && a[y]==1)
        {
            temp=0;
        }
        else
        {
            a[x]=1;
            a[y]=1;
        }
    }
    if(temp==0)
        printf("NO\n");
    else
        printf("YES\n");
    return 0;
}
