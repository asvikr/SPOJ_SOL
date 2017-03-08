#include<bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long int LL;
void multiply(LL F[2][2], LL M[2][2])
{
    LL x =  ((F[0][0] * M[0][0])%MOD + (F[0][1] * M[1][0])%MOD)%MOD;
    LL y =  ((F[0][0] * M[0][1])%MOD + (F[0][1] * M[1][1])%MOD)%MOD;
    LL z =  ((F[1][0] * M[0][0])%MOD + (F[1][1] * M[1][0])%MOD)%MOD;
    LL w =  ((F[1][0] * M[0][1])%MOD + (F[1][1] * M[1][1])%MOD)%MOD;
    F[0][0] = x;
    F[0][1] = y;
    F[1][0] = z;
    F[1][1] = w;
}

 /*
  * function to calculate power of a matrix
  */
void power(LL F[2][2], int n)
{
    if (n == 0 || n == 1)
        return;
    LL M[2][2] = {{1,1},{1,0}};
    power(F, n / 2);
    multiply(F, F);
    if (n % 2 != 0)
        multiply(F, M);
}
LL fib(LL n)
{
    LL F[2][2] = {{1,1},{1,0}};
    if (n == 0)
        return 0;
    power(F, n - 1);
    return F[0][0]%MOD;
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		LL ans1,ans2;
		ans1=fib(m+2)%MOD;
		ans2=fib(n+1)%MOD;
		ans1=(ans1-1+MOD)%MOD;
		ans2=(ans2-1+MOD)%MOD;
		printf("%lld\n",(ans1-ans2+MOD)%MOD);
	}
	return 0;
}
