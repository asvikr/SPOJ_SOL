#include <bits/stdc++.h>
using namespace std;
#define M 100007
typedef long long LL;

#define pb push_back
#define mp make_pair
#define f first
#define sc second

#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()

const int N = 500005;
int a[N];
int dp[N];
int last[2*N];
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
int main()
{
  for(int i = 1; i < N; i++) {
    dp[i] = dp[i-1] + i;
    if(dp[i] >= M) dp[i] -= M;
  }
  int t;
  scanf("%d",&t);
  for(int tt = 1; tt <= t; tt++) {
    int ans = 0;
    memset(last, 0, sizeof last);
    int n, m;
    //scanf("%d %d",&n, &m);
    n = read(); m = read();
    for(int i = 1; i <= n; i++) a[i] = read(); //scanf("%d", &a[i]);
    int cur = 0;
    for(int i = 1; i <= n; i++) {
      cur = max(cur,last[a[i]]);
      ans = ans + dp[i - cur];
      if(ans >= M) ans -= M;
      last[a[i]] = i;
    }
    printf("Case %d: %d\n",tt, ans);
  }
  return 0;
}