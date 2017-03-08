#include <cstdio>
#include <cstring>
#include <cmath>
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
#define SZ(x) ( (int) (x).size() )
#define dbg(x) cerr << #x << " = " << x << endl;
#define mp make_pair
#define pb push_back
#define fi first
#define se second
typedef long long ll;
typedef pair<int, int> i2;
const int MAX_N = 20;
#define ison(x, i) (((x) >> (i)) & 1)
int n, T;
ll dp[1 << MAX_N];
int a[MAX_N][MAX_N];

int main(){
  ios::sync_with_stdio(0);
  cin >> T;
  while(T--){
    cin >> n;
    for(int i = 0; i < n; i++){
      for(int j = 0; j < n; j++){
         cin >> a[i][j];
      }
    }
    int i, j, k;
    dp[0] = 1;
    for(i = 1; i < (1 << n); i++){
      j = 0;
      dp[i] = 0;
      for(k = 0; k < n; k++){
         j += ison(i, k); 
      }
      for(k = 0; k < n; k++){
         if(a[j - 1][k] && ison(i, k)){
            dp[i] += dp[i & ~(1 << k)];
         }
      }
    }
    cout << dp[(1 << n) - 1] << endl;
  }
  return 0;
}