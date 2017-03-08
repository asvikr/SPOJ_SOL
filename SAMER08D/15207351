#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
const int N=1005;
const int base=10007;
int dp[N][N];
int cnt[N][N];
int main()
{
    char A[N],B[N];
    while(1){
        int k;
        scanf("%d",&k);
        if(k==0) break;
        scanf("%s %s",A,B);
        int n,m;
        n=strlen(A);
        m=strlen(B);
        for(int i=0;i<N;i++) dp[i][0]=0,dp[0][i]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                if(A[i-1]==B[j-1]){
                       cnt[i][j]=cnt[i-1][j-1]+1;
                }
                else
                   cnt[i][j]=0;
                if(cnt[i][j]>=k){
                        for(int z=k;z<=cnt[i][j];z++)
                            dp[i][j]=max(dp[i][j],dp[i-z][j-z]+z);
                }
            }
        }
        printf("%d\n",dp[n][m]);
    }
    return 0;
}
