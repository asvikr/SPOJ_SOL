#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
int main()
{
    char str[5500];
    while(1)
    {
        scanf("%s",str);
        if(str[0]=='0')
            return 0;
        int l=strlen(str);
        if(l==2)
        {
            int x=(str[0]-'0')*10+(str[1]-'0');
            if(str[1]=='0' && x<=26)
                printf("1\n");
            else if(str[1]=='0' && x>26)
                printf("0\n");
            else if(x<=26)
                printf("2\n");
            else
                printf("1\n");
            continue;
        }
        LL dp[l+5];
        dp[0]=1;
        dp[1]=1;
        for(int i=2;i<=l;i++)
        {
            int x=(str[i-2]-'0')*10+(str[i-1]-'0');
            if(str[i-1]=='0')
            {
                dp[i]=dp[i-2];
            }
            else if(str[i-2]=='0')
                dp[i]=dp[i-1];
            else if(x<=26)
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
            else
                dp[i]=dp[i-1];
               // printf("dp[%d]=%d\n",i,dp[i]);
        }
        printf("%lld\n",dp[l]);
    }
    return 0;
}
