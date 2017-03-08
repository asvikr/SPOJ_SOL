#include<bits/stdc++.h>
using namespace std;
int n;
int solve(int a[],int l,int r,int val)
{
    if(l>r)
        return n;
    int mid=(l+r)/2;
    if((a[mid]>val) && (a[mid-1]<=val))
        return mid;
    else if(a[mid]>val)
        return solve(a,l,mid,val);
    else
        return solve(a,mid+1,r,val);
}
int main()
{
    while(1)
    {
    scanf("%d",&n);
    if(n==0)
        return 0;
    int a[2005];
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            int p=a[i]+a[j];
            ans+=n-solve(a,j+1,n-1,p);
    //printf("%d\n",ans);
        }
    }
    printf("%d\n",ans);
    }
    return 0;
}
