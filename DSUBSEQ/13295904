#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[100005];
        scanf("%s",str);
        long long int dp[100005];
        int last[26];
        memset(last,0,sizeof(last));
        dp[0]=1;
        int len=strlen(str);
        for(int i=1;i<=len;i++)
        {
            if(last[str[i-1]-65]!=0)
            dp[i]= dp[i-1]*2-dp[last[str[i-1]-65]-1];
            else
                dp[i]=(dp[i-1]%M*2)%M;
            if(dp[i]<0)
                dp[i]=(dp[i]+M)%M;
            else if(dp[i]>=M)
                dp[i]%=M;
            last[str[i-1]-65]=i;
        }
        //for(int i=0;i<=26;i++)
          //  printf("%d ",a[i]);
          dp[len]%=M;
        printf("%lld\n",dp[len]%M);
    }
    return 0;
}
