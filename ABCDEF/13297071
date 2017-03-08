#include<bits/stdc++.h>
using namespace std;
int b[1000005];
/*inline int read()
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
}*/
//map<int,int> M;
//map<int,int> M;
int main()
{
    int n,val;
    //n=read();
    scanf("%d",&n);
    int a[105];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    //    a[i]=read();
    }
    int cnt=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          for(int k=0;k<n;k++)
          b[cnt++]=(a[i]*a[j])+a[k];
    sort(b,b+cnt);
           int ans=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
          for(int k=0;k<n;k++)
          {
          if(a[k]!=0)
          {
          val=(a[i]+a[j])*a[k];
          ans+=upper_bound(b,b+cnt,val)-lower_bound(b,b+cnt,val);
          }
          }
    printf("%d\n",ans);
    return 0;
}
