#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
class node
{
public:
    int lcount,rcount;
    node *lchild,*rchild;
    node()
    {
        lcount=rcount=0;
        lchild=rchild=NULL;
    }
};
void insert(node *root,int n)
{
    for(int i=20;i>=0;i--)
    {
        int x=(n>>i)&1;
        if(x)
        {
            root->rcount++;
            if(root->rchild==NULL)
            {
                root->rchild=new node();
            }
            root=root->rchild;
        }
        else
        {
            root->lcount++;
            if(root->lchild==NULL)
            {
                root->lchild=new node();
            }
            root=root->lchild;
        }
    }
}
int query(node *root,int n,int k)
{
    if(root==NULL)
        return 0;
    int res=0;
    for(int i=20;i>=0;i--)
    {
        bool ch1=(k>>i)&1;
        bool ch2=(n>>i)&1;
        if(ch1)
        {
            if(ch2)
            {
                res+=root->rcount;
                if(root->lchild==NULL)
                return res;
                root=root->lchild;
            }
            else
            {
                res+=root->lcount;
                if(root->rchild==NULL)
                    return res;
                root=root->rchild;
            }
        }
        else
        {
            if(ch2)
            {
                if(root->rchild==NULL)
                return res;
                root=root->rchild;
            }
            else
            {
                if(root->lchild==NULL)
                    return res;
                root=root->lchild;
            }
        }
    }
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,k,x,p=0,q;
        node *root=new node();
        insert(root,0);
        LL ans=0;
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++)
        {
            scanf("%d",&x);
            q=p^x;
            ans+=(LL)query(root,q,k);
            insert(root,q);
            p=q;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
