#include<iostream>
#include<cstdio>
#include<cmath>
typedef long long int LL;
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        LL n;
        LL a,b,c;
        scanf("%lld",&n);
        if(n==1)
        {
            printf("TERM %d IS ",n);
            printf("1/1\n");
            continue;
        }
        if(n==3)
        {
            printf("TERM %d IS ",n);
            printf("2/1\n");
            continue;
        }
         a=(int)((-1+(sqrt(1.0+4*n*2)))/2);
        float ch;
        ch=sqrt(1.0+4*n*2);
        if(ch==(int)ch)
        a-=1;
        //printf("%d\n",a);
         b=n-((a*(a+1))/2);
         a+=1;
         if(a%2!=0)
         {
             printf("TERM %d IS ",n);
             printf("%d",(a+1-b));
            printf("/");
            printf("%d\n",b);
         }
         else
         {
             printf("TERM %d IS ",n);
            printf("%d",b);
            printf("/");
            printf("%d\n",(a+1-b));
         }
    }
    return 0;
}
