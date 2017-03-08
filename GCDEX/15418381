#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
//#include<ext/pb_ds/assoc_container.hpp>
//#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
const int N=1000001;
int phi[N];
LL res[N],cum[N];
void solve()
{
    for(int i=1;i<N;i++) phi[i]=i;
    for(int i=2;i<N;i++){
        if(phi[i]==i){
            for(int j=i;j<N;j+=i){
                phi[j]/=i;
                phi[j]*=i-1;
            }
        }
    }
    for(int i=1;i<N;i++){
        for(int j=i;j<N;j+=i){
            res[j]=res[j]+1LL*i*phi[j/i];
        }
    }
    for(int i=1;i<N;i++) res[i]-=i;
    cum[0]=0;
    for(int i=1;i<N;i++){
        cum[i]=cum[i-1]+res[i];
    }
}
int main()
{
    solve();
    int n;
    while(scanf("%d",&n)!=EOF){
        if(n==0) return 0;
        printf("%lld\n",cum[n]);
    }
    return 0;
}
