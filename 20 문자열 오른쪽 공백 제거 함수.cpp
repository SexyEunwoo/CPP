#include<iostream>

void StrRTrim(char* str) {
	// �������� �����̽���, \t
	char* string1 = str + strlen(str) - 1; // ������ ���ڸ� ����Ŵ
	while (*string1 == ' ' || *string1 == '\t') {
		string1--;
	}
	
	*(++string1) = '\0'; // ������ ���� �� ù��° ���� NULL ����
}

int main(void) {
	char str1[100];


	std::cout << "���ڿ� �Է�: ";
	std::cin.getline(str1, sizeof(str1));
	StrRTrim(str1);

	std::cout << "������ ���� ���ŵ� ���ڿ�: " << str1 << std::endl;

	return 0;
}