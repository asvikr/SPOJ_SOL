#include<bits/stdc++.h>
using namespace std;
int x[]={2,2,1,1,-2,-2,-1,-1};
int y[]={1,-1,2,-2,1,-1,2,-2};
int chk[9][9],dist[9][9];
void bfs(int x1,int y1,int x2,int y2)
{
    for(int i=1;i<=8;i++)
        for(int j=1;j<=8;j++)
       {
          chk[i][j]=0;
          dist[i][j]=INT_MAX;
       }
    dist[x1][y1]=0;
    queue<pair<int,int> > Q;
    Q.push(make_pair(x1,y1));
    while(!Q.empty())
    {
        pair<int,int> top=Q.front();
        int xx=top.first;
        int yy=top.second;
        Q.pop();
        if(xx==x2 && yy==y2)
            return;
        if(chk[xx][yy]==1)
            continue;
        chk[xx][yy]=1;
        for(int i=0;i<8;i++)
        {
            int xx1=xx+x[i];
            int yy1=yy+y[i];
            if(xx1>0 && yy1<9 && xx1<9 && yy1>0)
            {
            dist[xx1][yy1]=min(dist[xx1][yy1],dist[xx][yy]+1);
            Q.push(make_pair(xx1,yy1));
            }
        }
    }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char str[3],str1[3];
        scanf("%s %s",str,str1);
        int x1=(str[0]-'a')+1;
        int y1=str[1]-'0';
        int x2=(str1[0]-'a')+1;
        int y2=str1[1]-'0';
        bfs(x1,y1,x2,y2);
        printf("%d\n",dist[x2][y2]);
    }
    return 0;
}
