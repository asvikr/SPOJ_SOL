#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int a[50100],k,p;
        memset(a,0,sizeof(a));
        long long int ans=1,sum;
        for(int i=2;i<=n;i++)
        {
            k=i;
            if(a[i]==0)
            {
            sum=0;
            p=n/k;
            while(p>0)
            {
                sum+=p;
                k=k*i;
                p=n/k;
            }
            //printf("%d\n",sum);
            ans=(ans*(sum+1))%M;
            for(int j=i;j<=n;j+=i)
                a[j]=1;
            }

        }
        printf("%lld\n",ans);
    }
    return 0;
}
