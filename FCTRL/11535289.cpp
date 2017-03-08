#include<stdio.h>
#include<math.h>
int main()
{
    long long int t,n,i,k,sum;
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld",&n);
        sum=0;
        i=1;
        while(k=(n/(pow(5,i))))
        {
            sum=sum+k;
            i++;
        }
        printf("%lld\n",sum);
    }
    return 0;
}
