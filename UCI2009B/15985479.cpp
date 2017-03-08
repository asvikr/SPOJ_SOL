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
const int N=1005;
vector<int> prime;
bool mark[N];
vector<pair<int,int> > solve(int n,int r)
{
    vector<pair<int,int> > ret;
    for(int i=0;i<prime.size();i++){
        if(n<prime[i]) break;
        int c=prime[i];
        int coff=0;
        while(c<=n){
            coff+=n/c-r/c-(n-r)/c;
            c=c*prime[i];
        }
       // printf("%d %d\n",prime[i],coff);
        ret.pb(mp(prime[i],coff));
    }
    return ret;
}
int main()
{
    prime.pb(2);
    for(int i=3;i*i<N;i+=2)
        if(!mark[i])
            for(int j=i*i;j<N;j+=2*i) mark[j]=1;
    for(int i=3;i<N;i+=2)
        if(!mark[i]) prime.pb(i);
    // solve(20,4);
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        if(n==0){
            printf("1\n");
        }
        else if(n==1){
            printf("A+B\n");
        }
        else
        {
            printf("A^%d+",n);
            for(int i=1;i<n;i++){
                int x=n-i;
                int y=i;
                if(i>0 && i<n){
                    vector<pair<int,int> > cf=solve(n,i);
                    for(int j=0;j<cf.size();j++){
                        if(cf[j].sc==0) continue;
                        if(cf[j].sc==1){
                            printf("%dx",cf[j].f);
                            continue;
                        }
                        printf("%d^%dx",cf[j].f,cf[j].sc);
                    }
                }
                printf("A");
                if(n-i>1) printf("^%d",n-i);
                printf("B");
                if(i>1) printf("^%d",i);
                printf("+");
            }
            printf("B^%d\n",n);
        }
    }
    return 0;
}
