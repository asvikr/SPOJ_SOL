#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b)
{
    if(b==0)
        return a;
    return gcd(b,a%b);
}
void gcd1(char str[],int a)
{
    int l=strlen(str);
        if(l==1 && str[0]=='0'){
           printf("%d\n",a);
           return;
        }
        else if(a==0)
        {
            printf("%s\n",str);
            return;
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
        return;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[260];
        char str1[260];
        int k;
        scanf("%s",str);
        scanf("%s",str1);
        scanf("%d",&k);
        gcd1(str,pow(2,k));
    }
    return 0;
}
