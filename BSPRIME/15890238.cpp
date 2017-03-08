#include<bits/stdc++.h>
using namespace std;
typedef long long int LL ;
const int L1D_CACHE_SIZE = 32768;
//#define getchar_unlocked getchar
int ans,cnt;
pair<int,int> res[50005];
int cal[50005],t;
void segmented_sieve(int limit, int segment_size = L1D_CACHE_SIZE)
{
  int sqrt = (int) std::sqrt((double) limit);
  int count = (limit < 2) ? 0 : 1;
  int s = 2;
  int n = 3;

  // vector used for sieving
  vector<char> sieve(segment_size);

  // generate smaint  primes <= sqrt
  vector<char> is_prime(sqrt + 1, 1);
  for (int i = 2; i * i <= sqrt; i++)
    if (is_prime[i])
      for (int j = i * i; j <= sqrt; j += i)
        is_prime[j] = 0;

  vector<int> primes;
  vector<int> next;
    ans=1;
    cnt=3;
     int po=1;
    while(po<=t && res[po].first==0){
        cal[res[po].second]=0;
        po++;
    }
    while(po<=t && res[po].first==1){
        cal[res[po].second]=1;
        po++;
    }
    while(po<=t && res[po].first==2){
        cal[res[po].second]=1;
        po++;
    }
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
            int p=n;
            int k=(int)log2(p);
            for(int kk=k;kk>=0;kk--){
                    if(p&(1<<kk)) ++ans;
                    while(po<=t && res[po].first==cnt){
                        cal[res[po].second]=ans;
                        po++;
                    }
                    ++cnt;
                }
      }
    }
  }
}
inline int read()
{
	int ret = 0;
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
int main()
{
  int limit = 102000000;
  int size = L1D_CACHE_SIZE;
  t=read();
  for(int tt=1;tt<=t;tt++){
    int n;
    n=read();
    res[tt].first=n;
    res[tt].second=tt;
  }
  sort(res+1,res+t+1);
  segmented_sieve(limit, size);
  for(int i=1;i<=t;i++) printf("%d\n",cal[i]);
  return 0;
}
