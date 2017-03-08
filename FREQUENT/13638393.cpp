#include<bits/stdc++.h>
using namespace std;
int a[100005];
struct node
{
    int lval,lmax;
    int rval,rmax;
    int tval,tmax;
};
node tree[300005];
node merge_node(node x,node y)
{
    node res;
    if(x.lval==y.rval)
    {
        res.tval=res.lval=res.rval=x.lval;
        res.tmax=res.lmax=res.rmax=x.lmax+y.rmax;
    }
    else
    {
        res.lval=x.lval;
        res.lmax=x.lmax;
        res.rval=y.rval;
        res.rmax=y.rmax;
        if(x.lval==y.lval)
        {
            res.lmax=x.lmax+y.lmax;
        }
        if(x.rval==y.rval)
        {
            res.rmax=x.rmax+y.rmax;
        }
        if(x.tmax>y.tmax)
            res.tmax=x.tmax;
        else
            res.tmax=y.tmax;
        if(x.rval==y.lval)
        {
            int temp=x.rmax+y.lmax;
            if(temp>res.tmax)
            {
                res.tmax=temp;
                res.tval=x.rval;
            }
        }
    }
    return res;
}
void make_tree(int tl,int tr,int node)
{
    if(tl>tr)
        return;
    int mid=(tl+tr)/2;
    if(tl==tr)
    {
        tree[node].lval=a[tl];
        tree[node].lmax=1;
        tree[node].rval=a[tl];
        tree[node].rmax=1;
        tree[node].tval=a[tl];
        tree[node].tmax=1;
        return;
    }
    make_tree(tl,mid,node*2);
    make_tree(mid+1,tr,node*2+1);
    tree[node]=merge_node(tree[node*2],tree[node*2+1]);
}
node query(int l,int r,int tl,int tr,int node)
{
    if(l==tl && r==tr)
        return tree[node];
    int mid=(tl+tr)/2;
    if(mid>=r)
    return query(l,r,tl,mid,node*2);
    if(l>mid)
    return query(l,r,mid+1,tr,node*2+1);
    return merge_node(query(l,mid,tl,mid,node*2),query(mid+1,r,mid+1,tr,node*2+1));
}
int main()
{
    int n,q;
    while(1){
    scanf("%d",&n);
    if(n==0)
        return 0;
    scanf("%d",&q);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    make_tree(1,n,1);
    int l,r;
    while(q--)
    {
        scanf("%d %d",&l,&r);
        printf("%d\n",query(l,r,1,n,1).tmax);
    }
    }
    return 0;
}
