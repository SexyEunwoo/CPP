#include<iostream>
#include<Windows.h>

void PrintTriangle(int num) {
	for (int i = 0; i < num; i++) {
		for (int j = num-i; j > 0; j--) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

int main(void) {
	int num = 0;

	std::cout << "���ﰢ�� ����� ����� ���ϴ� ���� �Է�: ";
	std::cin >> num;

	if (std::cin.fail()) { // fail() -> ���ڸ� �Է¹޾ƾ� �ϴ� ���� ���ڸ� �Է¹����� failbit�� true�� �Ǵµ� �� ���� ��ȯ
		std::cout << "���ڸ� �Է��ϼ���" << std::endl;
		std::cin.clear(); // ���� �÷��� �ʱ�ȭ
		std::cin.ignore(INT_MAX, '\n'); // �Է¹��� �ʱ�ȭ 1�� �Ķ���� : ���� ���� �ִ����, 2�� : ���������� �о���� ����(���� NULL)
		return -1;
	}

	PrintTriangle(num);

	return 0;
}

