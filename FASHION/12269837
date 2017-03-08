#include<stdio.h>
int compare(const int *a,const int *b)
{
    return(*(int*)a - *(int*)b);
}
int main()
{
    int t,n,sum,a[1002],b[1002],i;
    scanf("%d",&t);
    while(t--)
    {
        sum=0;
        scanf("%d",&n);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        for(i=0;i<n;i++)
            scanf("%d",&b[i]);
        qsort(a,n,sizeof(int),compare);
        qsort(b,n,sizeof(int),compare);
        for(i=0;i<n;i++)
            sum+=a[i]*b[i];
        printf("%d\n",sum);
    }
    return 0;
}
