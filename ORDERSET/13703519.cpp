#include<bits/stdc++.h>
using namespace std;
int tree[800100];
struct node
{
    char st[2];
    int x;
};
map<int,int> M;
int num[200010];
void update(int tl,int tr,int pos,int node,int ch)
{
    if(tl>tr)
        return;
    int mid=(tl+tr)/2;
    if(tl==tr)
    {
        if(tree[node]==0 && ch==0)
        tree[node]=1;
        if(tree[node]==1 && ch==1)
        tree[node]=0;
        return;
    }
    if(pos<=mid)
        update(tl,mid,pos,node*2,ch);
    else
        update(mid+1,tr,pos,node*2+1,ch);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int query(int tl,int tr,int l,int r,int node)
{
    if(tl>tr || tl>r || tr<l)
        return 0;
    int mid=(tl+tr)/2;
    if(tl>=l && tr<=r)
        return tree[node];
    return query(tl,mid,l,r,node*2)+query(mid+1,tr,l,r,node*2+1);
}
int solve(int tl,int tr,int n,int node)
{
    if(tl==tr)
        return num[tl-1];
    int mid=(tl+tr)/2;
    int x=tree[node*2];
    if(x>=n)
        solve(tl,mid,n,node*2);
    else
        solve(mid+1,tr,n-x,node*2+1);
}
int main()
{
    int q;
    scanf("%d",&q);
    node inp[q+5];
    int j=0;
   for(int i=0;i<q;i++)
    {
        scanf("%s%d",inp[i].st,&inp[i].x);
        if(inp[i].st[0]=='I' || inp[i].st[0]=='C')
        num[j++]=inp[i].x;
    }
    sort(num,num+j);
    for(int i=0;i<j;i++)
        M[num[i]]=i;

    for(int i=0;i<q;i++)
    {
        if(inp[i].st[0]=='I')
            update(1,q+10,M[inp[i].x]+1,1,0);
        else if(inp[i].st[0]=='D'){
                if(M[inp[i].x]!=0){
                update(1,q+10,M[inp[i].x]+1,1,1);
                }
        }
        else if(inp[i].st[0]=='C')
            printf("%d\n",query(1,q+10,1,M[inp[i].x],1));
        else
        {
            if(tree[1]<inp[i].x)
                printf("invalid\n");
            else
            printf("%d\n",solve(1,q+10,inp[i].x,1));
        }
    }
    return 0;
}
