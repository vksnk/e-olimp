#include <iostream>
#include <string>
#include <cstdlib>
#include <cmath>

bool isPrime(int num) {
	//std::cout << num << "\n";
	if(num % 2 == 0) 
		return false;

	for(int i = 3; i <= static_cast<int>(sqrt(num)); i+=2) {
		if(num % i == 0)
			return false;
	}

	return true;
}

int main() {
	int numPas;
	std::string ticketNum;

	std::cin >> numPas >> ticketNum;

	int startFrom = atoi(ticketNum.c_str());
	int notMoreThan = pow(10, ticketNum.size());

	//std::cout << notMoreThan << " " << startFrom << "\n";

	bool found = false;
	int i;

	for(i = 1; i < numPas; i++) {
		int currentTicket = startFrom + i;
		if(currentTicket >= notMoreThan) 
			break;
		
		found = isPrime(currentTicket);

		if(found)
			break;
	}

	if(found) {
		std::cout << i - 1 << "\n";
	} else {
		std::cout << -1 << "\n";
	}
		
	return 0;
}