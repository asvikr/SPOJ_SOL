#include<bits/stdc++.h>
typedef long long int LL;
using namespace std;
LL a[1050000];
int main()
{
    int k;
    scanf("%d",&k);
    int n;
    while(k--)
    {
        memset(a,0,sizeof(a));
    scanf("%d",&n);
    vector<pair<int,int> > V(n);
    int D[n];
    int b,h,w,d;
    int maxi=-1;
    for(int i=0;i<n;i++)
    {
        scanf("%d %d %d %d",&b,&h,&w,&d);
        V[i].first=b;
        V[i].second=b+h;
        D[i]=w*d;
        if(maxi<h+b)
            maxi=h+b;
        int p=w*d;
        for(int j=b+1;j<=b+h;j++)
        {
            a[j]+=p;
           // printf("a[%d]=%d ",j,a[j]);
        }
       // printf("\n");
    }
    for(int i=1;i<=maxi;i++)
    {
        a[i]=a[i-1]+a[i];
        //printf("%d ",a[i]);
    }
    LL v;
    scanf("%lld",&v);
    if(a[maxi]<v)
    {
        printf("OVERFLOW\n");
        continue;
    }
    int ans=lower_bound(a,a+maxi,v)-a;
    int ans1=upper_bound(a,a+maxi,v)-a;
    if(a[ans]==v)
    printf("%0.2f\n",(float)ans);
    else
    {
       // printf("ans1=%d\n",ans1);
        float ch=0.0;
        for(int i=0;i<n;i++)
        {
            if(ans1<=V[i].second && ans>V[i].first)
            {
                ch+=D[i];
            }
        }
        int req=v-a[ans];
        float r=(float)(ans+(float)req/ch);
        printf("%.2f\n",r);
    }
    }
}
