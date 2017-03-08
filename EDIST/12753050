#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int a[3000][3000];
int main()
{
    char str1[3000],str2[3000];
    int t;
    scanf("%d",&t);
    while(t--)
    {
    scanf("%s",str1);
    scanf("%s",str2);
    int m=strlen(str1);
    int n=strlen(str2);
    for(int i=0;i<=m;i++)
        a[i][0]=i;
    for(int i=0;i<=n;i++)
        a[0][i]=i;
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(str1[i-1]==str2[j-1])
            {
                a[i][j]=a[i-1][j-1];
            }
             else if(str1[i-1]!=str2[j-1])
            {
                a[i][j]=min(a[i][j-1],min(a[i-1][j],a[i-1][j-1]))+1;
            }
        }
    }
    printf("%d\n",a[m][n]);
    }
    return 0;
}
