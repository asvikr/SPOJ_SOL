#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int a[100005];
    int n;
    while(1)
    {
    scanf("%d",&n);
    if(n==0)
        break;
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&a[i]);
    }
    int temp=1;
    for(int i=1;i<=n;i++)
    {
        if(i==a[a[i]])
        continue;
        else
        {
            temp=0;
            break;
        }
    }
    if(temp==0)
        printf("not ambiguous\n");
    else
        printf("ambiguous\n");
    }
    return 0;
}
