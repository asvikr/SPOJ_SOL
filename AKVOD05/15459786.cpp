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
int a[N],b[N],c[N];
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n,k;
        memset(c,0,sizeof(c));
        scanf("%d %d",&n,&k);
        map<int,int> Map;
        if(k==1){
            if(n&1) printf("1\n");
            else printf("0\n");
            continue;
        }
        for(int i=0;i<k;i++){
        scanf("%d",&a[i]);
        Map[a[i]]++;
        if(a[i]<N) c[a[i]]=1;
        }
        set<int> S;
        for(int i=0;i<N;i++){
            if(c[i]==0) S.insert(i);
        }
        int cnt=n-k;
        for(int i=0;i<=k;i++){
            b[i]=*S.begin();
            //printf("%d ",b[i]);
            S.erase(S.begin());
            Map[a[i]]--;
            if(Map[a[i]]==0)
            S.insert(a[i]);
        }
        printf("%d\n",b[(cnt-1)%(k+1)]);
    }
    return 0;
}
