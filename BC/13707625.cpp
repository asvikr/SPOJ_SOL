#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case #%d: ",i);
        LL n,m,k;
        scanf("%lld %lld %lld",&n,&m,&k);
        LL x=0,y=0;
        x=(n-1)+(m-1)*(n)+(k-1)*(n*m);
        y=ceil((double)log2(n))+ceil((double)log2(m))+ceil((double)log2(k));
        printf("%lld %lld\n",x,y);
    }
    return 0;
}
