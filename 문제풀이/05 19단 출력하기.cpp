#include<iostream>

void PrintMultiplicationTable(int num) {
	for (int j = 1; j < num; j++) {
		std::cout << num << " * " << j << " = " << num * j << std::endl;
	}
}

int main(void) {
	int num = 0;
	
	std::cout << "���ϴ� ������ ���� �Է�: ";
	std::cin >> num;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "���ڸ� �Է��Ͻÿ�" << std::endl;
		return - 1;
	}

	PrintMultiplicationTable(num);
}