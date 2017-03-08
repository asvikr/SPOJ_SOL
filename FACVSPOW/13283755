#include<iostream>
#include<cstdio>
#include<algorithm>
#include<math.h>
typedef long long int LL;
using namespace std;
double a[2718275];
void fun()
{
    a[0]=0;
    double fact=0;
    for(int i=1;i<=2718274;i++)
    {
        fact=(double)(log10(i*1.0)+fact);
        a[i]=(double)fact/i;
    }
    //printf("%f",a[4]);
    return;
}
int main()
{
    int n;
    scanf("%d",&n);
    int x,k;
    fun();
    while(n--)
    {
        scanf("%d",&x);
        double p=log10(x*1.0);  
        //printf("\n%f\n",p);
        //if(p<a[100000])
        k=upper_bound(a,a+2718274,p)-a;
       /* else
        {
             k=pow(10,p+0.434);
        }*/
        printf("%d\n",k);
    }
    return 0;
}
