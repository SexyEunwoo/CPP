#include<iostream>

void Strupr(char* str) {
	while(*str) {
		if (*str >= 97 && *str <= 122) // �ҹ��ڶ��
			*str++ -= 32;
		else // �ҹ��ڰ� �ƴ� ���
			*str++;
	}
}

int main(void) {
	char str[100];

	std::cout << "�빮�ڷ� �ٲ� ���ڿ� �Է�: ";
	std::cin >> str;

	Strupr(str);

	std::cout << "�빮�ڷ� �ٲ� ���ڿ�: " << str << std::endl;
	
	return 0;
}