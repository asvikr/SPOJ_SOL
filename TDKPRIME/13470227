#include<bits/stdc++.h>
using namespace std;
const int MAX=100000000;
const int LMT=10000;
const int LEN=6000010;
int flag[MAX>>6];
int prime[LEN];
int cnt=1;
#define ifc(x) (flag[x>>6]&(1<<((x>>1)&31)))
#define isc(x) (flag[x>>6]|=(1<<((x>>1)&31)))
void sieve()
{
   int k,i,j;
    for(i=3;i<LMT;i+=2)
    {
        if(!ifc(i))
            for(j=i*i,k=i<<1;j<MAX;j+=k)
            isc(j);
    }
    cnt=1;
    prime[cnt++]=2;
    for(i=3;i<MAX;i+=2)
    {
        if(!ifc(i))
        {
            prime[cnt++]=i;
        }
    }
    return;
}
int main()
{
    sieve();
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        printf("%d\n",prime[n]);
    }
    return 0;
}
