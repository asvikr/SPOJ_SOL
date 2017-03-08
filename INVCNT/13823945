#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int a[200005],tree[200005];
int maxval;
void update(int pos,int val)
{
    while(pos<=maxval)
    {
        tree[pos]+=val;
        pos+=(pos&-pos);
    }
}
int query(int pos)
{
    int ans=0;
    while(pos>0)
    {
        ans+=tree[pos];
        pos-=(pos&-pos);
    }
    return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        map<int,int> M;
        maxval=n;
        memset(tree,0,sizeof(tree));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            M[a[i]]=i;
        }
        LL ans=0;
        map<int,int>:: iterator it;
        it=M.begin();
        for(int i=1;i<=n;i++)
        {
            update(it->second,1);
            ans+=(LL)(query(n)-query(it->second));
              it++;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
