#include<iostream>

int Strchar(char* str, char ch) { // 인덱스 값 반환
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

	std::cout << "문자열 입력: ";
	std::cin >> str;

	char ch;
	std::cout << "찾고자 하는 문자 입력: ";
	std::cin >> ch;

	std::cout << "찾고자 하는 문자의 인덱스: " << Strchar(str, ch) << std::endl;
}