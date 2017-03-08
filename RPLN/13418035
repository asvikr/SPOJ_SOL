#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int tree[3000005];
/*inline int read()
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
}*/
void build(int tl,int tr,int node)
{
    if(tl>tr)
        return;
    if(tl==tr)
    {
        tree[node]=a[tl];
        return;
    }
    int mid=(tl+tr)/2;
    build(tl,mid,node*2);
    build(mid+1,tr,node*2+1);
    tree[node]=min(tree[node*2],tree[node*2+1]);
    return;
}
int query(int tl,int tr,int l,int r,int node)
{
    if(tl>tr || l>tr || tl>r)
        return INT_MAX;
    int mid=(tl+tr)/2;
    if(tl>=l && r>=tr)
        return tree[node];
    return min(query(tl,mid,l,r,node*2),query(mid+1,tr,l,r,node*2+1));
}
int main()
{
    int n,t;
    scanf("%d",&t);
    //t=read();
    for(int k=1;k<=t;k++)
    {
    printf("Scenario #%d:\n",k);
    scanf("%d",&n);
    //n=read();
    int q,l,r;
    //q=read();
    scanf("%d",&q);
    for(int i=1;i<=n;i++)
    //a[i]=read();
    scanf("%d",&a[i]);
    build(1,n,1);
    while(q--)
    {
       // l=read();
       // r=read();
        scanf("%d %d",&l,&r);
        printf("%d\n",query(1,n,l,r,1));
    }
    }
    return 0;
}
