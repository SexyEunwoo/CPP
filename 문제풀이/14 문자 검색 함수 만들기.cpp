#include<iostream>

int Strchar(char* str, char ch) { // �ε��� �� ��ȯ
	int index = 0;
	while (*str) {
		if (*str++ == ch)
			return index;
		index++;
	}

	return -1;
}

int main(void) {
	char str[100];

	std::cout << "���ڿ� �Է�: ";
	std::cin >> str;

	char ch;
	std::cout << "ã���� �ϴ� ���� �Է�: ";
	std::cin >> ch;

	std::cout << "ã���� �ϴ� ������ �ε���: " << Strchar(str, ch) << std::endl;
}