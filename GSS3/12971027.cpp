#include<iostream>
#include<cstdio>
using namespace std;
int a[50005];
struct node
{
    int sum;
    int pref;
    int suff;
    int ans;
};
node tree[200005];
node makedata(int val)
{
    node temp;
    temp.sum=val;
    temp.pref = temp.suff = temp.ans = max(-1000000,val);
    return temp;
}
node combine(node l,node r)
{
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
    }
    else
    {
    int mid=(l+r)/2;
     buildtree(l,mid,node*2);
     buildtree(mid+1,r,node*2+1);
    tree[node]=combine(tree[node*2],tree[node*2+1]);
    }
}
node query(int st,int en,int l,int r,int node)
{
   if(st==l && en==r)
    return tree[node];
    int mid=(st+en)/2;
   if(r<=mid)
    return query(st,mid,l,r,node*2);
   if(l>mid)
   {
       return query(mid+1,en,l,r,node*2+1);
   }
    return combine(query(st,mid,l,mid,node*2),query(mid+1,en,mid+1,r,node*2+1));
}
void modify(int tl,int tr,int pos,int val,int node)
{
    if(tl==tr)
        tree[node]=makedata(val);
    else
    {
        int m = (tl+tr)/2;
        if(pos<=m)
            modify(tl,m,pos,val,node*2);
        else
            modify(m+1,tr,pos,val,node*2+1);
        tree[node] = combine(tree[node*2],tree[node*2+1]);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    buildtree(1,n,1);
    int m,x,y;
    scanf("%d",&m);
    int sel;
    while(m--)
    {
        scanf("%d%d%d",&sel,&x,&y);
        if(sel==1)
        printf("%d\n",query(1,n,x,y,1).ans);
        else
            modify(1,n,x,y,1);
    }
    return 0;
}
