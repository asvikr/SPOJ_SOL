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
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
const int N=5111111;
bool mark[N];
int a[N],cnt[N];
void pre()
{
    for(int i=3;i*i<N;i+=2){
        if(mark[i]==0){
            for(int j=i*i;j<N;j+=2*i){
                mark[j]=1;
            }
        }
    }
    LL sum=1;
    for(LL c=2,x=2,p=2;sum<N;){
        sum+=x;
        if(sum>=N) break;
        if(mark[sum]==0 && sum%2!=0) a[x]=1;
        x=x*p;
    }
    for(LL i=3;i<N;i+=2){
        sum=1;
        if(mark[i]==0){
        for(LL c=i,x=i,p=i;sum<N;){
            sum+=x;
            if(sum>=N) break;
            if(mark[sum]==0 && sum%2!=0) a[x]=1;
            x=x*p;
        }
        }
    }
    for(int i=1;i<N;i++){
        cnt[i]=cnt[i-1]+a[i];
    }
}
int main()
{
    pre();
    int t;
    scanf("%d",&t);
    while(t--){
        int l,r;
        scanf("%d %d",&l,&r);
        printf("%d\n",cnt[r]-cnt[l-1]);
    }
    return 0;
}
