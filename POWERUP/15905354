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
inline LL power(LL x,LL y,LL m)
{
    if(x==0 && y==0) return 1LL;
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%m;
        x=(x*x)%m;
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
int main()
{
    LL a,b,c;
    while(scanf("%lld %lld %lld",&a,&b,&c)){
        if(a==-1 && b==-1 && c==-1) break;
        if(a%M==0){
            if(c==0){
                printf("0\n");
                continue;
            }
            if(b==0 && c>0){
                printf("1\n");
                continue;
            }
            if(b>0){
                printf("0\n");
                continue;
            }
        }
        LL p=power(b,c,M-1);
        LL ans=power(a,p,M);
        printf("%lld\n",ans%M);
    }
    return 0;
}

