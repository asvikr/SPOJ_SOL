#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    for(int i=1;i<=t;i++)
    {
        printf("Case %d: ",i);
        int r;
        scanf("%d",&r);
        float ans=0.0;
        ans=(float)4*r*r+0.25;
        printf("%0.2f\n",ans);
    }
    return 0;
}
