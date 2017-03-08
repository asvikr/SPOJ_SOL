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

#define MAX_V1 50000
#define MAX_V2 50000
#define MAX_E 150000

int V1,V2,l[MAX_V1],r[MAX_V2];
int E,to[MAX_E],nxt[MAX_E],last[MAX_V1];
bool visited[MAX_V1];

void init(){
	memset(last,-1,sizeof(int)*V1);
	E = 0;
}
 
void add_edge(int u, int v){
	to[E] = v, nxt[E] = last[u]; last[u] = E; ++E;
}

bool pairup(int u){
    if (visited[u])  return false;
    visited[u] = true;
    
    for(int e = last[u];e!=-1;e = nxt[e]){
        int v = to[e];
        
        if(r[v]==-1 || pairup(r[v])){
            l[u] = v;
            r[v] = u;
            return true;
        }
    }
    
    return false;
}

int hopcroft_karp(){
    bool change = true;
    memset(l,-1,sizeof(int)*V1);
    memset(r,-1,sizeof(int)*V2);
    
    while(change){
        change = false;
        memset(visited,false,sizeof(bool)*V1);
        
        for(int i = 0;i<V1;++i)
            if(l[i]==-1) change |= pairup(i);
    }
    
    int ret = 0;
    
    for(int i = 0;i<V1;++i)
        if(l[i]!=-1) ++ret;
    
    return ret;
}

int main(){
	int e,u,v;
	V1=read();V2=read();e=read();
	init();
	
	while(e--){
		//scanf("%d %d",&u,&v);
		u=read();v=read();
		--u; --v;
		add_edge(u,v);
	}
	
	printf("%d\n",hopcroft_karp());
	
	return 0;
}