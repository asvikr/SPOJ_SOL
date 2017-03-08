#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long int LL;
using namespace std;
 LL a[100005];
LL n,c;
int f(int x)
{
    int cowplaced=1;
    LL lastpos=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]-lastpos>=x)
        {
            cowplaced++;
            if(cowplaced==c)
            {
                return 1;
            }
            lastpos=a[i];
        }
    }
    return 0;
}
LL solve()
{
    LL st=0;
    LL en=a[n-1];
    LL mid;
    while(en>st)
    {
        mid=(st+en)/2;
        if(f(mid)==1)
        {
            st=mid+1;
        }
        else
            en=mid;
    }
    return st-1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&c);
        for(int i=0;i<n;i++)
            scanf("%lld",&a[i]);
            sort(a,a+n);
        LL k=solve();
        printf("%lld\n",k);
    }
}
