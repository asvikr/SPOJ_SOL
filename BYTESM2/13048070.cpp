#include<iostream>
#include<cstdio>
#include<math.h>
#include<algorithm>
#include<sstream>
using namespace std;
int a[105][105];inline int read()
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
int dp[105][105];

int main()
{
    int t;
    //scanf("%d",&t);
    t=read();
    while(t--)
    {
    int h,w;
    //scanf("%d %d",&h,&w);
    h=read();
    w=read();
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
           a[i][j]=read(); //scanf("%d",&a[i][j]);
    }
    for(int i=0;i<=h;i++)
   {
    dp[i][0]=0;
    dp[i][w+1]=0;
   }
   for(int i=0;i<=w;i++)
    dp[0][i]=0;
   int ans=0;
    for(int i=1;i<=h;i++)
    {
        for(int j=1;j<=w;j++)
        {
            dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j+1],dp[i-1][j]))+a[i][j];
           if(i==h)
           {
                ans=max(ans,dp[i][j]);
               // printf("%d ",dp[i][j]);
           }
        }
    }
    printf("%d\n",ans);
}
return 0;
}
