#include<iostream>

void PrintMultiplicationTable(int num) {
	for (int j = 1; j < num; j++) {
		std::cout << num << " * " << j << " = " << num * j << std::endl;
	}
}

int main(void) {
	int num = 0;
	
	std::cout << "원하는 구구단 숫자 입력: ";
	std::cin >> num;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "숫자만 입력하시오" << std::endl;
		return - 1;
	}

	PrintMultiplicationTable(num);
}