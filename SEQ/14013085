#include<bits/stdc++.h>
using namespace std;
#define M 1000000000
typedef long long int LL;
LL b[11],c[11];
LL T[11][11];
 int k;
LL solve(LL n,int k)
{
    LL mat[k+1][k+1],temp[k+1][k+1];
    memset(mat,0,sizeof(mat));
    for(int i=1;i<=k;i++)
        mat[i][i]=1;
    while(n>0)
    {
        if(n&1)
        {
            memset(temp,0,sizeof(temp));
            for(int i=1;i<=k;i++)
                for(int j=1;j<=k;j++)
                    for(int k1=1;k1<=k;k1++)
                        temp[i][j]=(temp[i][j]%M+(mat[i][k1]*T[k1][j])%M)%M;
                for(int i=1;i<=k;i++)
                for(int j=1;j<=k;j++)
                        mat[i][j]=temp[i][j]%M;
        }
            memset(temp,0,sizeof(temp));
            for(int i=1;i<=k;i++)
                for(int j=1;j<=k;j++)
                    for(int k1=1;k1<=k;k1++)
                        temp[i][j]=(temp[i][j]%M+(T[i][k1]*T[k1][j])%M)%M;
            for(int i=1;i<=k;i++)
                for(int j=1;j<=k;j++)
                        T[i][j]=temp[i][j]%M;
            n/=2;
    }
    LL ans=0;
    for(int i=1;i<=k;i++)
    {
        ans=(ans%M+(b[k-i+1]*mat[1][i])%M)%M;
    }
return ans;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(b,0,sizeof(b));
        memset(c,0,sizeof(c));
        memset(T,0,sizeof(T));
        scanf("%d",&k);
        for(int i=1;i<=k;i++)
            scanf("%lld",&b[i]);
        for(int i=1;i<=k;i++)
            scanf("%lld",&c[i]);
        LL n;
        scanf("%lld",&n);
        if(n<=k)
        {
            printf("%lld\n",b[n]);
            continue;
        }
        for(int i=1;i<=k;i++)
            T[1][i]=c[i];
        for(int i=2;i<=k;i++)
        {
            T[i][i-1]=1;
        }
        LL ans=solve(n-k,k);
        printf("%lld\n",ans%M);
    }
    return 0;
}

