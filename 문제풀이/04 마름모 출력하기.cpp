#include<iostream>
#include<Windows.h>

void PrintRhombus(int num) { 
	// ����â �⺻ �ʺ� = 120
	char command[256] = { '\n', };
	sprintf_s(command, "mode con lines=%d cols=%d", num/2, num);
	system(command);

	for (int i = 0  ; i < (num / 2 + 1); i++) { // �ٹٲ� Ƚ��

		for (int j = (num / 2); j > i; j--) // �����̽���
			std::cout << " ";

		for (int h = 0; h < (i*2)+1; h++) // ��
			std::cout << "*";

		std::cout<<std::endl;
	}

	for (int i = 0; i < (num / 2); i++) { // �ٹٲ� Ƚ��

		for (int j = 0; j < i+1; j ++) // �����̽���
			std::cout << " ";

		for (int h = 0; h < (num-2) - i * 2; h++) // ��
			std::cout << "*";

		std::cout << std::endl;
	}
}

int main(void) {
	int num = 0;

	std::cout << "����� ������� ���� �Է�: ";
	std::cin >> num;

	if (std::cin.fail()) { // fail() -> ���ڸ� �Է¹޾ƾ� �ϴ� ���� ���ڸ� �Է¹����� failbit�� true�� �Ǵµ� �� ���� ��ȯ
		std::cout << "���ڸ� �Է��ϼ���" << std::endl;
		std::cin.clear(); // ���� �÷��� �ʱ�ȭ
		std::cin.ignore(INT_MAX, '\n'); // �Է¹��� �ʱ�ȭ 1�� �Ķ���� : ���� ���� �ִ����, 2�� : ���������� �о���� ����(���� NULL)
		return -1;
	}

	if (num % 2 != 1) {
		std::cout << "Ȧ���� �Է��Ͻÿ�" << std::endl;
		return -1;
	}
	
	PrintRhombus(num);
	return 0;
}