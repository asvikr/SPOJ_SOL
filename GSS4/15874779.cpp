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
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
LL max(LL a,LL b,LL c){return max(a,max(b,c));}
//#include<stdio.h>
//typedef long long int LL;
/*LL max(LL a,LL b)
{
    if(a>b) return a;
    else return b;
}*/
/*inline LL power(LL x,LL y)
{
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        y/=2;
    }
    return ans;
}*/
inline LL read()
{
	LL ret = 0;
	LL c = getchar_unlocked();
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
LL a[N];
struct node
{
    LL maxi;
    LL sum;
}tree[4*N];
node combine(node x,node y)
{
    node temp;
    temp.maxi=max(x.maxi,y.maxi);
    temp.sum=x.sum+y.sum;
    return temp;
}
void build(int tl,int tr,int node)
{
    if(tl>tr) return;
    int mid=(tl+tr)/2;
    if(tl==tr){
        tree[node].maxi=a[tl];
        tree[node].sum=a[tl];
        return;
    }
    build(tl,mid,node*2);
    build(mid+1,tr,node*2+1);
    tree[node]=combine(tree[node*2],tree[node*2+1]);
}
void update(int tl,int tr,int l,int r,int node)
{
    if(tl>tr || tl>r || l>tr) return;
    int mid=(tl+tr)/2;
    if(tree[node].maxi<=1) return;
    if(tl==tr){
        LL k=(LL)sqrt(tree[node].maxi);
        tree[node].maxi=k;
        tree[node].sum=k;
        return;
    }
    update(tl,mid,l,r,node*2);
    update(mid+1,tr,l,r,node*2+1);
    tree[node]=combine(tree[node*2],tree[node*2+1]);
}
LL query(int tl,int tr,int l,int r,int node)
{
    if(tl>tr || tl>r || l>tr) return 0;
    int mid=(tl+tr)/2;
    if(tl>=l && tr<=r) return tree[node].sum;
    return query(tl,mid,l,r,node*2)+query(mid+1,tr,l,r,node*2+1);
}
int main()
{
    int n;
    int t=1;
    while(scanf("%d",&n)!=EOF){
    printf("Case #%d:\n",t);
    t++;
    for(int i=1;i<=n;i++) a[i]=read();
    int q;
    q=read();
    build(1,n,1);
    while(q--){
        int id,l,r;
        id=read();l=read();r=read();
        if(l>r) swap(l,r);
        if(id==0) update(1,n,l,r,1);
        else printf("%lld\n",query(1,n,l,r,1));
     }
    }
    return 0;
}
