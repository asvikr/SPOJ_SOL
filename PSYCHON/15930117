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
const int N=10000005;
int mark[N];
void pre()
{
    for(int i=1;i<N;i++) {
    if(i&1) mark[i]=i;
    else mark[i]=2;
    }
    for(int i=3;i*i<N;i+=2){
        if(mark[i]==i){
            for(int j=2*i;j<N;j+=i){
                mark[j]=i;
            }
        }
    }
    //printf("gadg\n");
}
int main()
{
    pre();
   int t;
   scanf("%d",&t);
   while(t--){
    int n;
    scanf("%d",&n);
    int ev=0,odd=0;
    while(1){
        if(n==1) break;
      //  printf("%d %d\n",n,mark[n]);
        if(mark[n]==n){
            odd++;
            break;
        }
        int k=mark[n],cnt=0;
        while(n%k==0){
            n/=k;
            cnt++;
        }
        if(cnt&1) odd++;
        else ev++;
    }
   if(ev>odd) printf("Psycho Number\n");
   else printf("Ordinary Number\n");
   }
   return 0;
}

