#include<iostream>

void Strupr(char* str) {
	while (*str) {
		if (*str >= 65 && *str <= 90) // �빮�ڶ��
			*str++ += 32;
		else // �빮�ڰ� �ƴ� ���
			*str++;
	}
}

int main(void) {
	char str[100];

	std::cout << "�ҹ��ڷ� �ٲ� ���ڿ� �Է�: ";
	std::cin >> str;

	Strupr(str);

	std::cout << "�ҹ��ڷ� �ٲ� ���ڿ�: " << str << std::endl;

	return 0;
}