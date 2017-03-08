#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long int LL;
const LL base = 10007;
char str[2005];
LL h[2005],w[2005],p[2005];
LL getH(int l,int r)
{
    if(l>r) return 0;
    LL k=h[r]-h[l-1]*p[r-l+1];
    return k;
}
LL getW(int l,int r)
{
    if(l>r) return 0;
    LL k=w[l]-w[r+1]*p[r-l+1];
    return k;
}
int main()
{
    int t;
    scanf("%d",&t);
    p[0]=1;
    for(int i=1;i<=2001;i++){
        p[i]=p[i-1]*base;
    }
    while(t--)
    {
        scanf("%s",str);
        int n=strlen(str);
        h[0]=0;
        w[n+1]=0;
        for(int i=1;i<=n;i++){
            h[i]=h[i-1]*base+(LL)str[i-1];
            //cout<<h[i]<<endl;
        }
        for(int i=n;i>=1;i--){
            w[i]=w[i+1]*base+(LL)str[i-1];
            //cout<<w[i]<<endl;
        }
        int dp[n+2];
        for(int i=1;i<=n;i++){
            if(getH(1,i)==getW(1,i)){
                dp[i]=0;
                continue;
            }
            else
            {
                dp[i]=INT_MAX;
                for(int j=1;j<i;j++){
                    if((getH(j+1,i)==getW(j+1,i))&& dp[i]>dp[j]+1)
                        dp[i]=dp[j]+1;
                }
            }
        }
        printf("%d\n",dp[n]+1);
    }
    return 0;
}
