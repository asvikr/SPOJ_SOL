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
map<pair<int,int>,int> mapp[15];
map<pair<int,int>,int> mark[15];
int solve(int len,int a,int b)
{
    if(len==0){
        if(a==0 && b==0) return 1;
        else return 0;
    }
    pair<int,int> pos=mp(a,b);
    if(mark[len][pos]==1) return mapp[len][pos];
    int cnt=0;
    cnt+=solve(len-1,a,b-1)+solve(len-1,a,b+1)+solve(len-1,a+1,b-1)+solve(len-1,a-1,b+1)+solve(len-1,a-1,b)+solve(len-1,a+1,b);
    mark[len][pos]=1;
    return mapp[len][pos]=cnt;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        for(int i=0;i<15;i++) mapp[i].clear(),mark[i].clear();
        int n;
        scanf("%d",&n);
        printf("%d\n",solve(n,0,0));
    }
    return 0;
}

