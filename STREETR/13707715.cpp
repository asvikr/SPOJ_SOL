#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    scanf("%d",&n);
    int a[n],b[n];
    int g=0;
    scanf("%d",&a[0]);
    for(int i=1;i<n;i++)
    {
        scanf("%d",&a[i]);
        g=__gcd(g,a[i]-a[i-1]);
        b[i]=a[i]-a[i-1];
    }
    int ans=0;
    for(int i=1;i<n;i++)
        ans+=(b[i]/g)-1;
    printf("%d\n",ans);
    return 0;
}
