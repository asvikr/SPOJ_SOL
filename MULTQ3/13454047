#include<bits/stdc++.h>
using namespace std;
struct node
{
    int num0;
    int num1;
    int num2;
};
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
node tree[300005];
int lazy[300005];
void build(int tl,int tr,int node)
{
    if(tl>tr)
        return;
    if(tl==tr)
    {
        tree[node].num0=1;
        return;
    }
    int mid=(tl+tr)/2;
    build(tl,mid,node*2);
    build(mid+1,tr,node*2+1);
    tree[node].num0=tree[node*2].num0+tree[node*2+1].num0;
}
void update(int l,int r,int tl,int tr,int node)
{
     if(lazy[node]!=0)
    {
        if(lazy[node]==1)
        {
        swap(tree[node].num0, tree[node].num1);
        swap(tree[node].num0, tree[node].num2);
        }
        else
        {
        swap(tree[node].num0, tree[node].num1);
        swap(tree[node].num1, tree[node].num2);

        }
        if(tl!=tr)
        {
            lazy[node*2]=(lazy[node*2]+lazy[node])%3;
            lazy[node*2+1]=(lazy[node*2+1]+lazy[node])%3;
        }
        lazy[node]=0;
    }
    if(tl>tr || l>tr || r<tl)
        return;

    if(tl>=l && r>=tr)
    {
        swap(tree[node].num0, tree[node].num1);
        swap(tree[node].num0, tree[node].num2);
        if(tl!=tr)
        {
        lazy[node*2]=(lazy[node*2]+1)%3;
        lazy[node*2+1]=(lazy[node*2+1]+1)%3;
        }
        return;
    }
    int mid=(tl+tr)/2;
    update(l,r,tl,mid,node*2);
    update(l,r,mid+1,tr,node*2+1);
    tree[node].num0=tree[node*2].num0+tree[node*2+1].num0;
    tree[node].num1=tree[node*2].num1+tree[node*2+1].num1;
    tree[node].num2=tree[node*2].num2+tree[node*2+1].num2;
}
int query(int l,int r,int tl,int tr,int node)
{
    if(tl>tr || l>tr || r<tl)
    return 0;
    if(lazy[node]!=0)
    {
       if(lazy[node]==1)
        {
        swap(tree[node].num0, tree[node].num1);
        swap(tree[node].num0, tree[node].num2);
        }
        else
        {
        swap(tree[node].num0, tree[node].num1);
        swap(tree[node].num1, tree[node].num2);

        }
        if(tl!=tr)
        {
            lazy[node*2]=(lazy[node*2]+lazy[node])%3;
            lazy[node*2+1]=(lazy[node*2+1]+lazy[node])%3;
        }
        lazy[node]=0;
    }
    if(tl>=l && r>=tr)
    {
        return tree[node].num0;
    }
     int mid=(tl+tr)/2;
    return query(l,r,tl,mid,node*2)+query(l,r,mid+1,tr,node*2+1);
}
int main()
{
    int n,q;
    scanf("%d %d",&n,&q);
  // n=read();
   //q=read();
   build(1,n,1);
   int i,a,b;
    while(q--)
    {
       scanf("%d %d %d",&i,&a,&b);
       //i=read();
       //a=read();
       //b=read();
        a++;
        b++;
        if(i==0)
        {
            update(a,b,1,n,1);
        }
        else
        {
            printf("%d\n",query(a,b,1,n,1));
        }
    }
    return 0;
}
