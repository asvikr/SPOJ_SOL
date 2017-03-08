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

const int N = 2505;
int a[N];
LL C[N][N];
inline LL power(LL x, LL y)
{
    LL ans = 1;
    while(y > 0){
        if(y&1)
            ans = (ans * x)%M;
        x = (x * x)%M;
        y /= 2;
    }
    return ans;
}
int main()
{
	C[0][0] = 1;
	C[1][0] = C[1][1] = 1;
	for(int i = 2; i < N; i++) {
		for(int j = 0; j <= i; j++) {
			if(j==0) {
				C[i][j] = 1;
				continue;
			}
			C[i][j] = (C[i-1][j] + C[i-1][j-1]);
			if(C[i][j] >= M) C[i][j] -= M;
		}
	}
	int t;
	scanf("%d",&t);
	while(t--) {
		int n;
		scanf("%d", &n);
		LL ans = 0;
		LL p = power(2, M-2);
		for(int i = 1; i <= n; i++) {
			LL c = C[n][i];
			LL temp = (c*(c-1))%M;
			temp = (temp*p)%M;
			temp = (temp*i)%M;
			ans = (ans + temp)%M;
			//printf("%lld ",(c*(c-1)*p)%M );
			for(int j = i+1; j <= n; j++) {
				//printf("%lld %d %d\n",C[n][j], n, j);
				ans = (ans + ((C[n][i]*C[n][j])%M*__gcd(i,j))%M)%M;
				//printf("%lld ", C[n][i]*C[n][j]*__gcd(i,j));
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}