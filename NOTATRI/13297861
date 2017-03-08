#include<bits/stdc++.h>
using namespace std;
int n;
inline int read()
{
	int ret = 0;
	int c = getchar_unlocked();

	while(c<'0' || c>'9')
		c = getchar_unlocked();
	while(c>='0' && c<='9')
	{
		ret = (ret<<3) + (ret<<1) + c - '0';
		c = getchar_unlocked();
	}
        return ret;
}
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
    //scanf("%d",&n);
    n=read();
    if(n==0)
        return 0;
    int a[2005];
    for(int i=0;i<n;i++)
       a[i]=read(); //scanf("%d",&a[i]);
    sort(a,a+n);
    int ans=0;
    for(int i=0;i<n-2;i++)
    {
        for(int j=i+1;j<n-1;j++)
        {
            int p=a[i]+a[j];
            //ans+=n-solve(a,j+1,n-1,p);
            ans+=n-(upper_bound(a+j+1,a+n,p)-a);

        }
    }
    printf("%d\n",ans);
    }
    return 0;
}
