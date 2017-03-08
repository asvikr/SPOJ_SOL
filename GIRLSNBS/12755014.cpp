#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main()
{
    int g,b,k;
    while(1)
    {
    scanf("%d%d",&g,&b);
    if(g==-1 && b==-1)
        break;
    if(b==0)
        printf("%d\n",g);
    else if(g==0)
    {
        printf("%d\n",b);
    }
    else if(b==g+1 || g==b+1)
        printf("1\n");
    else if((k=max(g,b)%(min(g,b)+1))==0)
    {
        printf("%d\n",max(g,b)/(min(g,b)+1));
    }
    else
    {
        printf("%d\n",max(g,b)/(min(g,b)+1)+1);
    }
    }
    return 0;
}
