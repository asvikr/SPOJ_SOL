#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long int LL;
using namespace std;
int a[100005];
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        LL need,n;
        scanf("%lld",&need);
        scanf("%lld",&n);
        for(int j=0;j<n;j++)
            scanf("%lld",&a[j]);
        sort(a,a+n);
        LL sum=0;
        LL k;
        for(k=n-1;k>=0;k--)
        {
            sum+=a[k];
            if(sum>=need)
                break;
        }
        printf("Scenario #%d:\n",i);
        if(sum>=need)
            printf("%lld\n",n-k);
        else
            printf("impossible\n");

    }
    return 0;
}
