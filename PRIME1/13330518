#include<bits/stdc++.h>
using namespace std;
int a[1000005];
int main()
{
    int t;
    scanf("%d",&t);
    int m,n;

    while(t--)
    {
        scanf("%d %d",&m,&n);
         memset(a,0,sizeof(a));
        m=max(m,2);
        int x=sqrt(n);
        for(int i=2;i<=x;i++)
        {
            int s=m/i;
            int p=n/i;
            for(int j=max(s,2);j<=p+1;j++)
            {
                if(j*i>=m)
                    a[j*i-m]=1;
            }
        }
        for(int i=0;i<=n-m;i++)
        {
            if(a[i]==0)
                printf("%d\n",i+m);
        }
    }
}
