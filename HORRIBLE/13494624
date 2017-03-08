#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL tree[400050];
LL lazy[400050];
LL a[100010];
LL val;
void update(LL l,LL r,LL tl,LL tr,LL node)
{
    if(lazy[node]!=0)
    {
        tree[node]+=(tr-tl+1)*lazy[node];
        if(tl!=tr)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(tl>tr || l>tr || r<tl)
    return;
    if(tl>=l && tr<=r)
    {
        LL k=(tr-tl+1)*val;
        tree[node]+=k;
        //printf("%lld\n",tree[node]);
        if(tl!=tr)
        {
        lazy[node*2]+=val;
        lazy[node*2+1]+=val;
        }
        return;
    }
    LL mid=(tl+tr)/2;
    //prLLf("%d %d %d\n",tl,tr,mid);
    update(l,r,tl,mid,node*2);
    update(l,r,mid+1,tr,node*2+1);
    tree[node]=tree[node*2]+tree[node*2+1];
}
LL query(LL l,LL r,LL tl,LL tr,LL node)
{
    if(tl>tr || l>tr || r<tl)
        return 0;
     if(lazy[node]!=0)
    {
        tree[node]+=(tr-tl+1)*lazy[node];
        if(tl!=tr)
        {
            lazy[node*2]+=lazy[node];
            lazy[node*2+1]+=lazy[node];
        }
        lazy[node]=0;
    }
    if(tl>=l && tr<=r)
        return tree[node];
    LL mid=(tl+tr)/2;
    return query(l,r,tl,mid,node*2)+query(l,r,mid+1,tr,node*2+1);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n,c,l,r;
        int i;
        scanf("%lld %lld",&n,&c);
        memset(tree,0,sizeof(tree));
        memset(lazy,0,sizeof(lazy));
        while(c--)
        {
            scanf("%d %lld %lld",&i,&l,&r);
            if(i==0)
            {
                scanf("%lld",&val);
                update(l,r,(LL)1,n,1);
            }
            else
                printf("%lld\n",query(l,r,1,n,1));
        }
    }
    return 0;
}
