#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a;
        char str[260];
        scanf("%d",&a);
        scanf("%s",str);
        int l=strlen(str);
        if(l==1 && str[0]=='0'){
            printf("%d\n",a);
             continue;
        }
        else if(a==0)
        {
            printf("%s\n",str);
            continue;
        }
        int num=0;
        for(int i=0;i<l;i++)
        {
            num=num*10+(str[i]-'0');
            if(num>a)
                num=num%a;
        }
        num%=a;
        printf("%d\n",gcd(num,a));
    }
    return 0;
}
