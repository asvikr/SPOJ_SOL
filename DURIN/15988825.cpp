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
char txt[500005];
char pat[10005];
bool mark[500005];
int lps[10005],m,n;
LL dp[500005];
void buildlps()
{
    int len=0,i=1;
    lps[0]=0;
    while(i<n){
        if(pat[i]==pat[len]) lps[i++]=++len;
        else
        {
            if(len!=0) len=lps[len-1];
            else lps[i]=0,i++;
        }
    }
}
void kmp()
{
    buildlps();
    int i=0,j=0;
    while(j<m){
        if(pat[i]==txt[j]) i++,j++;
        if(i==n){
            mark[j]=1;
            i=lps[i-1];
        }
        else if(pat[i]!=txt[j]){
            if(i!=0) i=lps[i-1];
            else j++;
        }
    }
}
int main()
{
    scanf("%s %s",pat,txt);
    n=strlen(pat),m=strlen(txt);
    kmp();
        dp[0]=1;
    for(int i=1;i<=m;i++){
        dp[i]=dp[i-1];
        if(mark[i]){
            dp[i]=dp[i-1]+dp[i-n];
        }
    if(dp[i]>=M) dp[i]-=M;
        //printf("%lld %d\n",dp[i],mark[i]);
    }
    printf("%lld\n",(dp[m]-1+M)%M);
}

