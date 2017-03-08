#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long int LL;
#define M 1000000007
using namespace std;
LL n,q,t,z,x,p;
LL power(LL p,LL n)
{
    if(n==1)
        return p;
    if(n%2==0)
    {
     LL b = power(p,n/2)%M;
     return (b*b)%M;
    }
    else
    {
       LL a=power(p,n/2)%M;
        return ((((a%M)*a)%M)*p)%M;
    }
}
/*inline LL read()
{
	LL ret = 0;
	char c = getchar_unlocked();
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}*/

pair<LL, pair<LL,LL> > extendedEuclid(LL a,LL b) {
    LL x = 1, y = 0;
    LL xLast = 0, yLast = 1;
   LL q, r, m, n;
    while(a != 0) {
        q = b / a;
        r = b % a;
        m = xLast - q * x;
        n = yLast - q * y;
        xLast = x, yLast = y;
        x = m, y = n;
        b = a, a = r;
    }
    return make_pair(b, make_pair(xLast, yLast));
}

LL modInverse(LL a, LL m) {
    return (extendedEuclid(a,m).second.first + m) % m;
}
int main()
{
    //t=read();
    //printf("%lld\n",power(3,50));
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&p);
       // n=read();
    //p=read();
        x=power(p,n-1)%M;
        z=((((x*p)%M-1+M)%M)*(modInverse(p-1,M)))%M;

        printf("%lld %lld\n",z,x);
    }
    return 0;
}
