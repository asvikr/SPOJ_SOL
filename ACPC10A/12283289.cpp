#include<iostream>
#include<stack>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main()
{
    int p,q,r,i,d;
    while(1)
    {
        scanf("%d%d%d",&p,&q,&r);
        if(p || q || r)
        {
            d=q-p;
            if(d==(r-q))
                printf("AP %d\n",r+d);
            else
                printf("GP %d\n",(r*r)/q);
        }
        else
            exit(0);
    }
    return 0;
}
