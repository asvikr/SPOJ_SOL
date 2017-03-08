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
vector<LL> sum(5761455,0);
const int L1D_CACHE_SIZE = 32768;
vector<int> prime;
void segmented_sieve(int64_t limit, int segment_size = L1D_CACHE_SIZE)
{
    prime.pb(2);
  int sqrt = (int) std::sqrt((double) limit);
  int64_t count = (limit < 2) ? 0 : 1;
  int64_t s = 2;
  int64_t n = 3;

  std::vector<char> sieve(segment_size);
  std::vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;

  std::vector<int> primes;
  std::vector<int> next;

  for (int64_t low = 0; low <= limit; low += segment_size)
  {
    std::fill(sieve.begin(), sieve.end(), 1);

    // current segment = interval [low, high]
    int64_t high = std::min(low + segment_size - 1, limit);

    // store small primes needed to cross off multiples
    for (; s * s <= high; s++)
    {
      if (is_prime[s])
      {
        primes.push_back((int) s);
          next.push_back((int)(s * s - low));
      }
    }
    for (std::size_t i = 1; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }

    for (; n <= high; n += 2)
      if (sieve[n - low]) // n is a prime
        prime.pb(n);
  }

}
int main()
{
   int limit = 100000005;
   segmented_sieve(limit);
   //printf("%d\n",prime.size());
   int t,m;
   t=read();
   m=read();
   prime.pb(inf);
   sum[0]=1;
   for(int i=1;i<=prime.size();i++){
    sum[i]=sum[i-1]*prime[i-1];
    if(sum[i]>=m) sum[i]%=m;
   }
   while(t--){
        int n;
        n=read();
        LL ans=1;
        int p=sqrt(n);
        int i1,i2;
        for(int i=0;i<prime.size();i++){
            if(p<prime[i]) {
                i1=i;
                break;
            }
            LL k=prime[i];
            while(k<=n){
                k=k*prime[i];
            }
            k/=prime[i];
            ans=(ans*k);
            if(ans>=m) ans%=m;
        }
        i2=upper_bound(prime.begin(),prime.end(),n)-prime.begin();
        LL temp=(sum[i2]*power(sum[i1],m-2,m))%m;
        ans=(ans*temp)%m;
        printf("%lld\n",ans);
   }
   return 0;
}

