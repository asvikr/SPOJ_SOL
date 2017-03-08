#include<stdio.h>
#define m 1000000007
int main()
{
    long long int t,a,n,sum,count,i;
    scanf("%lld",&t);
    while(t--)
    {
        sum=0;count=0;
        printf("\n");
        scanf("%lld",&n);
        for(i=0;i<n;i++)
        {
            scanf("%lld",&a);
            sum=(sum+a)%n;
            count++;
        }
        if(sum%count)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}
