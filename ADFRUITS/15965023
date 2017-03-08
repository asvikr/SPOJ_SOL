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
char s1[105],s2[105];
string com="";
int n,m;
int dp[105][105];
void solve(int i,int j)
{
    if(i==0 || j==0) return;
    if(s1[i-1]==s2[j-1]){
        com+=s1[i-1];
        //cout<<com<<endl;
        solve(i-1,j-1);
    }
    else
    {
        if(dp[i-1][j]>dp[i][j-1]) solve(i-1,j);
        else solve(i,j-1);
    }
}
int main()
{
    while(scanf("%s %s",s1,s2)!=EOF){
        n=strlen(s1);
        m=strlen(s2);
        memset(dp,0,sizeof(dp));
        com="";
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 || j==0)
                    dp[i][j]=0;
                else
                {
                    if(s1[i-1]==s2[j-1])
                        dp[i][j]=dp[i-1][j-1]+1;
                    else
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        solve(n,m);
        reverse(all(com));
        int i=0,j=0,k=0;
        string ans;
        while(i<n && j<m){
            if(s1[i]==com[k] && s2[j]==com[k]){
                ans+=com[k];
                i++;k++;j++;
            }
            else
            {
                if(s1[i]!=com[k]){
                    ans+=s1[i];
                    i++;
                }
                else if(s2[j]!=com[k]){
                    ans+=s2[j];
                    j++;
                }
            }
        }
        while(i<n) ans+=s1[i++];
        while(j<m) ans+=s2[j++];
        cout<<ans<<endl;
    }
    return 0;
}

