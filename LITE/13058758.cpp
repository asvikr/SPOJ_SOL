#include<iostream>
#include<cstdio>
using namespace std;
int tree[400005];
int lazy[400005];
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
void update(int tl,int tr,int l,int r,int node)
{
    int mid=(tl+tr)/2;
    if(lazy[node])
    {
        tree[node]=(tr-tl+1)-tree[node];
        if(tl!=tr)
        {
            lazy[node*2]^=1;
            lazy[node*2+1]^=1;
        }
        lazy[node]=0;
    }
    if(tl>tr || l>tr || tl>r)
        return;
    if(tl>=l && r>=tr)
    {
        tree[node]=(tr-tl+1)-tree[node];
        if(tl!=tr)
        {
            lazy[node*2]^=1;
            lazy[node*2+1]^=1;
        }
        return;
    }
    update(tl,mid,l,r,node*2);
    update(mid+1,tr,l,r,node*2+1);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int query(int tl,int tr,int l,int r,int node)
{
    if(tl>tr || l>tr || tl>r)
        return 0;
    int mid=(tl+tr)/2;
    if(lazy[node])
    {
        tree[node]=(tr-tl+1)-tree[node];
        if(tl!=tr)
        {
            lazy[node*2]^=1;
            lazy[node*2+1]^=1;
        }
        lazy[node]=0;
    }
    if(tl>=l && r>=tr)
        return tree[node];
    return query(tl,mid,l,r,node*2)+query(mid+1,tr,l,r,node*2+1);
}
int main()
{
    int n,m;
    n=read();
    m=read();
    //scanf("%d %d",&n,&m);
    int i,x,y;
    while(m--)
    {
        i=read();
        x=read();
        y=read();
        //scanf("%d %d %d",&i,&x,&y);
        if(i==0)
        {
            update(1,n,x,y,1);
        }
        else
            printf("%d\n",query(1,n,x,y,1));
    }
    return 0;
}
