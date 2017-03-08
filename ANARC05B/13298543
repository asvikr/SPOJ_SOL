#include<bits/stdc++.h>
using namespace std;
int solve(int arr[],int l,int r,int val)
{
    if(l>r)
        return 0;
    int mid=(l+r)/2;
    if(arr[mid]==val)
        return mid;
    else if(arr[mid]>val)
        return solve(arr,l,mid-1,val);
    else
        return solve(arr,mid+1,r,val);
}
int main()
{
    int n1,n2,a[10005],b[10005],a1[10005],b1[10005];
    while(1)
    {
        scanf("%d",&n1);
        if(n1==0)
            return 0;
        a[0]=0;
        b[0]=0;
        a1[0]=-999999;
        b1[0]=-999999;
        for(int i=1;i<=n1;i++)
            {
                scanf("%d",&a1[i]);
                a[i]=a[i-1]+a1[i];
            }
        scanf("%d",&n2);
        for(int i=1;i<=n2;i++)
        {
            scanf("%d",&b1[i]);
            b[i]=b[i-1]+b1[i];
        }
        long long int ans=0;
        int prev1=0,prev2=0;
        for(int i=1;i<=n1;i++)
        {
            int k = solve(b1,prev1,n2,a1[i]);
            //printf("k=%d\n",k);
            if(k!=0)
            {
                ans+=max(b[k]-b[prev1],a[i]-a[prev2]);
                //printf("%lld\n",ans);
                prev1=k;
                prev2=i;
            }
        }
        ans+=max(b[n2]-b[prev1],a[n1]-a[prev2]);
        printf("%lld\n",ans);
    }
    return 0;
}
