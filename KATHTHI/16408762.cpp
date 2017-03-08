#include <bits/stdc++.h>
using namespace std;
#define f first
#define sc second
#define inf (int)(1e9)
#define mp make_pair
const int N=1005;
char str[N][N];
bool vis[N][N];
int xx[]={1,0,-1,0};
int yy[]={0,1,0,-1};
deque<pair<int,pair<int,int> > > Q;
int r,c;
int d[N][N];
int solve()
{
	Q.clear();
	for(int i=0;i<r;i++) for(int j=0;j<c;j++) d[i][j]=inf;
	d[0][0]=0;
	Q.push_back(mp(0,mp(0,0)));
	while(!Q.empty()){
		pair<int,pair<int,int> > p=Q.front();
		Q.pop_front();
		int x=p.sc.f;
		int y=p.sc.sc;
		int dis=p.f;
		for(int i=0;i<4;i++){
			if(x+xx[i]>=0 && x+xx[i]<r && y+yy[i]>=0 && y+yy[i]<c){
				int k=0;
				if(str[x][y]!=str[x+xx[i]][y+yy[i]]) k=1;
				if(d[x+xx[i]][y+yy[i]]>d[x][y]+k){
					d[x+xx[i]][y+yy[i]]=d[x][y]+k;
					if(k==1) Q.push_back(mp(d[x+xx[i]][y+yy[i]],mp(x+xx[i],y+yy[i])));
					else Q.push_front(mp(d[x+xx[i]][y+yy[i]],mp(x+xx[i],y+yy[i])));
				}
			}
		}
	}
	return d[r-1][c-1];
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		
		scanf("%d %d",&r,&c);
		for(int i=0;i<r;i++) scanf("%s",str[i]);
		printf("%d\n",solve());
	}
}