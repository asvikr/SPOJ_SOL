#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int LL;
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
LL modulo(LL a,LL n,LL m)
{
    LL x=1,y=a;
    while(n>0)
    {
        if(n%2)
            x=(x*y)%m;
            y=(y*y)%m;
        n/=2;
    }
    return x%m;
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
vector<int> prime;
const int L1D_CACHE_SIZE = 32768;
void segmented_sieve(int64_t limit, int segment_size = L1D_CACHE_SIZE)
{
  prime.pb(2);
  int sqrt = (int) std::sqrt((double) limit);
  int64_t count = (limit < 2) ? 0 : 1;
  int64_t s = 2;
  int64_t n = 3;

  // vector used for sieving
  std::vector<char> sieve(segment_size);

  // generate small primes <= sqrt
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
    // sieve the current segment
    for (std::size_t i = 1; i < primes.size(); i++)
    {
      int j = next[i];
      for (int k = primes[i] * 2; j < segment_size; j += k)
        sieve[j] = 0;
      next[i] = j - segment_size;
    }

    for (; n <= high; n += 2)
      if (sieve[n - low])
        prime.pb(n);
  }
}
bool fun(LL p){
        for(int i=0;i<10;i++) {
        if(p==prime[i]) return true;
        if(p%prime[i]==0) return false;
        }
        LL s=p-1;
        while(s%2==0)
            s/=2;
        LL a,temp;
        for(int i=0;i<5;i++)
        {
         a=rand()%(p-1)+1;temp=s;
         int mod=modulo(a,temp,p);
         while((temp!=p-1) && (mod!=1) && (mod!=p-1))
         {
             mod=(mod*mod)%p;
             temp*=2;
         }
         if((temp%2==0) && (mod!=p-1))
         {
             return false;
         }
        }
        return true;
}
int main()
{
    int64_t limit = 100000000;
    segmented_sieve(limit);
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n;
        scanf("%lld",&n);
        if(n==1){
            printf("0\n");
            continue;
        }
        if(fun(n)){
            printf("1\n");
            continue;
        }
        LL ans=1,kk=n;
        for(int i=0;i<prime.size();i++){
            if(sqrt(n)<prime[i]) break;
            if(n%prime[i]==0){
                LL temp=1,p=prime[i];
                while(n%prime[i]==0){
                    n/=prime[i];
                    temp+=p;
                    p=(LL)p*prime[i];
                }

                ans=(ans*temp);
            }
        }
        if(n>1){
            ans*=(n+1);
        }
        ans-=kk;
        printf("%llu\n",ans);
    }
    return 0;
}

