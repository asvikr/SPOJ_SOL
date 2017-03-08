#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long LL;
const LL inf = 1e16;
const int N = 1005;

LL dp[N][N];
int pos[N][N];
LL cut[N];

LL solve(int l, int r) {
  if(l > r ) return 0;
  if(l+1 == r) return 0;
  if(l==r) return 0;
  LL &res = dp[l][r];
  if(res != -1) return res;
  res = inf;
  for(int i = l+1; i < r; i++) {
    res = min(res , solve(l, i) + solve(i, r) + cut[r] - cut[l]);
    //printf("%lld\n", res);
  }
 // printf("%lld\n", res);
  return res;
}

int main()
{
  int n, m;
  while(scanf("%d %d",&n, &m)!=EOF) {
   // memset(dp, -1, sizeof dp);
    cut[0] = 0; 
    for(int i = 1; i <= m; i++) scanf("%lld",&cut[i]);
    cut[m+1] = n;
   // LL ans = solve(0, m+1);
    for(int i = 0; i <= m+1; i++) dp[i][i] = 0;
    for(int i = 0; i <= m; i++) dp[i][i+1] = 0, pos[i][i+1] = i;

      for(int l = 3; l <= m+2; l++) {
        for(int i = 0; i <= m - l + 2; i++){
        int j = i + l - 1;
        dp[i][j] = inf;
        int mini = -1;
        for(int k = pos[i][j-1]; k <= pos[i+1][j]; k++) {
          if(dp[i][j] > dp[i][k] + dp[k][j] + cut[j] - cut[i]) {
            dp[i][j] =  dp[i][k] + dp[k][j] + cut[j] - cut[i];
            mini = k;
          }
        }
        pos[i][j] = mini;
       // printf("%d %d %d\n",i, j, mini);
      }
    }
    printf("%lld\n", dp[0][m+1]);
    //printf("%lld\n",ans);
  }
  return 0;
}