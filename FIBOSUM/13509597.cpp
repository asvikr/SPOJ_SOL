#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
typedef long long int LL;
LL fibo(LL n)
{
    LL temp[2][2],ans[2][2]={{1,0},{0,1}},fib[2][2]={{1,1},{1,0}};
    while(n>0)
    {
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            temp[i][j]=0;
        if(n&1)
        {
            for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                temp[i][j]=(temp[i][j]+ans[i][k]*fib[k][j])%M;
            for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                ans[i][j]=temp[i][j]%M;
        }
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
            temp[i][j]=0;
        for(int i=0;i<2;i++)
                for(int j=0;j<2;j++)
                for(int k=0;k<2;k++)
                temp[i][j]=(temp[i][j]+fib[i][k]*fib[k][j])%M;
        for(int i=0;i<2;i++)
            for(int j=0;j<2;j++)
                fib[i][j]=temp[i][j]%M;
            n>>=1;
    }
    return ans[0][1]%M;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n,m;
        scanf("%lld %lld",&n,&m);
        printf("%lld\n",(fibo(m+2)-fibo(n+1)+M)%M);
    }
    return 0;
}
