#include<iostream>

void Strset(char* str, char ch) {
	while (*str)
		*str++ = ch;
}

int main(void) {
	char str1[100];
	char ch;

	std::cout << "문자열 입력: ";
	std::cin >> str1;

	std::cout << "바꾸고자 하는 문자 입력: ";
	std::cin >> ch;

	Strset(str1, ch);

	std::cout << "바뀐 문자열: " << str1 << std::endl;

	return 0;
}