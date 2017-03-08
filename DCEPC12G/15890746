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
vector<int> prime;
int input[101];
LL fact[N];
void pre(int limit=N, int segment_size = 3200)
{
    fact[0]=1;
    fact[1]=1;
   for(int i=2;i<N;i++){
    fact[i]=(i*fact[i-1])%(M-1);
   }
  int sqrt = (int) std::sqrt((double) limit);
  int count = (limit < 2) ? 0 : 1;
  int s = 2;
  int n = 3;

  // vector used for sieving
  vector<char> sieve(segment_size);
    prime.pb(2);
  // generate smaint  primes <= sqrt
  vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;

  vector<int> primes;
  vector<int> next;
  for (int low = 0; low <= limit; low += segment_size)
  {
    fill (sieve.begin(), sieve.end(), 1);

    // current segment = interval [low, high]
    int high = std::min(low + segment_size - 1, limit);

    // store smaint  primes needed to cross off multiples
    for (; s * s <= high; s++)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
    // sieve the current segment
    for (int i = 1; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }

    for (; n <= high; n += 2){
        if (sieve[n - low]){ // n is a prime
            prime.pb(n);
      }
    }
  }
  //for(int i=0;i<500;i++) printf("%d\n",prime[i]);
}
int phi[105],pl[105];
int main()
{
    pre();
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++) {
        scanf("%d",&input[i]);
        phi[i]=input[i];
        pl[i]=upper_bound(all(prime),input[i])-prime.begin();
       // printf("%d ",pl[i]);
        }
    for(int i=0;i<prime.size();i++){
        for(int j=1;j<=t;j++){
            if(input[j]%prime[i]==0){
                   phi[j]-=phi[j]/prime[i];
                    while(input[j]%prime[i]==0) input[j]/=prime[i];
            }
        }
    }
    for(int i=1;i<=t;i++){
        int to=pl[i]-phi[i];
        //printf("%d %d\n",pl[i],phi[i]);
        if(to<0) to=0;
        printf("%d\n",power(phi[i],fact[to]));
    }
    return 0;
}
