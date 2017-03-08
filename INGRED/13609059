#include <iostream>
#include <map>
#include <cstring>
#include <fstream>
#include <cstdio>
#include <math.h>
#include <queue>
#include <stack>
#include <set>
#include <string>
#include <utility>
#include <cstdlib>
#include <cassert>
#include <algorithm>
#include <ctime>
#include <vector>
using namespace std;
#define fname ""
#define ull unsigned long long
#define INF 1000000000
#define LL long long
#define F first
#define S second
#define mp make_pair
const int N = 1000;
int n, m, a[N][N], b[N], p[N];
int s;
int s1, s2;

int main () {
	#ifndef ONLINE_JUDGE
    freopen ("in", "r", stdin);
    freopen ("out", "w", stdout);
    #endif

    cin >> n >> m;

    for (int i = 1; i <= n; i ++ ) {
	    for (int j = 1; j <= n; j ++ ) {
        	a[i][j] = INF;
        }
        a[i][i] = 0;
    }

    for (int i = 1; i <= m; i ++ ) {
    	int x, y, z;
    	cin >> x >> y >> z;
    	++x, ++y;
    	a[x][y] = a[y][x] = z;
    }

    for (int k = 1; k <= n; k ++ ) {
    	for (int i = 1; i <= n; i ++ ) {
    		for (int j = 1; j <= n; j ++ ) {
    			a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
    		}
    	}
    }

    cin >> s;

    for (int i = 0; i < s; i ++ ) {
    	cin >> b[i];
    	++b[i];
    }

    cin >> s1 >> s2;
    ++s1, ++s2;

    LL ans = INF;

    for (int mask = 0; mask < (1 << s); ++ mask) {
    	LL ans1 = INF, ans2 = INF;
    	int sz = 0;
    	for (int i = 0; i < s; ++ i) {
    		if ((mask & (1 << i))) {
    			p[++sz] = i;
    		}
    	}
    	if (!sz) ans1 = 0;
    	do {
    		int now = s1;
    		LL cost = 0;
    		for (int i = 1; i <= sz; ++ i) {
    			cost += a[now][b[p[i]]];
    			now = b[p[i]];
    		}
    		ans1 = min(ans1, cost);

    	}while(next_permutation(p + 1, p + 1 + sz));
    	sz = 0;
    	for (int i = 0; i < s; ++ i) {
    		if (!(mask & (1 << i))) {
    			p[++sz] = i;
    		}
    	}
    	if (!sz) ans2 = 0;
    	do {
    		int now = s2;
    		LL cost = 0;
    		for (int i = 1; i <= sz; ++ i) {
    			cost += a[now][b[p[i]]];
    			now = b[p[i]];
    		}
    		ans2 = min(ans2, cost);
    	}while(next_permutation(p + 1, p + 1 + sz));
    	ans = min(ans, ans1 + ans2);
    }

    cout << ans;

 	return 0;
}
