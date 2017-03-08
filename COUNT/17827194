#include <bits/stdc++.h>
using namespace std;
const int N = 5005;
const int M = 1988;
int dp[N][N];

int main() {
  int n, k;
  for(int i = 0 ; i <N; i++) {
    dp[i][1] = 1;
    dp[0][i] = 1;
   }
    
    for(int con = 2; con<N; con++) {
        for(int balls = 1; balls<N; balls++) {
          dp[balls][con] = ((balls-con>=0?dp[balls-con][con]:0) + dp[balls][con-1])%M;
        }
    }
  while(1) {
    scanf("%d %d",&n,&k);
    if(n==0 && k==0) break;
    
   
    printf("%d\n", dp[n-k][k]);
  }
}