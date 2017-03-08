#include<bits/stdc++.h>
using namespace std;
int a[10005];
int main()
{
    int n;
    for(int i=3;i<=sqrt(10000);i++)
    {
        if(a[i]==0)
        {
            for(int j=i*i;j<=10000;j+=i*2)
            {
                a[j]=1;
            }
        }
    }
    scanf("%d",&n);
    int cnt=0;
    int p=n,k=2;
    while((p/k)!=0)
    {
        cnt+=p/k;
        k=k*2;
    }
    printf("2^%d ",cnt);
    for(int i=3;i<=n;i++)
    {
        cnt=0;
        if(i%2!=0 && a[i]!=1)
        {
        k=i;
        while((n/k)!=0)
        {
            cnt+=n/k;
            k=k*i;
        }
        printf("* %d^%d ",i,cnt);
        }

    }
    return 0;
}
