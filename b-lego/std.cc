#include <iostream>

const int N = 1e4 + 10;
int a[N], b[N][N];
int cur[N], min_b[N];
int n, m, k;

bool dfs(int left) {
	for (int i = 0; i < n; ++i) {
		if (cur[i] + left * min_b[i] > a[i]) return false;
		// if (cur[i] > a[i]) return false;
	}
	if (left == 0) return true;

	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cur[j] += b[i][j];
		}
		if (dfs(left - 1)) return true;
		for (int j = 0; j < n; ++j) {
			cur[j] -= b[i][j];
		}
	}

	return false;
}

int main() {
	std::cin >> n >> m >> k;

	for (int i = 0; i < n; ++i) std::cin >> a[i];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> b[i][j];
		}
	}
	for (int i = 0; i < n; ++i) {
		min_b[i] = b[0][i];
		for (int j = 1; j < m; ++j) {
			min_b[i] = std::min(min_b[i], b[j][i]);
		}
	}

	if (dfs(k)) puts("Yes");
	else puts("No");
}
