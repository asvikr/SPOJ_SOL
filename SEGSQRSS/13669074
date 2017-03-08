#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL a[1000005],tree[4000005];
void build(int tl,int tr,int node)
{
    if(tl>tr)
    return;
    if(tl==tr)
    {
        tree[node]=a[tl]*a[tl];
        return;
    }
    int mid=(tl+tr)/2;
    build(tl,mid,node*2);
    build(mid+1,tr,node*2+1);
    tree[node]=tree[node*2]+tree[node*2+1];
}
LL query(int tl,int tr,int l,int r,int node)
{
    if(tl>tr || tl>r || tr<l)
        return 0;
    if(tl>=l && tr<=r)
        return tree[node];
    int mid=(tl+tr)/2;
    return query(tl,mid,l,r,node*2)+query(mid+1,tr,l,r,node*2+1);
}
void update(int tl,int tr,int l,int r,int val,int node,int ch)
{
    if(tl>tr || tl>r || tr<l)
        return;
    if(tl==tr)
    {
        if(ch==0)
        tree[node]=val*val;
        else
            tree[node]=pow((sqrt(tree[node])+val),2);
    return;
    }
    int mid=(tl+tr)/2;
    update(tl,mid,l,r,val,node*2,ch);
    update(mid+1,tr,l,r,val,node*2+1,ch);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case %d:\n",i);
        int n,m;
        scanf("%d %d",&n,&m);
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        int k,l,r,val;
        build(1,n,1);
        while(m--)
        {
            scanf("%d",&k);
             scanf("%d %d",&l,&r);
            if(k==2)
            {
                printf("%lld\n",query(1,n,l,r,1));
            }
            else if(k==0)
            {
                scanf("%d",&val);
                update(1,n,l,r,val,1,0);
            }
            else
            {
                scanf("%d",&val);
                update(1,n,l,r,val,1,1);
            }
        }
    }
    return 0;
}
