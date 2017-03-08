#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        pair<int,int> V[n];
        int a[n];
        int st,en,in;
        for(int i=0;i<n;i++)
        {
            scanf("%d %d",&st,&en);
            V[i].first=st;
            V[i].second=en;
            a[i]=st;
        }
        sort(a,a+n);
        int cnt=0;
        int maxi=-1;
        for(int i=0;i<n;i++)
        {
            int x=a[i];
            cnt=0;
            for(int j=0;j<n;j++)
            {
                if(V[j].first<=x && V[j].second>=x)
                    cnt++;
            }
            maxi=max(maxi,cnt);
        }
        printf("%d\n",maxi);
    }
    return 0;
}
