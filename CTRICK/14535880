#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
//#define getchar_unlocked getchar
#define f first
#define sc second
#define M 1000000007
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
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
	int ret = 0;
	int c = getchar_unlocked();

	while(c<'0' || c>'9')
		c = getchar_unlocked();
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
int tree[4*20000],a[20005];
void build(int tl,int tr,int node)
{
    if(tl==tr)
    {
        tree[node]=1;
        return;
    }
    int mid=(tl+tr)/2;
    build(tl,mid,node*2);
    build(mid+1,tr,node*2+1);
    tree[node]=tree[node*2]+tree[node*2+1];
}
void update(int tl,int tr,int pos,int node)
{
    if(tl>tr)
        return;
    if(tl==tr){
        tree[node]=0;
        return;
    }
    int mid=(tl+tr)/2;
    if(mid>=pos)
        update(tl,mid,pos,node*2);
    else
        update(mid+1,tr,pos,node*2+1);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int query(int tl,int tr,int l,int r,int node)
{
    if(tl>tr || l>tr || tl>r)
        return 0;
    if(tl>=l && tr<=r)
        return tree[node];
    int mid=(tl+tr)/2;
    return query(tl,mid,l,r,node*2)+query(mid+1,tr,l,r,node*2+1);
}
int solve(int tl,int tr,int sum,int node)
{
    int mid=(tl+tr)/2;
    if(tl==tr)
        return tl;
    if(tree[node*2]>=sum){
        solve(tl,mid,sum,node*2);
    }
    else
        solve(mid+1,tr,sum-tree[node*2],node*2+1);
}
int main()
{
    int t;
   // scanf("%d",&t);
   t=read();
    while(t--){
        memset(a,0,sizeof(a));
        int n;
        //scanf("%d",&n);
        n=read();
         build(1,n,1);
         if(n==1)
        {
        printf("1\n");
        continue;
        }
        if(n==2)
        {
        printf("2 1\n");
        continue;
        }
        a[2]=1;
        update(1,n,2,1);
        int placed=1;
        int cur=2;
        for(int i=3;i<=n+1;i++){
            int x=i+query(1,n,1,cur-1,1);
            x=x%(n-placed);
            if(x==0)
                x=n-placed;
            int pos=solve(1,n,x,1);
            update(1,n,pos,1);
            a[pos]=i-1;
            placed++;
            cur=pos;
        }
        for(int i=1;i<=n;i++)
            printf("%d ",a[i]);
        printf("\n");
    }
    return 0;
}

