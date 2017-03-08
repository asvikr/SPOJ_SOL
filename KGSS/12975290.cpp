#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[100005];
struct node
{
    int max1;
    int max2;
};
node tree[400005];
node makedata(int x)
{
    node temp;
    temp.max1=x;
    temp.max2=-1;
    return temp;
}
node combine(node l,node r)
{
    node temp;
    temp.max1=max(l.max1,r.max1);
    if(temp.max1==r.max1)
    {
    temp.max2=max(l.max1,r.max2);
    }
    else
        temp.max2=max(l.max2,r.max1);
    return temp;
}
void build(int l,int r,int node)
{
    if(l==r)
        tree[node]=makedata(a[l]);
    else
    {
        int mid=(l+r)/2;
        build(l,mid,node*2);
        build(mid+1,r,node*2+1);
        tree[node]=combine(tree[node*2],tree[node*2+1]);
    }
}
node query(int tl,int tr,int l,int r,int nod)
{
    if(tl>tr || tl>r || l>tr)
    return makedata(-999);
   if(tl>=l && r>=tr)
   return tree[nod];
    int mid=(tl+tr)/2;
    return combine(query(tl,mid,l,r,nod*2),query(mid+1,tr,l,r,nod*2+1));
}
void update(int tl,int tr,int pos,int val,int node)
{
    if(tl==tr)
        tree[node]=makedata(val);
    else
    {
        int mid=(tl+tr)/2;
        if(pos<=mid)
            update(tl,mid,pos,val,node*2);
        else
            update(mid+1,tr,pos,val,node*2+1);
        tree[node]=combine(tree[node*2],tree[node*2+1]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    build(1,n,1);
   int q;
    scanf("%d",&q);
    char str[2];
    int l,r;
    while(q--)
    {
        scanf("%s",str);
        scanf("%d%d",&l,&r);
        if(str[0]=='Q')
        {
           node temp=query(1,n,l,r,1);
            printf("%d\n",temp.max1+temp.max2);
        }
        else
            update(1,n,l,r,1);

    }
    return 0;
}
