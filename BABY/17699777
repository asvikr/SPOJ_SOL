#include <bits/stdc++.h>

using namespace std;

const int N = 17;

int n;
int memo[N][1 << N];

pair <int, int> queen_pos[N];
pair <int, int> actual_pos[N];

inline int diff(int a, int b) {
	return (a > b) ? a - b : b - a;
}

inline int stepToreach(int i, int j) {
	int step = diff(queen_pos[i].first, actual_pos[j].first);
	step += diff(queen_pos[i].second, actual_pos[j].second);
	return step;
}

int solve(int cur, int mask) {
	if (mask + 1 == (1 << n)) {
		return 0;
	}
	if (memo[cur][mask] != -1) {
		return memo[cur][mask];
	}
	int ans = (int)2e9;
	for (int i = 0; i < n; i++) {
		if (((mask >> i) & 1) == 0) {
			ans = min(ans, solve(cur + 1, mask | (1 << i)) + stepToreach(cur, i));
		}
	}
	return memo[cur][mask] = ans;
}

int main() {
	while (true) {
		scanf("%d", &n);
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			queen_pos[i] = make_pair(x - 1, i);
		}
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			actual_pos[i] = make_pair(x - 1, i);
		}
		memset(memo, -1, sizeof memo);
		int ans = solve(0, 0);
		printf("%d\n", ans);
	}
}