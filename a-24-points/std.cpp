#include <iostream>
#include <vector>

bool dfs(std::vector<int> cards) {
	if (cards.size() == 1) {
		return cards.front() == 24;
	}

	for (int i = 0; i < cards.size(); ++i) {
		for (int j = 0; j < cards.size(); ++j) {
			if (i == j) continue;

			std::vector<int> next;
			for (int k = 0; k < cards.size(); ++k) {
				if (k == i || k == j) continue;
				next.push_back(cards[k]);
			}

			int x = cards[i], y = cards[j];

			next.push_back(x + y);
			if (dfs(next)) return true;
			next.pop_back();

			next.push_back(x - y);
			if (dfs(next)) return true;
			next.pop_back();

			next.push_back(x * y);
			if (dfs(next)) return true;
			next.pop_back();

			if (y == 0) continue;
			next.push_back(x / y);
			if (dfs(next)) return true;
			next.pop_back();
		}
	}

	return false;
}
			
int main() {
	int t;
	std::cin >> t;

	while (t--) {
		std::vector<int> cards(4);
		for (int i = 0; i < 4; ++i) {
			std::cin >> cards[i];
		}

		if (dfs(cards)) std::cout << "Yes" << std::endl;
		else std::cout << "No" << std::endl;
	}
}
