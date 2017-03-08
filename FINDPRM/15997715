#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
LL max(LL a,LL b,LL c){return max(a,max(b,c));}
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
	int ret = 0,temp=1;
	int c = getchar_unlocked();
	while(c<'0' || c>'9'){
		c = getchar_unlocked();
	}
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
const LL N=10000005;
int prime[N];
bool mark[N];
int main()
{
   prime[2]=1,prime[3]=1;
    for(int i=4;i<N;i+=2) mark[i]=1;
    for(int i=9;i<N;i+=6) mark[i]=1;
    for(int i=6;i<N;i+=6){
        if(!mark[i-1]){
            prime[i-1]=1;
            if((LL)(i-1)*1LL*(i-1)<N)
                for(int j=(i-1)*(i-1);j<N;j+=(i-1)) mark[j]=1;
        }
        if(!mark[i+1]){
            prime[i+1]=1;
            if((LL)(i+1)*1LL*(i+1)<N)
                for(int j=(i+1)*(i+1);j<N;j+=(i+1))
                mark[j]=1;
        }
    }
    for(int i=2;i<N;i++) prime[i]+=prime[i-1];
    int t;
    t=read();
    while(t--){
        int n;
        n=read();
        printf("%d\n",prime[n]-prime[n/2]);
    }
    return 0;
}

