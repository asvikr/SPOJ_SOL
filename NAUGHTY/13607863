#include<bits/stdc++.h>
using namespace std;
pair<int,int> V[100005];
int main()
{
    int n,x,y;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        scanf("%d %d",&x,&y);
        V[x].first+=1;
        if(y!=x)
            V[y].second+=1;
    }
    int win=(n+1)/2;
    int temp=1,ans=INT_MAX;
    for(int i=0;i<100001;i++)
    {
       int c1=V[i].first;
       int c2=V[i].second;
       if(c1+c2<win)
        continue;
        ans=min(ans,max(win-c1,0));
    }
    if(ans>n)
        printf("Impossible\n");
    else
        printf("%d\n",ans);
    return 0;
}
