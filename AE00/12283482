#include<stdio.h>
long long int a[10002]={0};
long long int find(int n)
{
    int i,m=sqrt(n);
    long long int k=0;
    if(a[n]==0)
    {
    for(i=1;i<=m;i++)
    {
        if(n%i==0)
           k++;
    }
    a[n]=k;
    }

    return a[n];
}
int main()
{
    int n,i;
    long long int count=0;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        count+=find(i);
    }
    printf("%lld\n",count);
    return 0;
}
