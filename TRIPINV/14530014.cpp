#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define f first
#define sc second
#define M 1000000007
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
#define MAXN 100005
int a[MAXN];
int bit[2][MAXN];
void add(int k,int x,int val)
{
    for(int i=x;i<MAXN;i+=i&-i)
        bit[k][i]+=val;
}
int query(int k,int x)
{
    int ans=0;
    while(x>0){
        ans+=bit[k][x];
        x-=x&-x;
    }
    return ans;
}
int main()
{
    int n;
    n=read();
    for(int i=0;i<n;i++){
        a[i]=read();
        add(1,a[i],1);
    }
    LL ans=0;
    for(int i=0;i<n;i++){
        ans+=(LL)(query(0,MAXN-1)-query(0,a[i]))*(query(1,a[i]-1));
        add(1,a[i],-1);
        add(0,a[i],1);
    }
    printf("%lld\n",ans);
    return 0;
}

