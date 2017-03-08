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
char str[105],ch[105];
LL a[105];
LL dp[105][105];
int n,j,k;
LL solve(int l,int r)
{
    if(l==r) return a[l];
    if(dp[l][r]!=-1) return dp[l][r];
    LL maxi=LONG_LONG_MIN;
    for(int i=l;i<r;i++){
        LL left=solve(l,i);
        LL right=solve(i+1,r);
        LL ans;
        if(ch[i]=='+')
           ans=left+right;
        else ans=left*right;
        maxi=max(ans,maxi);
    }
    return (dp[l][r]=maxi);
}
LL solve1(int l,int r)
{
    if(l==r) return a[l];
    if(dp[l][r]!=-1) return dp[l][r];
    LL mini=LONG_LONG_MAX;
    for(int i=l;i<r;i++){
        LL left=solve1(l,i);
        LL right=solve1(i+1,r);
        LL ans;
        if(ch[i]=='+')
           ans=left+right;
        else ans=left*right;
        mini=min(ans,mini);
    }
    return (dp[l][r]=mini);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        memset(dp,-1,sizeof(dp));
        scanf("%s",str);
        n=strlen(str);
        j=0,k=0;
        for(int i=0;i<n;i++){
            if(str[i]>='0' && str[i]<='9'){
                a[j++]=str[i]-'0';
            }
            else ch[k++]=str[i];
        }
        printf("%lld ",solve(0,j-1));
        memset(dp,-1,sizeof(dp));
        printf("%lld\n",solve1(0,j-1));
    }
    return 0;
}

