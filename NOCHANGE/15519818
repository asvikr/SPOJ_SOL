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
const int N=100005;
bool ans[N];
int a[6];
int main()
{
    int x,k;
    scanf("%d %d",&x,&k);
    for(int i=0;i<k;i++) {
    scanf("%d",&a[i]);
    if(i>0) a[i]+=a[i-1];
    }
    memset(ans,false,sizeof(ans));
    ans[0]=true;
    for(int i=0;i<k;i++){
        for(int j=a[i];j<=x;j++){
            ans[j]|=ans[j-a[i]];
        }
    }
    if(ans[x]==1) printf("YES\n");
    else printf("NO\n");
    return 0;
}
