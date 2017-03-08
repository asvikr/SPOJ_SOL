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
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
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
int a[10005],cum[10005];
struct node
{
    int sum;
    int pref;
    int suff;
    int ans;
};
node tree[40005];
node makedata(int val)
{
    node temp;
    temp.sum=val;
    temp.pref = temp.suff = temp.ans = val;
    return temp;
}
node combine(node l,node r)
{
   if(l.sum==-inf) return r;
   if(r.sum==-inf) return l;
   node res;
   res.sum = l.sum + r.sum;
   res.pref = max(l.pref,l.sum + r.pref);
   res.suff = max(r.suff,r.sum + l.suff);
   res.ans = max(max(l.ans,r.ans),l.suff + r.pref);
   return res;
}
void buildtree(int l,int r,int node)
{
    if(l==r)
    {
        tree[node]=makedata(a[l]);
        return;
    }
    int mid=(l+r)/2;
     buildtree(l,mid,node*2);
     buildtree(mid+1,r,node*2+1);
    tree[node]=combine(tree[node*2],tree[node*2+1]);

}
node query(int st,int en,int l,int r,int node)
{
    if(st>en || st>r || en<l) return makedata(-inf);
    int mid=(st+en)/2;
    if(st>=l && en<=r) return tree[node];
    return combine(query(st,mid,l,r,node*2),query(mid+1,en,l,r,node*2+1));
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        memset(tree,0,sizeof(tree));
        scanf("%d",&n);
        for(int i=1;i<=n;i++) {
        scanf("%d",&a[i]);
        cum[i]=cum[i-1]+a[i];
        }
        buildtree(1,n,1);
        int q;
        scanf("%d",&q);
        while(q--){
            int x1,y1,x2,y2;
            scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
            if(x1==y1 && y1==x2 && x2==y2){
                printf("%d\n",a[x1]);
                continue;
            }
            int ans=0;
            if(y1<x2){
                node temp1=query(1,n,x1,y1,1);
                node temp2=query(1,n,x2,y2,1);
                ans+=cum[x2-1]-cum[y1];
                ans+=temp1.suff+temp2.pref;
                printf("%d\n",ans);
            }
            else
            {
                node temp1=query(1,n,x1,x2,1);
                node temp2=query(1,n,x2+1,y2,1);
                node temp3=query(1,n,x1,y1,1);
                node temp4=query(1,n,y1+1,y2,1);
                ans=max(max(temp1.suff+temp2.pref,temp1.suff),max(temp3.suff+temp4.pref,temp3.suff));
                ans=max(ans,query(1,n,x2,y1,1).ans);
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}
