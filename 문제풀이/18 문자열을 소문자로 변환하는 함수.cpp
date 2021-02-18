#include<iostream>

void Strupr(char* str) {
	while (*str) {
		if (*str >= 65 && *str <= 90) // 대문자라면
			*str++ += 32;
		else // 대문자가 아닌 경우
			*str++;
	}
}

int main(void) {
	char str[100];

	std::cout << "소문자로 바꿀 문자열 입력: ";
	std::cin >> str;

	Strupr(str);

	std::cout << "소문자로 바뀐 문자열: " << str << std::endl;

	return 0;
}