#include<bits/stdc++.h>
using namespace std;
int flag[2005];
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
int main()
{
    int t;
    scanf("%d",&t);
    //t=read();
    for(int k=1;k<=t;k++)
    {
        printf("Scenario #%d:\n",k);
        int n,in;
        //n=read();
        //in=read();
        scanf("%d %d",&n,&in);
        int u,v;
        vector<int> V[2005];
        for(int i=0;i<in;i++)
        {
            //u=read();
            //v=read();
            scanf("%d %d",&u,&v);
            V[u].push_back(v);
            V[v].push_back(u);
        }
        int chk[2005];
        memset(chk,0,sizeof(chk));
        for(int i=1;i<=n;i++)
            flag[i]=-1;
    int temp=1;
    for(int i=1;i<=n;i++)
    {
        if(chk[i]==0)
        {
         flag[i]=1;
         queue<int> Q;
         Q.push(i);
         while(!Q.empty())
         {
          int p=Q.front();
           Q.pop();
           chk[p]=1;
          vector<int> :: iterator it;
          for(it=V[p].begin();it!=V[p].end();it++)
          {
                if(flag[*it]==-1)
                    flag[*it]=!flag[p];
                else if(flag[*it]==flag[p])
                {
                        temp=0;
                        break;
                }
                if(chk[*it]==0)
                  Q.push(*it);
            }
            if(temp==0)
                break;
         }
        }
        if(temp==0)
            break;
    }
        if(temp==0)
            printf("Suspicious bugs found!\n");
        else
            printf("No suspicious bugs found!\n");
        temp=1;
    }
    return 0;
}
