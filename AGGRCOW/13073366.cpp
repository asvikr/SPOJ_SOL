#include<iostream>
#include<cstdio>
#include<algorithm>
typedef long long int LL;
using namespace std;
 int a[100005];
int n,c;
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
int f(int x)
{
    int cowplaced=1;
    int lastpos=a[0];
    for(int i=1;i<n;i++)
    {
        if(a[i]-lastpos>=x)
        {
            cowplaced++;
            if(cowplaced==c)
            {
                return 1;
            }
            lastpos=a[i];
        }
    }
    return 0;
}
int solve()
{
    int st=0;
    int en=a[n-1];
    int mid;
    while(en>st)
    {
        mid=(st+en)/2;
        if(f(mid)==1)
        {
            st=mid+1;
        }
        else
            en=mid;
    }
    return st-1;
}
int main()
{
    int t;
    //scanf("%d",&t);
    t=read();
    while(t--)
    {
        n=read();
        c=read();
       // scanf("%d%d",&n,&c);
        for(int i=0;i<n;i++)
          a[i]=read();//  scanf("%d",&a[i]);
            sort(a,a+n);
        int k=solve();
        printf("%d\n",k);
    }
}
