#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
#define f first
#define sc second
#define M  5000000
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
int bit[MAXN],a[MAXN],b[MAXN];
void update(int idx,int val)
{
    while(idx<MAXN){
        bit[idx]+=val;
        if(bit[idx]>=M)
            bit[idx]-=M;
        idx+=idx&-idx;
    }
}
int query(int idx)
{
    int ans=0;
    while(idx>0){
        ans+=bit[idx];
        if(ans>=M)
            ans-=M;
        idx-=idx&-idx;
    }
    return ans;
}
int main()
{
    int n,k;
    int x;
    n=read(); k=read();
    for(int i=0;i<n;i++){
        a[i]=read();
        a[i]++;
        b[i]=1;
    }
    for(int i=0;i<k;i++){
        memset(bit,0,sizeof(bit));
        for(int j=0;j<n;j++){
            update(a[j],b[j]);
            b[j]=query(a[j]-1);
        }
    }
    printf("%d\n",query(MAXN-1));
    return 0;
}

