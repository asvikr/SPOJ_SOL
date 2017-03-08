#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
const int MAX=100005;
int prime[100005];
bool mark[100005];
int cnt=0;
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
void sieve()
{
    prime[cnt++]=2;
    int k=sqrt(MAX+100);
     int p=sqrt(k+100);
    for(int i=3;i<=p;i+=2)
    {
        if(!mark[i])
        {
            for(int j=i*i;j<=k;j+=2*i)
                mark[j]=1;
        }
    }
    for(int i=3;i<=k;i+=2)
    {
        if(!mark[i]){
            prime[cnt++]=i;
            //printf("%d ",i);
        }
    }
}
int k=0;
void fun(int fact[],int n,int m)
{
    for(int i=0;i<cnt && prime[i]<=m;i++)
    {
        if(n%prime[i]==0){
            fact[k++]=prime[i];
            while(n%prime[i]==0)
            {
                n/=prime[i];
            }
        }
    }
    if(n>1 && n<=m)
        fact[k++]=n;

}
int cal(int m,int k,int fact[])
{
    int p=1,sz=0,to=0;
    int var=pow(2,k);
    for(int i=1;i<var;i++)
    {
        p=1;
        sz=0;
        for(int j=0;j<k;j++)
        {
            if(i&(1<<j))
            {
                p=p*fact[j];
                sz++;
            }
        }
        if(sz&1)
            to+=m/p;
        else
            to-=m/p;
    }
    return to;
}
int main()
{
    sieve();
    int q,n,m;
    scanf("%d",&q);
   //q=read();
    while(q--)
    {
        scanf("%d %d",&n,&m);
        //n=read();
        //m=read();
        int ans=m;
        k=0;
        int fact[30];
        fun(fact,n,m);
        //printf("%d\n",fact.size());
        if(k==0)
        {
            printf("%d\n",m);
            continue;
        }
        printf("%d\n",m-cal(m,k,fact));
    }
    return 0;
}
