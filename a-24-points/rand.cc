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
		int t = 1000;
		std::string file = std::to_string(i) + ".in";
		std::ofstream out(file);
		out << t << std::endl;

		while (t--) {
			out << random(1, 13);
			for (int i = 0; i < 3; ++i) out << ' ' << random(1, 13);
			out << std::endl;
		}
	}
}
