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
#define MAX 1000000000000000LL
LL fib[2002],ans[2002];
int main()
{
    fib[0]=1;
    fib[1]=2;
    int i;
    for(i=2;;i++){
        fib[i]=fib[i-1]+fib[i-2];
        if(fib[i]>MAX) break;
    }
    //in case of LL change read function
    int t;
    scanf("%d",&t);
    while(t--){
        LL n;
        scanf("%lld",&n);
        for(i=0;;i++) if(fib[i]>n) break;
        int j=0;
        while(i>0){
            ans[j]=n/fib[i-1];
            n=n%fib[i-1];
            j++;
            i--;
        }
        for(i=0;i<j;i++) printf("%lld",ans[i]);
        printf("\n");
    }
    return 0;
}
