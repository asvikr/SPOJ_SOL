#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
long long int dp[N][N];
int n, m;
int c[N], b[N];
long long int solve(int i, int j) {
  if(i==n) return 0;
  if(j==m) return 1e13;

  if(dp[i][j]!=-1) return dp[i][j];

  long long int res = LONG_LONG_MAX;
  res = min(res, solve(i+1, j+1) + abs(b[i]-c[j]));
  res = min(res, solve(i, j+1));
  dp[i][j] = res;
  return res;
}
int main() {
  scanf("%d %d",&n,&m);
  memset(dp, -1, sizeof dp);
  for(int i = 0; i<n; i++) scanf("%d",&b[i]);
  for(int i = 0; i<m; i++) scanf("%d",&c[i]);
  sort(b, b+n);
  sort(c, c+m);
  long long int ans = solve(0,0);
  printf("%lld\n", ans);
  return 0;
}