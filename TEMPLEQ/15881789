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
int bit[N]={0};
int n;
void update(int idx,int val)
{
    while(idx<=n){
        bit[idx]+=val;
        idx+=idx&-idx;
    }
}
int query(int idx)
{
    int ret=0;
    while(idx>0){
        ret+=bit[idx];
        idx-=idx&-idx;
    }
    return ret;
}
int lowerbound(int val)
{
    int l=1,r=n;
    if(query(r)<val) return n+1;
    while(l<r){
        int mid=(l+r)>>1;
        if(query(mid)>=val) r=mid;
        else l=mid+1;
    }
    return l;
}
int q;
pair<int,int> p[N];
int ind[N],pos[N];
int main()
{
    n=read();q=read();
    for(int i=1;i<=n;i++){
        p[i].f=read();
        p[i].sc=i;
    }
    sort(p+1,p+n+1);
    for(int i=1;i<=n;i++){
        ind[p[i].sc]=i;
        pos[i]=p[i].sc;
    }
    p[0].f=0;
    for(int i=1;i<=n;i++){
        update(i,p[i].f-p[i-1].f);
    }
    while(q--){
        int ty=read();
        int x=read();
        if(ty==1){
            int y=query(ind[x]);
            int z=pos[lowerbound(y+1)-1];
            swap(ind[x],ind[z]);
            pos[ind[x]]=x;
            pos[ind[z]]=z;
            update(ind[x],1);
            update(ind[x]+1,-1);
        }
        else if(ty==2) printf("%d\n",n+1-lowerbound(x));
        else update(lowerbound(x),-1);

    }
    return 0;
}
