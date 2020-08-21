#include<iostream>
#include<vector>

int SearchLengthOfLen(long long k, long long n, std::vector<int>& vec) {
	bool multiplied = false, divided = false;
	long long startLength = 300;
	long long minLength = 0, maxLength = 0;

	while (1) {
		int count = 0;
		
		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++) 
			count += *it / startLength;

		if (count > n) {
			if (divided) {
				minLength = startLength;
				startLength = (startLength + maxLength) / 2;
				multiplied = true;
			}
			else {
				minLength = startLength;
				startLength *= 2;
				maxLength = startLength;
				multiplied = true;
			}
		}
		else if (count < n) {
			if (multiplied) {
				maxLength = startLength;
				startLength = (startLength + minLength) / 2;
				divided = true;
				multiplied = false;
			}
			else {
				maxLength = startLength;
				startLength /= 2;
				divided = true;
				multiplied = false;
			}
		}
		else
			break;
	}

	for (int i = startLength; i < maxLength; i++) {
		int count = 0;

		for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); it++)
			count += *it / i;

		if (count < n)
			return i-1;
	}
}

int main(void) {
	std::vector<int> vec;
	long long k, n, temp;
	
	std::cin >> k >> n;

	for (int i = 0; i < k; i++) {
		std::cin >> temp;
		vec.push_back(temp);
	}
	std::cout << SearchLengthOfLen(k, n, vec) << std::endl;
}