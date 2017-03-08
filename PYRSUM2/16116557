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
const int N=1000005;
LL tree[4*N];
pair<LL,LL> lazy[4*N];
void update(int tl,int tr,int l,int r,LL a,LL d,int node)
{
	//printf("%d %d %d %d %d %d\n",tl,tr,l,r,a,d);
	LL n;
	if(lazy[node].f!=0){
			n=(tr-tl+1);
			tree[node]+=((2*lazy[node].f+(n-1)*lazy[node].sc)*n)/2;
			if(tl!=tr){
				LL m=(tl+tr)/2;
				lazy[node*2].f+=lazy[node].f;
				lazy[node*2].sc+=lazy[node].sc;
				lazy[node*2+1].f+=lazy[node].f+(m-tl+1)*lazy[node].sc;
				lazy[node*2+1].sc+=lazy[node].sc;
			} 
			lazy[node].f=0;
			lazy[node].sc=0;
	}
	if(tl>tr || tl>r || tr<l || l>r) return;
	int mid=(tl+tr)/2;
	if(tl>=l && tr<=r){
		n=(tr-tl+1);
		tree[node]+=(LL)((2*a+(n-1)*d)*n)/2;
		int m=(tl+tr)/2;
		if(tl!=tr){
			n=m-tl+1;
			lazy[node*2].f+=a;
			lazy[node*2].sc+=d;
			lazy[node*2+1].f+=a+n*d;
			lazy[node*2+1].sc+=d;
		}
		return;
	}
     n=mid-l+1;
	if(n<0) n=0;
	update(tl,mid,l,min(r,mid),a,d,node*2);
	update(mid+1,tr,max(l,mid+1),r,a+n*d,d,node*2+1);
	tree[node]=tree[node*2]+tree[node*2+1];
}
LL query(int tl,int tr,int l,int r,int node)
{
	if(tl>tr || tl>r || tr<l || l>r) return 0;
	int mid=(tl+tr)/2;
	LL n;
	if(lazy[node].f!=0){
			n=(tr-tl+1);
			tree[node]+=((2*lazy[node].f+(n-1)*lazy[node].sc)*n)/2;
			if(tl!=tr){
				int m=(tl+tr)/2;
				lazy[node*2].f+=lazy[node].f;
				lazy[node*2].sc+=lazy[node].sc;
				lazy[node*2+1].f+=lazy[node].f+(m-tl+1)*lazy[node].sc;
				lazy[node*2+1].sc+=lazy[node].sc;
			} 
			lazy[node].f=0;
			lazy[node].sc=0;
	}
	if(tl>=l && tr<=r)
		return tree[node];
	return query(tl,mid,l,r,node*2)+query(mid+1,tr,l,r,node*2+1);
}
int main()
{

		int q;
		q=read();
		char str[10];
		int l,r,mid,w;
		while(q--){
			scanf("%s",str);
			if(str[0]=='b'){
				mid=read();w=read();
				int h=(w+1)/2;
				l=mid-h+1,r=mid+h-1;
				update(1,N-1,l,mid,1,1,1);
				update(1,N-1,mid+1,r,h-1,-1,1);	
			}
			else
			{
				l=read();r=read();
				printf("%lld\n",query(1,N-1,l,r,1));
			}
		}
		printf("\n");
	return 0;
}
