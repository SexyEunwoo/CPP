#include<iostream>

void Strset(char* str, char ch) {
	while (*str)
		*str++ = ch;
}

int main(void) {
	char str1[100];
	char ch;

	std::cout << "���ڿ� �Է�: ";
	std::cin >> str1;

	std::cout << "�ٲٰ��� �ϴ� ���� �Է�: ";
	std::cin >> ch;

	Strset(str1, ch);

	std::cout << "�ٲ� ���ڿ�: " << str1 << std::endl;

	return 0;
}