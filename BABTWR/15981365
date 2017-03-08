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
struct node
{
    int l,b,h;
};
vector<node> V;
bool cmp(node x,node y)
{
    if(x.l==y.l) return x.b>y.b;
    return x.l>y.l;
}
int dp[200];
int main()
{
    while(true){
        int n;
        scanf("%d",&n);
        if(n==0) return 0;
        V.clear();
        vector<int> a(3);
        for(int i=0;i<n;i++){
        scanf("%d %d %d",&a[0],&a[1],&a[2]);
        sort(a.begin(),a.end());
        do
        {
            V.pb({a[0],a[1],a[2]});

        }while(next_permutation(a.begin(),a.end()));
        }
        sort(V.begin(),V.end(),cmp);
        int ans=0;
        for(int i=0;i<V.size();i++){
            dp[i]=0;
            for(int j=i-1;j>=0;j--){
                if(V[i].b<V[j].b && V[i].l<V[j].l){
                dp[i]=max(dp[i],dp[j]);
                }
            }
            dp[i]+=V[i].h;
            ans=max(ans,dp[i]);
        }
        printf("%d\n",ans);

    }
    return 0;
}
