#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
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
int phi(int x)
{
    int ans=x;
    if(x%2==0){
        ans-=ans/2;
    while(x%2==0) x/=2;
    }
    for(int i=3;i*i<=x;i+=2){
            if(x%i==0){
                ans-=ans/i;
                while(x%i==0) x/=i;
            }
    }
    if(x>1) ans-=ans/x;
    return ans;
}
int main()
{
    int n;
    while(scanf("%d",&n)!=EOF){
        LL ans=1;
        int x;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            ans=(ans*phi(x));
            if(ans>=M) ans%=M;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

