#include<iostream>

bool CheckIsItChar() {
	if (std::cin.fail()) {
		std::cout << "���ڸ� �Է��ϼ̽��ϴ�" << std::endl << std::endl;
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		return true;
	}

	return false;
}

int main(void) {
	int array[10] = { 0, };
	int sum = 0;

	for (int i = 0; i < 10; i++) {
		std::cout << i + 1 << "��° �� �Է�: ";
		std::cin >> array[i];

		while (CheckIsItChar()) {
			std::cout << i + 1 << "��° �� �Է�: ";
			std::cin >> array[i];
		}
	}

	for (int j = 0; j < 10; j++)
		sum += array[j];

	std::cout << "�� ��: " << sum << std::endl;
}