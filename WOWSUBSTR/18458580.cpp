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
char str[N];
int main()
{
  int t;
  scanf("%d",&t);
  for(int tt = 1; tt <= t; tt++) {
    scanf("%s",str + 1);
    int ans = 0;
    int n = strlen(str+1);
    //printf("%d\n", n);
    for(int i = 1; i <= n; i++) {
      int c[26];
      memset(c, 0, sizeof c);
      int j = i-1;
      c[str[i] - 'a'] = 1;
      int res = 1;
      while(j > 0) {
        if(c[str[j]-'a'] == 1) break;
        c[str[j]-'a'] = 1;
        j -= 1;
        res += (i - j);
      }
      ans = (ans + res);
      if(ans >= M) ans -= M;
    }
    printf("Case %d: %d\n",tt, ans);
  }
  return 0;
}