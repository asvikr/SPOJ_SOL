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
const int N=100005;
LL tree[4*N],lazy[4*N];
LL R[N],cum[N],rr;
int n,q;
void update(int tl,int tr,int l,int r,LL st,int node)
{
    if(lazy[node]!=0){
            tree[node]=(tree[node]+(lazy[node]*cum[tr-tl])%M)%M;
            if(tl!=tr){
                lazy[node*2]=(lazy[node*2]+lazy[node])%M;
                int p=(tl+tr)/2-tl+1;
                lazy[node*2+1]=(lazy[node*2+1]+(lazy[node]*R[p])%M)%M;
            }
            lazy[node]=0;
    }
    if(tl>tr || l>tr || tl>r) return;
    int mid=(tl+tr)/2;
    if(tl>=l && tr<=r){
        tree[node]=(tree[node]+(st*cum[tr-tl])%M)%M;
        if(tl!=tr){
            lazy[node*2]=(lazy[node*2]+st)%M;
            int p=mid-tl+1;
            lazy[node*2+1]=(lazy[node*2+1]+(st*R[p])%M)%M;
        }
        return;
    }
        LL p;
        if(r<=mid) p=0;
        else if(l>mid) p=1;
        else
        {
            int k=mid-max(l,tl)+1;
            p=R[k];
        }
        update(tl,mid,l,r,st,node*2);
        update(mid+1,tr,l,r,(st*p)%M,node*2+1);
        tree[node]=(tree[node*2]+tree[node*2+1])%M;
}
LL query(int tl,int tr,int l,int r,int node)
{
    if(tl>tr || l>tr || tl>r) return 0;
     if(lazy[node]!=0){
            tree[node]=(tree[node]+(lazy[node]*cum[tr-tl])%M)%M;
            if(tl!=tr){
                lazy[node*2]=(lazy[node*2]+lazy[node])%M;
                int p=(tl+tr)/2-tl+1;
                lazy[node*2+1]=(lazy[node*2+1]+(lazy[node]*R[p])%M)%M;
            }
            lazy[node]=0;
    }
    if(tl>=l && tr<=r) return tree[node];
    int mid=(tl+tr)/2;
    return (query(tl,mid,l,r,node*2)+query(mid+1,tr,l,r,node*2+1))%M;
}
void upd(int tl,int tr,int pos,int node)
{
    if(lazy[node]!=0){
            tree[node]=(tree[node]+(lazy[node]*cum[tr-tl])%M)%M;
            if(tl!=tr){
                lazy[node*2]=(lazy[node*2]+lazy[node])%M;
                int p=(tl+tr)/2-tl+1;
                lazy[node*2+1]=(lazy[node*2+1]+(lazy[node]*R[p])%M)%M;
            }
            lazy[node]=0;
    }
    if(!(tl<=pos && pos<=tr)) return;
    if(tl==tr){
        tree[node]=0;
        return;
    }
    int mid=(tl+tr)/2;
    upd(tl,mid,pos,node*2);
    upd(mid+1,tr,pos,node*2+1);
    tree[node]=(tree[node*2]+tree[node*2+1])%M;
}
int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    n=read();
    rr=(LL)read();
    q=read();
    //scanf("%d %lld %d",&n,&rr,&q);
    R[0]=1;
    cum[0]=1;
    for(int i=1;i<=n;i++){
        R[i]=(R[i-1]*rr)%M;
        cum[i]=(cum[i-1]+R[i])%M;
    }
    int id,l,r;
    LL st;
    while(q--){
        id=read();
        //scanf("%d",&id);
        if(id==0){
            st=(LL)read();l=read();r=read();
            //scanf("%lld %d %d",&st,&l,&r);
            update(1,n,l,r,st,1);
        }
        else if(id==1)
        {
            l=read();r=read();
            //scanf("%d %d",&l,&r);
            LL ans=query(1,n,l,r,1);
            printf("%lld\n",ans%M);
        }
        else
        {
           l=read();
           //scanf("%d",&l);
            upd(1,n,l,1);
        }
    }
    return 0;
}
