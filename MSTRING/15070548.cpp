#include<bits/stdc++.h>
using namespace std;
#define N 1005
int dp[N][N],idx[N][N];
int main()
{
    char V[N],T[N];
    scanf("%s %s",V,T);
    int n=strlen(V);
    int m=strlen(T);
    for(int i=0;i<n;i++){
        int prev=-1;
        for(int j=0;j<m;j++){
            if(V[i]==T[j]) prev=j;
            idx[i+1][j+1]=prev;
        }
    }
    for(int i=1;i<=n;i++) dp[i][0]=1;
    for(int i=0;i<=m;i++) dp[0][i]=N;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            if(idx[i][j]==-1) dp[i][j]=1;
            else
            {
                dp[i][j]=min(1+dp[i-1][idx[i][j]],dp[i-1][j]);
            }
        }
    }
    printf("%d\n",dp[n][m]);
    return 0;
}
