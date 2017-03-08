#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define N 111111
struct node
{
    int cnt;
    node *left,*right;
    node(int cnt,node *left,node *right): cnt(cnt),left(left),right(right){}
    node* insert(int l,int r, int w);
};
int RM[N],a[N];
node *root[N];
node *null = new node(0, NULL, NULL);
node * node:: insert(int l,int r,int w)
{
    if(l<=w && w<r){
        if(l+1==r){
            return new node(this->cnt+1,null,null);
        }
        int m=(l+r)>>1;
        return new node(this->cnt+1,this->left->insert(l,m,w),this->right->insert(m,r,w));
    }
    return this;
}
int query(node *a,node *b,int l,int r,int k)
{
    if(l+1==r){
        return l;
    }
    int m=(l+r)>>1;
    int cnt=a->left->cnt-b->left->cnt;
    if(cnt>=k)
        return query(a->left,b->left,l,m,k);
    return query(a->right,b->right,m,r,k-cnt);
}
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    map<int,int> M;
    for(int i=0;i<n;i++){
       scanf("%d",&a[i]);
       M[a[i]];
    }
    int maxi=0;
    for(map<int,int> :: iterator it=M.begin();it!=M.end();it++){
        M[it->first]=maxi;
        RM[maxi]=it->first;
        maxi++;
    }
    null->left=null->right=null;
    for(int i=0;i<n;i++){
        root[i]=(i==0? null : root[i-1])->insert(0,maxi,M[a[i]]);
    }
    while(m--)
    {
        int l,r,k;
        scanf("%d %d %d",&l,&r,&k);
        l--,r--;
        int ans=query(root[r],(l==0?null:root[l-1]),0,maxi,k);
        printf("%d\n",RM[ans]);
    }
    return 0;
}
