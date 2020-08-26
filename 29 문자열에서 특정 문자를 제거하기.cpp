#include<iostream>

void StrDel(char* str, char ch) {
	if (strlen(str) == 0)
		return;

	int cnt = 0;
	for (int i = 0; i < strlen(str); i++) {
		if (*(str + i) == ch) {
			for (int j = i; j < strlen(str); j++) // 비효휼적인 삭제구조
				*(str + j) = *(str + j + 1);
		}
	}
}

int main(void) {
	char str[100];
	std::cin.getline(str, sizeof(str));

	StrDel(str, 'x');
	std::cout << str << std::endl;
}