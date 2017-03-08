#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(a==0)
        return b;
    return gcd(b%a,a);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        int m=gcd(a,b);
        int cnt=0;
        for(int i=1;i<=sqrt(m);i++)
        {
            if(m%i==0)
            {
                cnt+=2;
                if(i==sqrt(m))
                    cnt-=1;
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}
