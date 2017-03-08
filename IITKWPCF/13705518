#include<bits/stdc++.h>
using namespace std;
typedef long long int LL;
LL a[100005];
LL prime[1000005];
bool isprime(LL n)
{
    if(n==1)
        return true;
    if(n==2 || n==3 || n==5)
        return false;
    LL x=sqrt(n);
    for(LL i=2;i<=x;i++)
    {
        if(n%i==0)
        {
            return true;
        }
    }
    return false;
}
void sieve()
{
    LL x=sqrt(1000005);
    for(LL i=2;i<=1000000;i+=2)
        prime[i]=1;
    prime[2]=0;
    prime[1]=1;
    for(LL i=3;i<=x;i+=2)
    {
        if(!prime[i])
        {
            for(LL j=i*i;j<=1000005;j+=i*2)
                prime[j]=1;
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    //sieve();
    while(t--)
    {
        LL n;
        scanf("%lld",&n);
        if(n%2){
            printf("0\n");
            continue;
        }
        LL x=n/2,j=0;
        LL p=sqrt(x);
        for(LL i=1;i<=p;i++)
        {
            if(i*(x/i)==x){
                if(isprime(i))
                a[j++]=i;
                if((isprime(x/i)==true) && (x/i!=i))
                a[j++]=x/i;
            }
        }
        printf("%lld ",j);
        sort(a,a+j);
        for(int i=0;i<j;i++)
            printf("%lld ",a[i]);
        printf("\n");
    }
    return 0;
}
