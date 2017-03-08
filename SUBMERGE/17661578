#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 10005
struct node {
	int u,v;
};
int min(int x, int y) {
	if(x<y) return x;
	return y;
}
struct node ed[100005];
int deg[N];
int sz[N];
int timer;
int tin[N], low[N];
int mark[N], point[N];
void dfs(int u, int par, int **V) {
	mark[u] = 1;
	low[u] = tin[u] = ++timer;
	int i, child = 0;
	for(i = 0; i < sz[u]; i++) {
		int v = V[u][i];
		if(v == par) continue;
		if(mark[v]) {
			low[u] = min(low[u], tin[v]);
		} else {
			dfs(v, u, V);
			low[u] = min(low[u], low[v]);
			if(low[v] >= tin[u] && par!=-1) {
				point[u] = 1;
			}
			++child;
		}
	}
	if(child>1 && par==-1) point[u] = 1;
}
void init() {
	memset(mark, 0,sizeof mark);
	memset(deg, 0, sizeof deg);
	memset(point, 0, sizeof point);
	memset(sz, 0, sizeof sz);
	memset(tin, 0, sizeof tin);
	memset(low, 0, sizeof low);
	timer = 0;
}
int main() {
	int n, m;
	while(1) {
		init();
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) return 0;
		int **V = (int**)malloc(sizeof(int*)*n);
		int i;
		for(i=0;i<m;i++) {
			int u,v;
			scanf("%d %d",&u,&v);
			u--;v--;
			deg[u]++; deg[v]++;
			ed[i].u = u;
			ed[i].v = v;
		}
		for(i=0;i<n;i++) {
			V[i] = (int*)malloc(sizeof(int)*deg[i]);
		}
		for(i=0;i<m;i++) {
			int u = ed[i].u;
			int v = ed[i].v;
			V[u][sz[u]++] = v;
			V[v][sz[v]++] = u;
		}
		dfs(0, -1, V);
		int ans = 0;
		for(i=0;i<n;i++) if(point[i]) ans++;
		printf("%d\n",ans);
	}
	return 0;
}