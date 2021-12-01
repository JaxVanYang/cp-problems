#include <iostream>

const int N = 1e5 + 10;
int a[N];

int main() {
	int n;
	std::cin >> n;
	for (int i = 0; i < n; ++i) std::cin >> a[i];

	int l = 0, r = n - 1;
	int ans = (r - l) * std::min(a[l], a[r]);
	while (l < r) {
		if (a[l] < a[r]) ++l;
		else --r;
		ans = std::max(ans, (r - l) * std::min(a[l], a[r]));
	}
	std::cout << ans << std::endl;
}
