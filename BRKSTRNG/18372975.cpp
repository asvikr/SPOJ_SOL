#include <bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long LL;
const LL inf = 1e16;
const int N = 1005;

LL dp[N][N];
int pos[N][N];
LL cut[N];

int main()
{
  int n, m;
  while(scanf("%d %d",&n, &m)!=EOF) {

    cut[0] = 0; 
    for(int i = 1; i <= m; i++) scanf("%lld",&cut[i]);
    cut[m+1] = n;
 
    for(int i = 0; i <= m+1; i++) dp[i][i] = 0;
    for(int i = 0; i <= m; i++) dp[i][i+1] = 0, pos[i][i+1] = i;
      m = m+1;
      for(int l = 3; l <= m + 1; l++) {
        for(int i = 0; i <= m - l + 1; i++){
        int j = i + l - 1;
        dp[i][j] = inf;
        int mini = -1;
        for(int k = pos[i][j-1]; k <= pos[i+1][j]; k++) {
        LL p = dp[i][k] + dp[k][j] + cut[j] - cut[i];
          if(dp[i][j] > p) {
            dp[i][j] =  p;
            mini = k;
          }
        }
        pos[i][j] = mini;
      }
    }
    printf("%lld\n", dp[0][m]);
  }
  return 0;
}