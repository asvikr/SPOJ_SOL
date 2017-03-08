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
const int N=1000005;
LL phi[N];
LL res[N];
void pre()
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
            res[j]+=(i*phi[i]);
        }
    }
}
int main()
{
    pre();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        LL ans=res[n]+1;
        ans*=n;
        ans/=2;
        printf("%lld\n",ans);
    }
    return 0;
}

