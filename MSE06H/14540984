#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
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
struct edge
{
    int st,en;
};
bool cmp(struct edge x,struct edge y)
{
    if(x.st==y.st)
        return x.en<y.en;
    return x.st<y.st;
}
const int MAXN=1005;
int bit[MAXN];
void update(int x,int val)
{
    while(x<MAXN)
    {
        bit[x]+=val;
        x+=x&-x;
    }
}
LL sum(int x)
{
    LL ans=0;
    while(x>0){
        ans+=bit[x];
        x-=x&-x;
    }
    return ans;
}
int main()
{
    int t;
    t=read();
    for(int tt=1;tt<=t;tt++){
        memset(bit,0,sizeof(bit));
        int n,m,k;
        n=read();
        m=read();
        k=read();
        edge a[k];
        for(int i=0;i<k;i++){
            a[i].st=read();
            a[i].en=read();
            }
        sort(a,a+k,cmp);
        LL ans=0;
        for(int i=0;i<k;i++){
            ans+=sum(MAXN-1)-sum(a[i].en);
            update(a[i].en,1);
        }
        printf("Test case %d: %lld\n",tt,ans);
    }
    return 0;
}
