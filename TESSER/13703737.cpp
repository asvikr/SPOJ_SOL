#include<bits/stdc++.h>
using namespace std;
int lps[100005];
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
void clc(char pat[],int m)
{
    lps[0]=0;
    int k=0,i=1;
    while(i<m)
    {
        if(pat[i]==pat[k])
            lps[i++]=++k;
        else
        {
            if(k==0)
                lps[i++]=0;
            else
                k=lps[k-1];
        }
    }
}
int b=0;
void Kmp(char text[],int n,char pat[],int m)
{
    int k=0,i=0,j=0;
    while(i<n)
    {
        if(text[i]==pat[j])
        {
            i++;
            j++;
        }
        if(j==m)
        {
            b=1;
            printf("YES");
            j=lps[j-1];
            break;
        }
        if(text[i]!=pat[j])
        {
            if(j!=0)
                j=lps[j-1];
            else
                i=i+1;
        }
    }
    return;
}
int main()
{
    int t;
    //scanf("%d",&t);
    t=read();
    while(t--)
    {
        int n,i;
        //scanf("%d",&n);
        n=read();
        char text[100005],pat[100005];
        int a[n];
        //scanf("%d",&a[0]);
        a[0]=read();
        for(i=1;i<n;i++)
        {
           // scanf("%d",&a[i]);
            a[i]=read();
            if(a[i]>a[i-1])
                text[i-1]='G';
            else if(a[i]<a[i-1])
                text[i-1]='L';
            else
                text[i-1]='E';
        }
        text[i-1]='\0';
        scanf("%s",pat);
        int l=strlen(pat);
        clc(pat,l);
        Kmp(text,i-1,pat,l);
        if(b==0)
            printf("NO");
        printf("\n");
        b=0;
        memset(lps,0,sizeof(lps));
    }
    return 0;
}
