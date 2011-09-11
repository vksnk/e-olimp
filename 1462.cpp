#include <iostream>
#include <vector>
#include <algorithm>

int main() {
	std::vector< std::vector<int> > numbers(10, std::vector<int>());
	int n;

	std::cin >> n;

	for(int i = 0; i < n; i++) {
		int val;
		std::cin >> val;

		numbers[val % 10].push_back(val);
	}

	for(int i = 0; i < 10; i++)
		std::sort(numbers[i].begin(), numbers[i].end());
	
	std::vector<int> numbersSorted;

	for(int i = 0; i < 10; i++) {
		for(unsigned int j = 0; j < numbers[i].size(); j++)
			numbersSorted.push_back(numbers[i][j]);
	}

	std::cout << numbersSorted[0];

	for(int i = 1; i < numbersSorted.size(); i++)
		std::cout << " " << numbersSorted[i];

	std::cout << "\n";
	return 0;
}