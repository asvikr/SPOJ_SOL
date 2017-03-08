#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
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
char A[55],B[55];
LL dp[51][55][55][55];
LL solve(int i,int th,int sx,int nin)
{
	if(!i){
		return (th==sx && sx==nin && th>=1);
	}
	LL &res=dp[i][th][sx][nin];
	if(res!=-1) return res%M;
	res=0;
	for(int d=0;d<=9;d++){
		res+=solve(i-1,th+(d==3),sx+(d==6),nin+(d==9));
		res%=M;
	}
	return res%M;
}
LL dfs(char str[],int i,int th,int sx,int nin,int n)
{
	if(i==n) return (th==sx && sx==nin && th>=1);
	int j;
	LL res=0;
	int x=str[i]-'0';
	res+=dfs(str,i+1,th+(x==3),sx+(x==6),nin+(x==9),n);
	res%=M;
	for(int j=0;j<x;j++){
		res+=solve(n-i-1,th+(j==3),sx+(j==6),nin+(j==9));
		res%=M;
	} 
	return res%M;
}
LL count(char str[],int n)
{
	LL res=dfs(str,0,0,0,0,n)%M;
	/*for(int i=1;i<n;i++){
		res+=solve(n-i,0,0,0);
		if(res>=M) res-=M;
	}*/
	return res%=M;
}
int main()
{
	int t;
	scanf("%d",&t);
	memset(dp,-1,sizeof(dp));
	while(t--){
		scanf("%s %s",A,B);
		int n,m;
		n=strlen(A);
		m=strlen(B);
		bool temp=false;
		int th=0,sx=0,nin=0;
		for(int i=0;i<n;i++){
			sx+=((A[i]-'0')==6);
			th+=((A[i]-'0')==3);
			nin+=((A[i]-'0')==9);
		}
		if(sx==th && th==nin && th>=1) temp=true;
		LL ans=count(B,m);
		ans-=count(A,n);
		ans=(ans+2*M+temp)%M;
		printf("%lld\n",ans);
	}
	return 0;
}
