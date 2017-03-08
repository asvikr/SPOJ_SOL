#include<bits/stdc++.h>
using namespace std;
const int M=10000005;
int a[M];
const int sq=sqrt(M);
int main()
{
    int n;
    for(int i=2;i<=sq;i++)
    {
        if(a[i]==0)
        {
            for(int j=2*i;j<=M;j+=i)
                a[j]=i;
        }
    }
   /* for(int i=2;i<=100;i++)
    {
        if(a[i])
            printf("%d ",a[i]);
        else
            printf("%d ",i);
    }
    printf("\n");*/
    while(scanf("%d",&n)!=EOF)
    {
    multiset<int> S;
        while(n!=1)
        {
            if(a[n]==0)
            {
                S.insert(n);
                //printf("%d\n",n);
                n/=n;
            }
            else
            {
                S.insert(a[n]);
               // printf("%d\n",a[n]);
                n=n/a[n];
            }

        }
       printf("1");
       set<int> :: iterator it;
       for(it=S.begin();it!=S.end();it++)
        {
            printf(" x %d",(*it));
        }
       printf("\n");
    }
    return 0;
}
