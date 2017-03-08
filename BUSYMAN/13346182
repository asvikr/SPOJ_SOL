#include<bits/stdc++.h>
using namespace std;
pair<int,int> V[100005];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int x,y;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&x,&y);
            V[i].first=y;
            V[i].second=x;
        }
        sort(V,V+n);
        int ans=1,prev=V[0].first;
        //for(int i=0;i<n;i++)
          //  printf("%d %d\n",V[i].second,V[i].first);
        for(int i=1;i<n;i++)
        {
            if(V[i].second>=prev)
            {
                ans++;
                prev=V[i].first;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
