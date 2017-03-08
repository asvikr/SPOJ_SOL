#include<bits/stdc++.h>
using namespace std;
struct node
{
    int val;
    int idx;
    int l,r;
    int chk;
};
node a[230005];
int tree[100005];
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
inline bool cmp(const node &a,const node &b)
{
    if(a.val!=b.val)
        return a.val > b.val;
    if(a.val==b.val)
        return a.chk < b.chk;

}
void update(int tl,int tr,int node,int pos)
{
    if(tl>tr)
        return;
    int mid=(tl+tr)/2;
    if(tl==tr)
    {
        tree[node]=1;
        return;
    }
    if(mid>=pos)
        update(tl,mid,node*2,pos);
    else
        update(mid+1,tr,node*2+1,pos);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int query(int l,int r,int tl,int tr,int node)
{
    if(tl> tr || l>tr || tl>r)
        return 0;
    if(tl>=l && r>=tr)
        return tree[node];
    int mid=(tl+tr)/2;
    return query(l,r,tl,mid,node*2)+query(l,r,mid+1,tr,node*2+1);
}
int main()
{
    int n;
    n=read();
    //scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        //scanf("%d",&a[i].val);
        a[i].val=read();
        a[i].idx=i;
        a[i].chk=1;
    }
    int q;
    //scanf("%d",&q);
    q=read();
    for(int i=1;i<=q;i++)
    {
       // scanf("%d %d %d",&a[i+n].l,&a[i+n].r,&a[i+n].val);
       a[i+n].l=read();
       a[i+n].r=read();
       a[i+n].val=read();
        a[i+n].chk=0;
        a[i+n].idx=i;
    }
    sort(a+1,a+n+q+1,cmp);
    int ans[200005];
    for(int i=1;i<=n+q;i++)
    {
       // printf("%d %d\n",a[i].val,a[i].chk);
        if(a[i].chk==0)
        {
            ans[a[i].idx]=query(a[i].l,a[i].r,1,n,1);
            //printf("%d\n",ans);
        }
        else
        {
            update(1,n,1,a[i].idx);
        }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
