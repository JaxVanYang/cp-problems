#include <iostream>

const int N = 1e5 + 10;
int a[N];

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	int ans = 0;
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			ans = std::max(ans, (j - i) * std::min(a[i], a[j]));
		}
	}
	std::cout << ans << std::endl;
}
