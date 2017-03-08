#include <bits/stdc++.h>
using namespace std;
const int N = 10005;
vector<int> V[N];
bool mark[N];
int tin[N], low[N];
int timer;
int point[N];
void dfs(int x, int par) {
  mark[x] = 1;
  tin[x] = low[x] = ++timer;
  int child = 0;
  for(int u: V[x]) {
    if(u == par) continue;
    if(mark[u]) {
      low[x] = min(tin[u], low[x]);
    } else {
      dfs(u, x);
      low[x] = min(low[x], low[u]);
      if(low[u] >= tin[x] && par!=-1) {
        point[x] = 1;
      }
      ++child;
    }
  }
  if(par == -1 && child > 1) point[x] = 1;
}
void init() {
  for(int i =1;i<N ;i++) {
    V[i].clear();
    mark[i] = 0;
    tin[i] = low[i] = 0;
    point[i] = 0;
  }
  

}
int main() {
  int n, m;
  while(1) {
  scanf("%d %d",&n,&m);
  init();
  if(n==0 && m==0) return 0;
  for(int i=0;i<m;i++) {
    int u,v;
    scanf("%d %d",&u,&v);
    V[u].push_back(v);
    V[v].push_back(u);
  }
  dfs(1, -1);
 // printf("********************************");
  //for(int i=1;i<=n;i++) printf("%d %d %d\n",i, tin[i], low[i]);
  //for(int x:point) printf("%d ",x);
  int ans = 0;
  for(int i = 1;i<=n;i++) if(point[i]) ans++;
  printf("%d\n",ans);
 }
}
/*
7 8
1 2
1 5
2 3
2 4
2 6
3 5
3 7
4 7
*/