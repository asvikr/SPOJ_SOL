#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int LL;
const LL base = 10007;
char str[2005];
bool ok[2005][2005];
int main()
{
    int t;
    scanf("%d",&t);
   /* p[0]=1;
    for(int i=1;i<=2001;i++){
        p[i]=p[i-1]*base;
    }*/
    while(t--)
    {
        memset(ok,false,sizeof(ok));
        scanf("%s",str);
        int n=strlen(str);
        for(int i=1;i<=n;i++) ok[i][i]=1;
        for(int i=1;i<n;i++) if(str[i-1]==str[i]) ok[i][i+1]=1;
        for(int len=3;len<=n;len++){
            for(int i=1;i<=n-len+1;i++){
                int j=i+len-1;
                if(str[i-1]==str[j-1] && ok[i+1][j-1]) ok[i][j]=1;
                else ok[i][j]=0;
            }
        }
        int dp[n+2];
        for(int i=1;i<=n;i++){
            if(ok[1][i]==1){
                dp[i]=0;
                continue;
            }
            else
            {
                dp[i]=INT_MAX;
                for(int j=1;j<i;j++){
                    if(ok[j+1][i]==1 && dp[i]>dp[j]+1)
                        dp[i]=dp[j]+1;
                }
            }
        }
        printf("%d\n",dp[n]+1);
    }
    return 0;
}
