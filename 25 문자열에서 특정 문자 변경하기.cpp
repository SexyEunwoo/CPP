#include<iostream>

void StrReplace(char* str, char* dst, char* src) {
	/*
		ex) "dmsdn dla 123", "n d", "nd"
	*/
	char* string = str;
	int length = strlen(dst), idx = 0;

	for (int i = 0; i < strlen(str) - length + 1; i++) { // ��� dst���ڿ��� src�� �ٲ�
		int cnt = 0;
		char* searchStr = dst;

		for(int j = 0; j < length; j++) { // dst�� ������ ���ڿ��� �߰����� ��� idx�� �� �ε��� ��ġ�� ��Ÿ��
			if (*(string+cnt) == *searchStr) {
				cnt++;
				searchStr++;
			}
			else {
				string++;
				break;
			}
		}

		if (cnt == length) { // cnt�� ���ڿ��� ������ ���� ������ ���ڿ��� ������ �ִ��� Ȯ��
			for (int h = 0; h < strlen(src); h++) // ���ڿ� ��ȯ
				*(str + idx + h) = *(src + h);
			for (int z = idx + strlen(src); z < strlen(str); z++) { // �ٲ� ���ڿ��� ���� ���ڿ����� ª�ٸ� ������ ����
				*(str + z) = *(str + z + strlen(dst) - strlen(src));
			}
		}
		idx++;
	}
}

int main(void) {
	char str1[100];
	char str2[100];
	char str3[100];

	std::cout << "���ڿ� �Է�: ";
	std::cin >> str1;

	std::cout << "���ڿ����� ã�� ���ڿ�, �ٲ� ���ڿ� �Է�: ";
	std::cin >> str2 >> str3;

	StrReplace(str1, str2, str3);

	std::cout << str1 << std::endl;
}