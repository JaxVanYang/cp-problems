#include <iostream>
#include <vector>
#include <queue>

const int N = 15;
int a[N], b[N][N];
int n, m, k;

struct Node {
	int left, p;
	std::vector<int> cur;

	inline bool operator <(const Node &node) const {
		if (left > node.left) return true;
		if (left == node.left) {
			if (p > node.p) return true;
			if (p == node.p && cur > node.cur) return true;
		}
		return false;
	}
};

int main() {
	std::cin >> n >> m >> k;
	for (int i = 0; i < n; ++i) std::cin >> a[i];
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> b[i][j];
		}
	}

	std::priority_queue<Node> pq;
	pq.push(Node{k, 0, std::vector<int>(n, 0)});
	while (pq.size()) {

		Node node = pq.top();
		pq.pop();
		if (node.left == 0) {
			puts("Yes");
			return 0;
		}
		if (node.p == m) continue;
		++node.p;
		pq.push(node);

		while (node.left) {
			bool flag = false;
			for (int j = 0; j < n; ++j) {
				node.cur[j] += b[node.p - 1][j];
				if (node.cur[j] > a[j]) {
					flag = true;
					break;
				}
			}
			if (flag) break;
			--node.left;
			pq.push(node);
		}
	}

	puts("No");
}
