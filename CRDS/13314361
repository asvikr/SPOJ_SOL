#include<bits/stdc++.h>
using namespace std;
#define M 1000007
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        long long int n;
        scanf("%lld",&n);
        long long int ans;
        ans=(n*(n+1))/2;
        //printf("%lld\n",ans);
        ans%=M;
        //printf("%lld\n",ans);
        ans=(ans*3-n+M)%M;
        printf("%lld\n",ans%M);
    }
    return 0;
}
