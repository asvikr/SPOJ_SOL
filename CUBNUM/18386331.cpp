#include <bits/stdc++.h>
using namespace std;

typedef long long LL;

#define pb push_back
#define mp make_pair
#define f first
#define sc second

#define inf (int)(2e+9)
#define all(o) (o).begin(), (o).end()

const int N = 100005;
int a[N];
const int M = 50;
int dp[N];
int main()
{

  for(int j = 1; j < M; j++) {
    for(int i = 1; i < N; i++) {
      if(j == 1) {
        dp[i] = i;
        continue;
      }
      if( i >= j*j*j) dp[i] = min(dp[i], dp[i-j*j*j] + 1);
    }
  }
  int n;
  int tt = 1;
  while(scanf("%d", &n)!=EOF) {
    printf("Case #%d: %d\n",tt++, dp[n]);
  }
  return 0;
}