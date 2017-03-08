#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define getchar_unlocked getchar
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
LL max(LL a,LL b,LL c){return max(a,max(b,c));}
inline LL power(LL x,LL y)
{
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%M;
        x=(x*x)%M;
        y/=2;
    }
    return ans;
}
inline int read()
{
	int ret = 0,temp=1;
	int c = getchar_unlocked();
	while(c<'0' || c>'9'){
		c = getchar_unlocked();
	}
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
int a[1005];
int m,n;
int max_hist(int h[])
{
//for(int i=1;i<=n;i++) printf("%d ",h[i]);
 int i, top = 1, area = 0, S[1005];
 h[0] = S[0] = h[n+1] = 0;
 for(i=1; i<=n+1; i++)
 {
    while(top>1 && h[S[top-1]]>=h[i]){
    area = max(area, h[S[top-1]]*(i - S[top-2]-1));
    top--;
    }
 S[top++] = i;
 }
 return area;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--){
        char s[2];
        int best=0;
        scanf("%d %d",&m,&n);
        memset(a,0,sizeof(a));
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                scanf("%s",s);
                if(s[0]=='R') a[j]=0;
                else a[j]++;
                //printf("%d ",a[j]);
            }
            //printf("\n");
            best=max(best,max_hist(a));
            //printf("%d\n",best);
        }
        printf("%d\n",best*3);
    }
    return 0;
}
