#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m;
        scanf("%d %d",&n,&m);
        char str[n+1][m+1];
        for(int i=0;i<n;i++)
            scanf("%s",str[i]);
        vector<pair<int,int> > V(n*n);
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(str[i][j]=='1')
                {
                   V[cnt++]=make_pair(i,j);
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int mini=99999999;
                if(str[i][j]=='0')
                {
                    for(int k=0;k<cnt;k++)
                    {
                        if(mini>abs(i-V[k].first)+abs(j-V[k].second))
                            mini=abs(i-V[k].first)+abs(j-V[k].second);
                    }
                    printf("%d ",mini);
                }
                else
                    printf("0 ");
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}
