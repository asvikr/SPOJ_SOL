#include<bits/stdc++.h>
using namespace std;
int M;
typedef long long int LL;
LL fibo(LL n)
{
    LL temp[4][4],ans[4][4],fib[4][4]={{1,1,1,0},{1,0,0,0},{0,0,1,1},{0,0,0,1}};
    memset(ans,0,sizeof(ans));
    for(int i=0;i<4;i++) ans[i][i]=1;
    while(n>0)
    {
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            temp[i][j]=0;
        if(n&1)
        {
            for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                for(int k=0;k<4;k++)
                temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j])%M;
            for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                ans[i][j]=temp[i][j]%M;
        }
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
            temp[i][j]=0;
        for(int i=0;i<4;i++)
                for(int j=0;j<4;j++)
                for(int k=0;k<4;k++)
                temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j])%M;
        for(int i=0;i<4;i++)
            for(int j=0;j<4;j++)
                fib[i][j]=temp[i][j]%M;
            n>>=1;
    }
    LL res=(ans[0][0]+ans[0][2]+ans[0][3])%M;
    return res;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n;
        scanf("%lld %lld",&n,&M);
        if(n==1){
            printf("1\n");
            continue;
        }
        else if(n==0){
            printf("0\n");
            continue;
        }
        LL ans;
        ans=fibo(n-1)%M;
        if(ans<0)
            ans+=M;
        printf("%lld\n",ans);
    }
    return 0;
}

