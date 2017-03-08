#include<bits/stdc++.h>
using namespace std;
int fun(int n)
{
    if(n<=1)
        return 1;
    return n*fun(n-1);
}
int main()
{
    int n,k;
    int x;
    while(scanf("%d %d",&n,&k)!=EOF)
    {
        int ans=fun(n);
        for(int i=1;i<=k;i++)
        {
            scanf("%d",&x);
            ans/=fun(x);
        }
        printf("%d\n",ans);
        }
    return 0;
}

