#include <iostream>
#include <algorithm>
#include <deque>

int main() {
	int n;
	std::cin >> n;

	if(n < 2) {
		std::cout << n << "\n";
		return 0;
	}

	std::deque<int> binRepres;
	while(n > 0) {
		binRepres.push_front(n % 2);
		n /= 2;
	}
/*
	for(unsigned i = 0; i < binRepres.size(); i++) 
		std::cout << binRepres[i] << " ";
	
	std::cout<< "\n";
*/
	int maxNum = 0;

	for(unsigned i = 0; i < binRepres.size(); i++) {
		int val = 0;
		std::rotate(binRepres.begin(), binRepres.begin() + 1, binRepres.end());
/*
		for(unsigned i = 0; i < binRepres.size(); i++) 
			std::cout << binRepres[i] << " ";
	
		std::cout<< "\n";
*/
		for(unsigned j = 0; j < binRepres.size(); j++) {
			val = val * 2 + binRepres[j];
		}

		maxNum = std::max(maxNum, val);

	}

	std::cout << maxNum << "\n";
	return 0;
}