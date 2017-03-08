#include<bits/stdc++.h>
using namespace std;
#define N 300005
#define A 1111111
int a[N],cnt[A],n;
struct node
{
    int L,R;
    int idx;
}q[200005];
int ans[200005],answer=0;
bool cmp(node x,node y)
{
    if(x.L/555!=y.L/555)
        return x.L/555<y.L/555;
    return x.R<y.R;
}
void add(int x)
{
    cnt[a[x]]++;
    if(cnt[a[x]]==1)
        answer++;
}
void remove(int x)
{
    cnt[a[x]]--;
    if(cnt[a[x]]==0)
        answer--;
}
int main()
{
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {
        scanf("%d %d",&q[i].L,&q[i].R);
        q[i].L--;
        q[i].R--;
        q[i].idx=i;
    }
    sort(q,q+t,cmp);
    int curL=0,curR=0;
    for(int i=0;i<t;i++)
    {
        int L=q[i].L;
        int R=q[i].R;
        while(curL<L)
        {
            remove(curL);
            curL++;
        }
        while(curL>L)
        {
            add(curL-1);
            curL--;
        }
        while(curR<=R)
        {
            add(curR);
            curR++;
        }
        while(curR>R+1)
        {
            remove(curR-1);
            curR--;
        }
        ans[q[i].idx]=answer;
    }
    for(int i=0;i<t;i++)
        printf("%d\n",ans[i]);
}
