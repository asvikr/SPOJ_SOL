#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    char str[1005];
    long long int n;
    int t;
    int a[][5]={{0},{1},{2,4,8,6},{3,9,7,1},{4,6},{5},{6},{7,9,3,1},{8,4,2,6},{9,1}};
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",str);
        int l=strlen(str);
        int k = str[l-1]-'0';
        scanf("%lld",&n);
        if(n==0 || k==1)
             printf("1\n");
        else if(k==2 || k==3 || k==7 || k==8)
            printf("%d\n",a[k][(n-1)%4]);
        else if(k==9 || k==4)
            printf("%d\n",a[k][(n-1)%2]);
        else
            printf("%d\n",k);
    }
    return 0;
}
