#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
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
const int N=900005;
int phi[N];
vector<int> prime[N];
LL sumphi[N];

void allphi(){

	for(int i=1;i<N;i++) phi[i]=i;
	for(int i=2;i<N;i++){
		if(phi[i]==i){
			for(int j=i;j<N;j+=i){
				phi[j]-=phi[j]/i;
				prime[j].pb(i);
			}
		}
	}
	sumphi[3]=1;
	for(int i=4;i<N;i++) sumphi[i]=sumphi[i-1]+phi[i]/2;
}

int calc(int mid,int k)
{
	int sz = prime[k].size();

	double val = 0;
	for(int i=0;i<(1<<sz);i++){
		int cnt=0;
		int p = 1;
		for(int j=0;j<sz;j++){
			if(i&(1<<j)) {
				cnt++;
				p*=prime[k][j];
			}
		}
		if(cnt&1) val -= mid/p;
		else val += mid/p;
	}
	return val;
}

int solve(int k,int pp)
{
	int l = 1,r = k;
	while(l<r){
		int mid = (l+r)/2;
		if(calc(mid,k)>=pp) r = mid;
		else l = mid+1;
	}
	return l;
}

int main()
{
	allphi();
	int t;
	scanf("%d",&t);
	while(t--){
		LL n;
		scanf("%lld",&n);
		if(n==1){
			printf("1 2\n");
			continue;
		}
		int k = lower_bound(sumphi,sumphi+N,n)-sumphi;
		
		LL pp = n-sumphi[k-1];
		int x = solve(k,pp);
		printf("%d %d\n",x,k-x);
	}
	return 0;
}
	