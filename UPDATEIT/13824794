#include<bits/stdc++.h>
using namespace std;
int tree[10005];
int maxval;
void update(int pos,int val)
{
    while(pos<=maxval)
    {
        tree[pos]+=val;
        pos+=(pos&-pos);
    }
}
int query(int idx)
{
    int sum=0;
    while(idx>0)
    {
        sum+=tree[idx];
        idx-=(idx&-idx);
    }
    return sum;
}
int main()
{
    int t,n,u,l,r,val,q;
    scanf("%d",&t);
    while(t--)
    {
        memset(tree,0,sizeof(tree));
        scanf("%d %d",&n,&u);
        maxval=n;
        while(u--)
        {
            scanf("%d %d %d",&l,&r,&val);
            l++;
            r++;
            update(l,val);
            update(r+1,-val);
        }
        scanf("%d",&q);
        while(q--)
        {
            scanf("%d",&l);
            l++;
            printf("%d\n",query(l));
        }
    }
    return 0;
}
