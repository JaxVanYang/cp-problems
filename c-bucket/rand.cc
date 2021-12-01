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

int main() {
	srand(time(nullptr));

	for (int i = 1; i <= 10; ++i) {
		std::string file = std::to_string(i) + ".in";
		std::ofstream out(file);

		int n = 1e5;
		out << n << std::endl;

		for (int i = 0; i < n; ++i) {
			if (i) out << ' ';
			out << random(1, 10000);
		}
		out << std::endl;
	}
}
