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
char str[28];
int a[26];
int main()
{
    for(int i=0;i<13;i++) a[i]=i+16;
    for(int i=13;i<20;i++) a[i]=i+7;
    for(int i=20;i<27;i++) a[i]=i-2;
    while(scanf("%s",str)!=EOF){
        int n=strlen(str);
        if(n<=3) break;
        int cnt=0;
        for(int i=0;i<n;i++){
          printf("%d ",a[str[i]-'a']);
          if(a[str[i]-'a']>a[16]) cnt++;
        }
        printf("\n");
        if(cnt!=0)
        printf("%d\n",cnt);
        else puts("no one.");
    }
    return 0;
}
