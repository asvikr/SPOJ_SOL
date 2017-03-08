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
LL dp[35][2][2][2];
int a,b,c;
int A[35],B[35],C[35];
LL solve(int i,bool loA,bool loB,bool loK)
{
	if(i==32) return (loA && loB && loK);
	int t1=A[i];
	int t2=B[i];
	int t3=C[i];
	int hiA=(loA ? 1:t1);
	int hiB=(loB ? 1:t2);
	int hiK=(loK ? 1:t3);
	//printf("%d %d %d\n",hiA,hiB,hiK);
	LL &res=dp[i][loA][loB][loK];
	if(res!=-1) return res;
	res=0;
	for(int j=0;j<=hiA;j++){
		for(int k=0;k<=hiB;k++){
			int K=j&k;
			if(K>hiK) continue;
			res+=solve(i+1,loA || (j<t1),loB || (k<t2),loK || (K<t3));
		}
	}
	return res;
}
int main()
{
	int t;
	scanf("%d",&t);
	for(int tt=1;tt<=t;tt++){
		scanf("%d %d %d",&a,&b,&c);
		memset(A,0,sizeof(A));
		memset(B,0,sizeof(B));
		memset(C,0,sizeof(C));
		for(int i=31;i>=0;i--){
			A[31-i]=((1<<i)&a?1:0);
			B[31-i]=((1<<i)&b?1:0);
			C[31-i]=((1<<i)&c?1:0);
		}
		memset(dp,-1,sizeof(dp));
		LL ans=solve(0,0,0,0);
		printf("Case #%d: %lld\n",tt,ans);
	}
	return 0;
}
