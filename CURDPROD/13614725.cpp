#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define en1 1000000000000000000LL
LL a[10005];
LL pro(LL mid,int n)
{
    LL tar=0;
    for(int i=0;i<n;i++)
    {
        tar+=mid/a[i];
    }
    return tar;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        LL T;
        scanf("%lld",&T);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
        LL st=1,en=en1+1;
        LL ans=0;
        while(en>st)
        {
            LL mid=(st+en)/2;
            LL total=pro(mid,n);
            if(total>=T)
            {
                ans=mid;
                en=mid;
                continue;
            }
            st=mid+1;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
