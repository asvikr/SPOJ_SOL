#include <iostream>  
#include <stdio.h>  
using namespace std;  

#define MAX 102  

int a[MAX];  
int d[MAX];  

int X[MAX];  

int procMod(int a,int b)  
{  
    if(a % b >=0)  
    {  
        return a % b;  
    }  
    else  
    {  
        return a % b + b;  
    }  
}  

void exGcd(int a,int b,int &d,int &x,int &y)  
{  
    if(b == 0)  
    {  
        x = 1;  
        y = 0;  
        d = a;  
        return ;  
    }  

    exGcd(b,a%b,d,x,y);  

    int temp = x;  
    x = y;  
    y = temp - a/b*y;  
    return ;  
}  

int judge(int n,int b,int m)  
{  
    int x,y;  
    for(int i=0; i<n; i++)  
    {  
        if(i == 0)  
        {  
            exGcd(a[0],m,d[0],x,y);  
        }  
        else  
        {  
            exGcd(d[i-1],a[i],d[i],x,y);  
        }  
    }  
    if(b%d[n-1] == 0)  
    {  
        return 1;  
    }  
    else  
    {  
        return 0;  
    }  
}  

int main()  
{  
    int T;  

    int n,b,m;  
    int b2;  

//#ifndef ONLINE_JUDGE  
//  freopen("in.txt","r",stdin);  
//#endif  

    scanf("%d",&T);  
    while(T--)  
    {  
        scanf("%d",&n);  
        for(int i=0; i<n; i++)  
        {  
            scanf("%d",&a[i]);  
        }  
        scanf("%d %d",&b,&m);  

        b = b%m;  
        for(int i=0; i<n; i++)  
        {  
            a[i] = a[i]%m;  
        }  

        if(judge(n,b,m) == 1)  
        {  
            b2 = b;  
            for(int i=n; i>0; i--)  
            {  
                int x,y;  
                int temp_d;  
                int current;  
                if(i!=n)  
                {  
                    current = int((long long)a[i] * X[i] % m);  
                }  

                else  
                {  
                    current = 0;  
                }  
                b = procMod(-current + b ,m);  
                if(i>1)  
                {  
                    exGcd(a[i-1],d[i-2],temp_d,x,y);  
                    b2 =  b % d[i-2];  
                    X[i-1] = int((long long)x * (b2/temp_d) % d[i-2]);  
                    if(X[i-1]<0)  
                    {  
                        X[i-1] = X[i-1] + d[i-2];  
                    }  
                }  
                else  
                {  
                    exGcd(a[0],m,temp_d,x,y);  
                    b2 =  b % m;  
                    X[0] = int((long long)x * (b2/temp_d) % m);  
                    if(X[0]<0)  
                    {  
                        X[0] = X[0] + m;  
                    }  
                }  
            }  
            for(int i=0;i<n-1;i++)  
            {  
                printf("%d ",X[i]);  
            }  
            printf("%d\n",X[n-1]);  
        }  
        else  
        {  
            printf("NO\n");  
        }  
    }  
    return 0;  
} 