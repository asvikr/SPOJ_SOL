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
const int N=20005;
int tree[4*N],a[N];
void build(int tl,int tr,int node)
{
    if(tl==tr){
        tree[node]=a[tl];
        return;
    }
    int mid=(tl+tr)/2;
    build(tl,mid,node*2);
    build(mid+1,tr,node*2+1);
    tree[node]=tree[node*2]&tree[node*2+1];
}
int query(int tl,int tr,int l,int r,int node)
{
    if(tl>tr || tl>r || tr<l) return (1<<30)-1;
    if(tl>=l && tr<=r) return tree[node];
    int mid=(tl+tr)/2;
    return query(tl,mid,l,r,node*2)&query(mid+1,tr,l,r,node*2+1);
}
int main()
{
    int t;
    t=read();
    while(t--){
        int n,k;
        n=read();k=read();
        int ans;
        for(int i=0;i<n;i++){
            a[i]=read();
            if(i==0) ans=a[i];
            else ans&=a[i];
        }
        build(0,n-1,1);
        if(k>=n/2){
            for(int i=0;i<n;i++)
            printf("%d ",ans);
        }
        else
        {
            for(int i=0;i<n;i++){
                int l=(i-k+n)%n;
                int r=(i+k)%n;
                int x=a[i];
                if(l>r){
                    if(i<r)
                        x&=query(0,n-1,0,r,1)&query(0,n-1,l,n-1,1);
                    if(r<i)
                        x&=query(0,n-1,l,n-1,1)&query(0,n-1,0,r,1);
                }
                else
                {
                    x&=query(0,n-1,l,i-1,1)&query(0,n-1,i+1,r,1);
                }
                printf("%d ",x);
            }
        }
        printf("\n");
    }
    return 0;
}

