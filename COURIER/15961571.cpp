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
#define inf (int)(1e+8)
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
int mat[105][105];
int dp[105][1<<12],to;
int n,m,b;
vector<pair<int,int> > V;
void clr()
{
    V.clear();
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) mat[i][j]=inf;
    for(int i=0;i<n;i++) mat[i][i]=0;
    memset(dp,-1,sizeof(dp));
}
int solve(int last,int bit)
{
    if(bit==(1<<to)-1) return mat[b][last];
    if(dp[last][bit]!=-1) return dp[last][bit];
    int ret=inf;
    for(int i=0;i<V.size();i++){
        if(!(bit&(1<<i)))
            ret=min(ret,mat[last][V[i].f]+mat[V[i].f][V[i].sc]+solve(V[i].sc,bit|(1<<i)));
    }
   // printf("%d\n",ret);
    return dp[last][bit]=ret;
}
int main()
{
   int t;
   scanf("%d",&t);
   while(t--){
    scanf("%d %d %d",&n,&m,&b);
    clr();
    b--;
    int u,v,w;
    for(int i=0;i<m;i++){
        scanf("%d %d %d",&u,&v,&w);
        --u,--v;
        if(mat[u][v]>w) mat[u][v]=w;
        if(mat[v][u]>w) mat[v][u]=w;
    }
    int z;
    scanf("%d",&z);
    for(int i=0;i<z;i++){
        scanf("%d %d %d",&u,&v,&w);
        u--,v--;
        while(w--) V.pb(mp(u,v));
    }
    for(int k=0;k<n;k++) for(int i=0;i<n;i++) for(int j=0;j<n;j++) mat[i][j]=min(mat[i][j],mat[i][k]+mat[k][j]);
    to=V.size();
    printf("%d\n",solve(b,0));
   }
   return 0;
}
