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
const int N=1000005;
vector<LL> prime;
bool mark[N];
void pre()
{
    prime.pb(2);
    for(int i=3;i*i<N;i+=2){
        if(mark[i]==0){
            for(int j=i*i;j<N;j+=2*i){
                mark[j]=1;
            }
        }
    }
    for(int i=3;i<N;i+=2)
        if(mark[i]==0)
        prime.pb(i);
}
LL fun(LL n)
{
    LL cnt=0;
    LL sum=0;
    if(n==2 || n==3 || n==5) return 1;
        if(n%2==0){
            cnt++;
            sum+=2;
            while(n%2==0) n/=2;
        }
        for(int i=3;i<=sqrt(n);i++){
                if(n%i==0){
                    cnt++;
                    sum+=i;
                    while(n%i==0) n/=i;
                }
        }
        if(cnt!=0 && n>1) return fun(sum+n)+cnt+1;
        else if(cnt!=0) return fun(sum)+cnt;
        else return 1;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        LL n;
        scanf("%lld",&n);
        printf("%lld\n",fun(n));
    }
    return 0;
}
