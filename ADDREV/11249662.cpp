#include<stdio.h>
int rev(int n)
{
    int temp,r=0;
    while(n>0)
    {
        temp=n%10;
        r=r*10+temp;
        n=n/10;
    }
    return r;
}
int main()
{
    int t,n1,n2,sum,rsum,rn1,rn2;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%d%d",&n1,&n2);
    rn1=rev(n1);
    rn2=rev(n2);
    sum=rn1+rn2;
    rsum=rev(sum);
    printf("%d\n",rsum);
    }
    return 0;
}
