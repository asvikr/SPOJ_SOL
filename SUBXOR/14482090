#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define f first
#define sc second
#define M 1000000007
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
pair<int,int> edges[50000000][2];
int fr=0;
int newNode()
{
    edges[fr][0].first=-1;
    edges[fr][1].first=-1;
    edges[fr][0].second=0;
    edges[fr][1].second=0;
    return fr++;
}
void insert(int p,int n)
{
    for(int i=20;i>=0;i--){
        int cur=(n>>i)&1;
        edges[p][cur].second++;
        if(edges[p][cur].first<0){
            edges[p][cur].first=newNode();
        }
        p=edges[p][cur].first;
    }
}
int query(int p,int n,int k)
{
    int ans=0;
    for(int i=20;i>=0;i--){
        int cur1=(n>>i)&1;
        int cur2=(k>>i)&1;
        if(cur2){
            if(cur1){
                ans+=edges[p][1].second;
                if(edges[p][0].first<0)
                    return ans;
                p=edges[p][0].first;
            }
            else
            {
                ans+=edges[p][0].second;
                if(edges[p][1].first<0)
                    return ans;
                p=edges[p][1].first;
            }
        }
        else
        {
            if(cur1){
                    if(edges[p][1].first<0)
                    return ans;
                p=edges[p][1].first;
            }
            else
            {
                if(edges[p][0].first<0)
                    return ans;
                p=edges[p][0].first;
            }
        }
    }
    return ans;
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output1.txt","w",stdout);
    int t;
    scanf("%d",&t);
    while(t--){
        fr=0;
        memset(edges,0,sizeof(edges));
        int n,k;
        int q=0,p=0,x;
        LL ans=0;
        newNode();
        insert(0,0);
        scanf("%d %d",&n,&k);
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            q=p^x;
            ans+=(LL)query(0,q,k);
            insert(0,q);
            p=q;
        }
        printf("%lld\n",ans);
    }
    return 0;
}

