#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
#define pb push_back
#define mp make_pair
#define f first
#define sc second
#define pii pair<int,int>
#define M 1000000007
#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
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
LL mulmod(LL a,LL b) {
   long double res = a;
   res *= b;
   LL c = (LL)(res / M);
   a *= b;
   a -= c * M;
   a %= M;
   if (a < 0) a += M;
   return a;
}
LL solve(int n)
{
        LL temp[2][2],ans[2][2]={{1,0},{0,1}},fib[2][2]={{1,1},{1,0}};
        while(n>0)
        {
           memset(temp,0,sizeof(temp));
            if(n&1)
            {
                for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++) temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j])%M;
                for(int i=0;i<2;i++) for(int j=0;j<2;j++) ans[i][j]=temp[i][j],temp[i][j]=0;
            }
            for(int i=0;i<2;i++) for(int j=0;j<2;j++) for(int k=0;k<2;k++)  temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j])%M;
            for(int i=0;i<2;i++) for(int j=0;j<2;j++) fib[i][j]=temp[i][j];
                n>>=1;
        }

        return (ans[0][0]+ans[1][1])%M;
}
int main(){
    int t;
    t=read();
    while(t--){
        int n;
        n=read();
        if(n<=1){
            printf("%d\n",n+1);
            continue;
        }
        LL ans=solve(n);
        printf("%lld\n",ans);
    }
    return 0 ;
}
