#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main()
{
    int p;
    scanf("%d",&p);
    while(p--)
    {
        LL n,t=0,k,m;
        scanf("%lld %lld %lld",&n,&k,&m);
        if(n>m)
        {
            printf("0\n");
            continue;
        }
        while(1)
        {
            if((double)n*(double)k>(double)m)
                break;
            n=n*k;
            t++;
        }
        printf("%lld\n",t);
    }
    return 0;
}
