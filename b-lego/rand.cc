#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>

using ll = long long;

int random(int n) {
	return (ll)rand() * rand() % n;
}
int random(int l, int r) {
	return l + random(r - l + 1);
}

int a[10005];

int main() {
	srand(time(nullptr));

	for (int i = 6; i <= 10; ++i) {
		std::string file = std::to_string(i) + ".in";
		std::ofstream out(file);

		int n = random(1, 10), m = random(1, 10), k = random(1, 10);
		out << n << ' ' << m << ' ' << k << std::endl;

		for (int i = 0; i < n; ++i) {
			if (i) out << ' ';
			a[i] = random(30, 100);
			out << a[i];
		}
		out << std::endl;

		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (j) out << ' ';
				// out << random(1, a[i]);
				out << random(0, 10);
			}
			out << std::endl;
		}
	}
}
