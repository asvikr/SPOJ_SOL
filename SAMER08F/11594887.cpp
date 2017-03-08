#include<stdio.h>
int main()
{
    int n,ans,i;
    while(1)
    {
        scanf("%d",&n);
        if(n==0)
            return 0;
            ans=0;
        for(i=1;i<=n;i++)
            ans=ans+i*i;
        printf("%d\n",ans);
    }
    return 0;
}
