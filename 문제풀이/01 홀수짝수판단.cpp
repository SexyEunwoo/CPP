#include<iostream>
#include<cmath>

bool IsitOdd(int num) {
	if (num < 0) num = abs(num);
	return (num % 2 == 1) ? true : false;
}

int main(void) {
	int num = 0;

	std::cout << "홀수/짝수 검사할 숫자 입력:";
	std::cin >> num;

	if (!std::cin) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return -1;
	}

	std::cout << IsitOdd(num) << std::endl;
}