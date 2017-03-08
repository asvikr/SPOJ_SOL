#include<iostream>
#include<cstdio>
using namespace std;
typedef long long int LL;
int main()
{
    LL n;
    scanf("%lld",&n);
    LL x,temp,y;
    x=n;
    int cnt=0;
    LL ans;
    for(int i=0;i<10000;i++)
    {
    ans=0;
    while(x!=0)
    {
        temp=x%10;
        ans+=temp*temp;
        x=x/10;
    }
    cnt++;
    if(ans==1)
        break;
    else
    {
        x=ans;
    }
    }
    if(ans==1)
    {
        printf("%d\n",cnt);
    }
    else
        printf("-1\n");
    return 0;
}
