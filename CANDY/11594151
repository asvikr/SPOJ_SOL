
#include<stdio.h>
int main()
{
    int n,a[10001],i,total,count,k;
    float av;
    while(1)
    {
        scanf("%d",&n);
        if(n==-1)
            return 0;
        count=0;
        total=0;
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        total=total+a[i];
    }
    av=total/n;
    k=total%n;
    if(k==0)
    {
        for(i=0;i<n;i++)
        {
            if(a[i]>av)
            count+=a[i]-av;
        }
        printf("%d\n",count);
    }
    else
        printf("-1\n");
    }
    return 0;
}
