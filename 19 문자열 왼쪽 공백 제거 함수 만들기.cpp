#include<iostream>

void StrLTrim(char* str) {
	// �������� �����̽���, \t
	int count = 0;		// ���� ���� ����
	char* string1 = str;
	while (*string1 == ' ' || *string1 == '\t') {
		count++;
		string1++;
	}

	if (count != 0) { // ���ʿ� ������ �����Ѵٸ�
		int length = strlen(str) - count; // ������ ������ ���ڿ� ���� ��ŭ ������ �ű� ���� ����
		char* string2 = str + count; // �ű�� ������ ���ڸ� ����Ŵ
		for (int i = 0; i < length; i++) {
			*str++ = *string2++;
		}
		*str = '\0'; // �� �ű�� ���� �������� �ι��� �߰�
	}
}

int main(void) {
	char str1[100];


	std::cout << "���ڿ� �Է�: ";
	std::cin.getline(str1, sizeof(str1));
	StrLTrim(str1);

	std::cout << "���� ���� ���ŵ� ���ڿ�: " << str1 << std::endl;

	return 0;
}