#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;
int n;
LL hist[100005];
LL tree[300005];
void build(int tl,int tr,int node)
{
    if(tl>tr)
        return;
    if(tl==tr)
    {
        tree[node]=tl;
        return;
    }
    int mid=(tl+tr)/2;
    build(tl,mid,node*2);
    build(mid+1,tr,node*2+1);
   if(hist[tree[node*2]]>hist[tree[node*2+1]])
    tree[node]=tree[node*2+1];
   else
    tree[node]=tree[node*2];
    return;
}
int query(int tl,int tr,int l,int r,int node)
{
    if(tl>tr || l>tr || tl>r)
        return 0;
    int mid=(tl+tr)/2;
    if(tl>=l && r>=tr)
        return tree[node];
        int idx1=query(tl,mid,l,r,node*2);
        int idx2=query(mid+1,tr,l,r,node*2+1);
        if(hist[idx1]>hist[idx2])
            return idx2;
        else
           return idx1;

}
LL fun(int l,int r)
{
 if(l>r)
        return LONG_LONG_MIN;
 if(l==r)
    return hist[l];
 int m=query(1,n,l,r,1);
 //printf("m=%d\n",m);
 LL p1=fun(l,m-1);
 LL p2=fun(m+1,r);
 LL p3=(r-l+1)*(hist[m]);
// printf("p1=%lld p2=%lld p3=%lld\n",p1,p2,p3);
 return max(max(p1,p2),p3);
}
int main()
{
    hist[0]=LONG_LONG_MAX;
    while(1)
    {
    scanf("%d",&n);
    if(n==0)
        return 0;
    for(int i=1;i<=n;i++)
        scanf("%lld",&hist[i]);
    build(1,n,1);
    printf("%lld\n",fun(1,n));
    }
    return 0;
}
