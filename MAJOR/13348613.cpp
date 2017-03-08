#include<bits/stdc++.h>
using namespace std;
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
int main()
{
    int t,n;
   // scanf("%d",&t);
   t=read();
    while(t--)
    {
       // scanf("%d",&n);
       n=read();
        int x,temp=0;
        map<int,int> M;
        for(int i=0;i<n;i++)
        {
            //scanf("%d",&x);
            x=read();
            M[x]++;
            if(M[x]>n/2)
                temp=x;
        }
        if(temp!=0)
            printf("YES %d\n",temp);
        else
            printf("NO\n");
    }
    return 0;
}
