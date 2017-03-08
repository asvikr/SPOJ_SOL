#include<bits/stdc++.h>
using namespace std;
int tree[40005];
void update(int tl,int tr,int pos,int node)
{
    if(tl>tr) return;
    int mid=(tl+tr)/2;
    if(tl==tr){
        tree[node]=0;
        return;
    }
    if(pos<=mid) update(tl,mid,pos,node*2);
    else update(mid+1,tr,pos,node*2+1);
    tree[node]=tree[node*2]+tree[node*2+1];
}
void build(int tl,int tr,int node)
{
    if(tl>tr) return;
    if(tl==tr){
        tree[node]=1;
        return;
    }
    int mid=(tl+tr)/2;
    build(tl,mid,node*2);
    build(mid+1,tr,node*2+1);
    tree[node]=tree[node*2]+tree[node*2+1];
}
int query(int tl,int tr,int val,int node)
{
    if(tl==tr)
        return tl;
    int mid=(tl+tr)/2;
  //  printf("%d %d %d\n",tl,tr,tree[node]);
    if(tree[node*2]>=val)
    return query(tl,mid,val,node*2);
    else
    return query(mid+1,tr,val-tree[node*2],node*2+1);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        vector<pair<int,int> > V(n);
        for(int i=0;i<n;i++){
              int x;
              scanf("%d",&x);
              V[i].first=x;
        }
        for(int i=0;i<n;i++){
            int x;
            scanf("%d",&x);
            V[i].second=x;
        }
        build(1,n,1);
        sort(V.begin(),V.end());
        vector<int> ans(n+1);
        ans[V[0].second+1]=V[0].first;
        update(1,n,V[0].second+1,1);
        for(int i=1;i<n;i++){
            int cnt=V[i].second+1;
            int q=query(1,n,cnt,1);
            ans[q]=V[i].first;
            update(1,n,q,1);
        }
        for(int i=1;i<=n;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
    }
}
