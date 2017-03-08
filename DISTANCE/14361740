#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL maxi[65],mini[65];
LL x[7];
int n,d;
void solve()
{
    LL p=0;
    for(int i=0;i<(1<<d);i++){
        p=0;
        for(int j=0;j<d;j++){
           if(i&(1<<j))
                p-=x[j];
           else
                p+=x[j];
        }
        //printf("%lld\n",p);
        maxi[i]=max(maxi[i],p);
        mini[i]=min(mini[i],p);
    }
}
int main()
{
    for(int i=0;i<65;i++){
        maxi[i]=LONG_LONG_MIN;
        mini[i]=LONG_LONG_MAX;
    }
    scanf("%d %d",&n,&d);
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            scanf("%lld",&x[j]);
        }
        solve();
    }
    LL ans=LONG_LONG_MIN;
    for(int i=0;i<(1<<d);i++){
        ans=max(ans,maxi[i]-mini[i]);
    }
    printf("%lld\n",ans);
    return 0;
}
