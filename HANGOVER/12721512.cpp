#include<iostream>
#include<cstdio>
using namespace std;
 float a[530];
 int solve(float x,int l,int r)
 {
     if(r>l)
     {
         int m=l+(r-l)/2;
         if(a[m]>=x && a[m-1]<x)
            return m;
         else if(a[m]>x)
            solve(x,l,m);
         else if(a[m]<x)
            solve(x,m+1,r);
     }
 }
int main()
{

    a[0]=0;
    a[1]=0;
    for(int i=2;i<530;i++)
    {
        a[i]=a[i-1]+(float)1/i;
    }
    float x;
    while(1)
    {
    scanf("%f",&x);
    if(x==0.00)
        break;
    int p=solve(x,1,529);
    printf("%d card(s)\n",p-1);
    }
    return 0;
}
