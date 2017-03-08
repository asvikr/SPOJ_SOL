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
string s[2];
const int N=100;
bool mark[N];
int dp[10][2][N];
int solve(int cur,bool lo,int sum,int i)
{
	if(cur==s[i].size()){
		return !mark[sum];
	}
	int &ret=dp[cur][lo][sum];
	if(ret!=-1) return ret;
	int k=(lo?9:(s[i][cur]-'0'));
	ret=0;	
	for(int d=0;d<=k;d++){
		ret+=solve(cur+1,lo || (d<(s[i][cur]-'0')),sum+d,i);
		//printf("%d %d\n",sum+d,ret);
	}
	//printf("%d\n",ret);
	return ret;
}
int main()
{
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
		cin>>s[0]>>s[1];
		int tp=0;
		for(int i=0;i<s[0].size();i++) tp+=s[0][i]-'0';
		stringstream ss(s[0]);
		ss>>f;
		stringstream ss1(s[1]);
		ss1>>t;
		memset(dp,-1,sizeof(dp));
		int ans=solve(0,0,0,1);
		memset(dp,-1,sizeof(dp));
		ans-=solve(0,0,0,0);
		printf("%d\n",ans+!mark[tp]);
	}
	return 0;
}
