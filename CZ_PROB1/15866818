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
vector<int> v;
bool isprime(int x)
{
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return false;
    }
    return true;
}
LL dp[8005][4];
/*LL solve(int x,int k)
{
    if(x<k) return 0;
    if(x==k) return 1;
    if(k==1) return 1;
    LL &ret=dp[x][k];
    if(ret!=-1) return ret;
    ret=0;
    for(int i=1;i<=k;i++) ret+=solve(x-k,i);
    return ret;

}*/
int main()
{
    for(int i=1;i<=90;i++){
        for(int j=i;j<=90;j++){
            int x=i*i+j*j;
            if(isprime(x))
                v.pb(x);
        }
    }
    sort(v.begin(),v.end());
    //memset(dp,-1,sizeof(dp));
    for(int i=0;i<8000;i++) dp[i][1]=1;
    dp[0][2]=dp[0][3]=1;
    for(int k=2;k<=3;k++){
        for(int i=1;i<8000;i++){
            dp[i][k]=dp[i][k-1];
            if(i>=k) dp[i][k]+=dp[i-k][k];
        }
    }
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k;
        scanf("%d %d",&n,&k);
        //LL ans=1;
       // for(int i=2;i<=k;i++) ans+=solve(v[n-1],i);
        printf("%lld\n",dp[v[n-1]][k]);
    }
    return 0;
}

