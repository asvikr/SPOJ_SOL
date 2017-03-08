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
/*#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;*/
int gcd(int a, int b) { return (b == 0 ? a : gcd(b, a % b)); }
int lcm(int a, int b) { return (a * (b / gcd(a, b))); }
LL max(LL a,LL b,LL c){return max(a,max(b,c));}
inline LL power(LL x,LL y,LL m)
{
    if(x==0 && y==0) return 1;
    if(x==0 && y>0) return 0;
    LL ans=1;
    while(y>0){
        if(y&1)
            ans=(ans*x)%m;
        x=(x*x)%m;
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
const int N=200005;
LL fact[N];
int lucas(int n,int r,int m)
{
    if(r<0 || r>n) return 0;
    if(r==0 || r==n) return 1;
    if(n==1 && r==1) return 1;
    if(n>=m) return (lucas(n/m,r/m,m)*lucas(n%m,r%m,m))%m;
}
void exgcd(LL a,LL b,LL &x,LL &y)
{
    if(b==0){
        x=1;
        y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    LL x1=y;
    LL y1=x-(a/b)*y;
    x=x1,y=y1;
}
LL inv(LL a,LL m)
{
    LL x,y;
    exgcd(a,m,x,y);
    if(x<0) x+=m;
    return x%m;
}
LL chinese(LL a1,LL m1,LL a2,LL m2)
{
    LL m=m1*m2;
    return (((a1*m2*(inv(m2,m1)%m1)))+(a2*m1*(inv(m1,m2)%m2)))%m;
}
int main()
{
   // freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int t;
    fact[0]=fact[1]=1;
    LL m2=(M-1)/2,m1=2;
    for(int i=2;i<N;i++) fact[i]=(fact[i-1]*i)%m2;
    t=read();
    while(t--){
        LL a,b,n;
        a=(LL)read();b=(LL)read();n=(LL)read();
        if(n==0 || b==0){
            printf("%lld\n",a);
            continue;
        }
        if(a==0){
            printf("0\n");
            continue;
        }
        LL rem1=lucas(2*n,n,m1);
        LL rem2=fact[2*n];
        rem2=(rem2*inv((fact[n]*fact[n])%m2,m2))%m2;
        LL rem=chinese(rem1,m1,rem2,m2)%(M-1);
        LL ans=power(a,power(rem,b,M-1),M);
        printf("%lld\n",ans%M);
    }
    return 0;
}
