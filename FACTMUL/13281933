#include<cstdio>
#include<iostream>
#include<algorithm>
typedef long long int LL;
using namespace std;
LL mulmod(LL a,LL b,LL m)
{
    LL y=a,x=0;
    while(b>0)
    {
        if(b%2==1)
            x=(x+y)%m;
        y=(y*2)%m;
        b/=2;
    }
    return (x%m);
}
int main()
{
    int n;
    LL m=109546051211LL;
    LL ans=1;
    LL fact=1;
    scanf("%d",&n);
    if(n>=587116)
        printf("0\n");
    else
    {
        for(int i=1;i<=n;i++)
        {
            fact=mulmod(fact,i,m)%m;
            ans=mulmod(ans,fact,m)%m;
        }
        printf("%lld\n",ans);
    }
    return 0;

}
