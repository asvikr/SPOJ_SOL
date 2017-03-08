#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
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
const int N=100005;
vector<int> V[N];
char str[N];
int bit[26][N];
void update(int i,int id,int val)
{
    while(id<N){
        bit[i][id]+=val;
        id+=id&-id;
    }
}
int query(int i,int id)
{
    int ret=0;
    while(id>0){
        ret+=bit[i][id];
        id-=id&-id;
    }
    return ret;
}
int in[N],out[N],timer=0;
void dfs(int cur,int prev)
{
    in[cur]=++timer;
    update(str[cur]-'a',timer,1);
    for(int i=0;i<V[cur].size();i++){
        if(V[cur][i]!=prev){
            dfs(V[cur][i],cur);
        }
    }
    out[cur]=timer;
}
int main()
{
    int n;
    //scanf("%d",&n);
    n=read();
    for(int i=0;i<n-1;i++){
        int u,v;
        //scanf("%d %d",&u,&v);
        u=read();
        v=read();
        V[u].pb(v);
        V[v].pb(u);
    }
    scanf("%s",str+1);
    dfs(1,0);
    int q;
    //scanf("%d",&q);
    q=read();
    while(q--){
        int id;
       // scanf("%d",&id);
       id=read();
        if(id==0){
            int x;
            char s[2];
            //scanf("%d %s",&x,s);
            x=read();
            scanf("%s",s);
            update(str[x]-'a',in[x],-1);
            str[x]=s[0];
            update(str[x]-'a',in[x],1);
        }
        else
        {
            int x;
            scanf("%d",&x);
            int odd=0;
            for(int i=0;i<26;i++){
                int cnt=query(i,out[x])-query(i,in[x]-1);
                if(cnt&1) odd++;
            }
            if(odd==0 || odd==1) printf("YES\n");
            else printf("NO\n");
        }
    }
    return 0;
}
