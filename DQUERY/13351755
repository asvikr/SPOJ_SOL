#include<bits/stdc++.h>
using namespace std;
struct node
{
    int idx;
    int val,l;
    int chk,idx1;
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
bool cmp(const node &a,const node &b)
{
    if(a.idx==b.idx)
        return a.val>b.val;
    return a.idx < b.idx;
}
void update(int tl,int tr,int node,int pos)
{
    if(tl>tr)
        return;
    int mid=(tl+tr)/2;
    if(tl==tr)
    {
        tree[node]^=1;
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
int arr[1000005]={0};
int main()
{
    int n,x;
    //scanf("%d",&n);
    n=read();
    for(int i=1;i<=n;i++)
    {
       // scanf("%d",&x);
       x=read();
        a[i].idx=i;
        a[i].val=x;
        a[i].chk=0;
    }
    int q,l,r;
    scanf("%d",&q);
    for(int i=1;i<=q;i++)
    {
        //scanf("%d %d",&l,&r);
        l=read();
        r=read();
        a[i+n].idx=r;
        a[i+n].chk=1;
        a[i+n].idx1=i;
        a[i+n].l=l;
    }
    sort(a+1,a+n+q+1,cmp);
    int ans[200005];
    for(int i=1;i<=n+q;i++)
    {
        if(a[i].chk)
        {
            ans[a[i].idx1]=query(a[i].l,a[i].idx,1,n,1);
        }
        else
        {
            int num=a[i].val;
            if(arr[num]!=0)
            {
                update(1,n,1,arr[num]);
            }
            update(1,n,1,a[i].idx);
            arr[num]=a[i].idx;
        }
    }
    for(int i=1;i<=q;i++)
        printf("%d\n",ans[i]);
    return 0;
}
