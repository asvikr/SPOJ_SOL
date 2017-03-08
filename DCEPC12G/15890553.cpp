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
const int N=10000005;
vector<int> prime;
int phi[N];
LL fact[N];
void pre()
{
    fact[1]=1;
    fact[0]=1;
    phi[1]=1;
    for(int i=2;i<N;i++) {
    phi[i]=i;
    fact[i]=(i*fact[i-1])%(M-1);
    }
    prime.pb(2);
    for(int i=2;i<N;i++){
        if(phi[i]==i){
            for(int j=i;j<N;j+=i){
                phi[j]-=phi[j]/i;
            }
        }
    }
    for(int i=3;i<N;i+=2)
        if(phi[i]==i-1)
        prime.pb(i);
   //for(int i=1;i<100;i++) printf("%d ",phi[i]);
}
int main()
{
    pre();
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        int pr=upper_bound(prime.begin(),prime.end(),n)-prime.begin();
        int to=phi[n];
        int fn=pr-to;
        if(fn<0) fn=0;
        printf("%d\n",power(to,fact[fn]));
    }
    return 0;
}