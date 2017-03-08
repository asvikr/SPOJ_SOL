#include <bits/stdc++.h>
using namespace std;
const int N = 1024;
typedef long long LL;
#define M 100000007

int n, m;
LL dp[N][N];
int a[N], b[N];

int main() {
    int t;
    scanf("%d",&t);
    for(int tt = 1; tt <= t; tt++) {
        memset(dp, 0, sizeof dp);

        scanf("%d %d",&n, &m);
        for(int i = 0; i < n; i++) {
            scanf("%d",&a[i]);
        }
        dp[0][0] = 1;
        int x;
        memset(b, 0, sizeof b);
        for(int i = 0; i < m; i++) {
            scanf("%d",&x);
            b[x] = 1;
        }
        
        for(int i = 1; i <= n; i++) {
            for(int j = 0; j <N; j++) {
                dp[i][j] = dp[i-1][j ^ a[i-1]] + dp[i-1][j];
                if(dp[i][j] >= M) dp[i][j] -= M;
            }
        }
        long long ans = 0;
        for(int i = 0; i < N; i++) {
            if(b[i]==1) continue;
            ans += dp[n][i];
            if(ans >= M) ans -= M;
        }
        printf("Case %d: ",tt);
        printf("%lld\n",ans);
    }
}