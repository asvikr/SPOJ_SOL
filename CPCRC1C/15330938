#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL p10[20];
LL solve(int n)
{
    if(n<10) return n*(n+1)/2;
    int LOG=log10(n)+1;
    int p=n/p10[LOG-1];
    int mod=p*p10[LOG-1];
    return p*(LOG-1)*45*p10[LOG-2]+(p*(p-1)/2)*p10[LOG-1]+p*(n%mod+1)+solve(n%mod);
}
int main()
{
    int a,b;
    p10[0]=1;
    for(int i=1;i<18;i++)
        p10[i]=10*p10[i-1];
    while(1){
        scanf("%d %d",&a,&b);
        if(a==-1 && b==-1) break;
        printf("%lld\n",solve(b)-solve(a-1));
    }
    return 0;
}

