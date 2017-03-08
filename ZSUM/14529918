#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define f first
#define sc second
#define M 10000007
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
inline LL power(LL x,LL y)
{
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        y/=2;
    }
    return ans;
}
inline int read()
{
	int ret = 0;
	int c = getchar_unlocked();

	while(c<'0' || c>'9')
		c = getchar_unlocked();
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
int main()
{
    LL n,k;
    while(scanf("%lld %lld",&n,&k)==2){
    if(n==0 && k==0)
     return 0;
    LL ans=0;
    ans=2*power(n-1,k);
    if(ans>=M)
        ans%=M;
    ans=ans+power(n,k);
    if(ans>=M)
        ans%=M;
    ans=ans+2*power(n-1,n-1);
    ans%=M;
    ans=ans+power(n,n);
    if(ans>=M)
        ans%=M;
    printf("%lld\n",ans);
    }
    return 0;
}

