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
int p[12];
const int N=120;
bool mark[N];
int dp[12][2][N][N];
int n;
int solve(int cur,bool lo,int ev,int odd)
{
	if(cur==12){
		if(ev-odd<=0) return 0;
		//printf("%d %d\n",ev,odd);
		return (mark[ev-odd]==false);
	}
	int &ret=dp[cur][lo][ev][odd];
	if(ret!=-1) return ret;
	int k=(lo?9:p[cur]);
	ret=0;	
	for(int d=0;d<=k;d++){
		if((11-cur)%2==0)
		ret+=solve(cur+1,lo || (d<p[cur]),ev,odd+d);
		else ret+=solve(cur+1,lo || (d<p[cur]),ev+d,odd);
		//printf("%d %d %d\n",ev,odd,ret);
	}
	//printf("%d\n",ret);
	return ret;
}
int tp=0;
void fun(int x)
{
	memset(p,0,sizeof(p));
	int i=11;
	while(x>0){
		p[i]=x%10;
		if((11-i)%2==0) tp-=p[i];
		else tp+=p[i];
		x/=10;i--;
	}
}
int main()
{
	mark[0]=1;
	mark[1]=1;
	mark[2]=0;
	for(int i=4;i<N;i+=2) mark[i]=1;
	for(int i=3;i*i<N;i+=2)
		if(!mark[i])
			for(int j=i*i;j<N;j+=2*i) mark[j]=1;
	int t;
	scanf("%d",&t);
	while(t--){
		int f,t;
		scanf("%d %d",&f,&t);
		tp=0;
		fun(t);
		memset(dp,-1,sizeof(dp));
		int ans=solve(0,0,0,0);
		memset(dp,-1,sizeof(dp));
		tp=0;
		fun(f);
		ans-=solve(0,0,0,0);
		printf("%d\n",ans+(tp>0 && mark[tp]==0));
	}
	return 0;
}
