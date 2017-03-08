#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
inline int read()
{
	int ret = 0;
	int c = getchar_unlocked();

	while(c<'0' || c>'9')
		c = getchar_unlocked();
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
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
      //  freopen("input.txt","r",stdin);
       // freopen("outut.txt","w",stdout);
    int t;
   // scanf("%d",&t);
   t=read();
    while(t--)
    {
        int n,k,x,p=0,q;
        node *root=new node();
        insert(root,0);
        LL ans=0;
       // scanf("%d %d",&n,&k);
       n=read();k=read();
        for(int i=0;i<n;i++)
        {
            //scanf("%d",&x);
            x=read();
            q=p^x;
            ans+=(LL)query(root,q,k);
            insert(root,q);
            p=q;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
