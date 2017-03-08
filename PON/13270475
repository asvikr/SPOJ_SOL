#include<bits/stdc++.h>
typedef unsigned long long int LL;
using namespace std;
LL mul(LL a,LL b,LL c){
    LL x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
        b /= 2;
    }
    return x%c;
}
LL modulo(LL a,LL n,LL m)
{
    LL ans=1,y=a%m;
    while(n>0)
    {
        if(n%2)
            ans=mul(ans,y,m);
        y=mul(y,y,m);
        n/=2;
    }
    return ans%m;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
    LL p;
    scanf("%lld",&p);
    if(p==2)
    {
        printf("YES\n");
        continue;
    }
         if((p%2==0) && (p!=2))
            {
                printf("NO\n");
                continue;
            }
        LL s=p-1;
        while(s%2==0)
            s/=2;
        LL a,temp;
        int ch=1;
        for(int i=0;i<20;i++)
        {
         a=rand()%(p-1)+1;
         temp=s;
         LL mod=modulo(a,temp,p);
        // printf("%lld\n",mod);
         while((temp!=p-1) && (mod!=1) && (mod!=p-1))
         {
             mod=mul(mod,mod,p);
            // printf("%lld\n",mod);
             temp*=2;
         }
         if((temp%2==0) && (mod!=p-1))
         {
            printf("NO\n");
             ch=0;
             break;
         }
        }
        if(ch==1)
        {
            printf("YES\n");
        }
}
        return 0;
}
