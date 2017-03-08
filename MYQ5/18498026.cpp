#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long LL;

#define pb push_back
#define mp make_pair
#define f first
#define sc second

#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()

const int N = 1005;
int a[N];
int dp[N][N];

int solve(int grp, int have) {
  if(grp == 0) return (have == 0?1:0);
  int &ret = dp[grp][have];
  if(ret != -1) return ret;

  ret = solve(grp - 1, have);
  if(have >= grp) {
    ret += solve(grp, have - grp);
    if(ret >= M) ret -= M;
  }
  return ret;
}
int main()
{
  memset(dp, -1, sizeof dp);
  int t;
  scanf("%d",&t);
  while(t--) {
    int n, k;
    scanf("%d %d",&n, &k);
    int ans = 0;
    for(int i = 1; i <= n/k; i++) {
      ans += solve(i, n - k*i);
      if(ans >= M) ans -= M;
    }
    printf("%d\n", ans);
  }
  return 0;
}