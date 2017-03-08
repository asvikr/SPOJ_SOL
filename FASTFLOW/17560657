#include <bits/stdc++.h>
using namespace std;

const int N = 5005;
const int INF = 1e9;

int n, m; // number of vertices and edges 

int source, dest;
int level[N], pointer[N], Queue[N];
// level[] = construct level graph
// pointer[] = points to current index of adjacency list
// Queue[] = Queue implementation for bfs

struct edge {
    int u, v, capacity, flow;
};

vector<edge> edges;
vector<int> g[N]; // adjacency list

void add_edge(int u, int v, int capacity) {
    edge e1 = {u, v, capacity, 0};
    edge e2 = {v, u, capacity, 0};
    g[u].push_back((int)edges.size());
    edges.push_back(e1);
    g[v].push_back((int)edges.size());
    edges.push_back(e2);
}

bool bfs() {
    memset(level, -1, sizeof level);
    level[source] = 0;
    int qhead = 0, qtail = 0;
    Queue[qtail++] = source;

    while(qhead < qtail && level[dest]==-1) {
        int u = Queue[qhead++];
        for(int i = 0; i<(int)g[u].size(); i++) {
            int id = g[u][i];
            int v = edges[id].v;
            if(level[v]==-1 && edges[id].capacity > edges[id].flow) { 
            // include this edge in out level graph only if capacity is greater than current flow
                Queue[qtail++] = v;
                level[v] = level[u] + 1;
            }
        }
    }
    return (level[dest]!=-1);
}

int dfs(int u, int flow) {
    if(!flow) return 0;
    if(u == dest) return flow;
    for(; pointer[u]<(int)g[u].size(); ++pointer[u]) {
        int id = g[u][pointer[u]];
        int v = edges[id].v;
        if(level[v]!=level[u]+1) continue;

        int pushed = dfs(v, min(flow, edges[id].capacity - edges[id].flow)); 
        // find blocking flow in augmented path from current node to source node

        if(pushed) {
            edges[id].flow += pushed; // increase the flow through edge
            edges[id^1].flow -= pushed; // decrease the flow in opposite direction
            return pushed;
        }
    }
    return 0;
}

long long dinic() {
    long long flow = 0;
    while(bfs()) {
        memset(pointer, 0, sizeof pointer);
        while(1) {
            int pushed = dfs(source, INF);
            if(pushed) flow += pushed;
            else break;
        }
    }
    return flow;
}

int main() {
    int u,v,cap;
    scanf("%d %d",&n,&m);
    for(int i=0; i<m; i++){
        scanf("%d %d %d",&u,&v,&cap);
        u--,v--;
        if(u != v)
        add_edge(u,v,cap);
    }
    source = 0,dest = n - 1;
    printf("%lld\n",dinic());
}