#include<iostream>

void Strrev(char* str) {
	int count = strlen(str) / 2;
	char* start = str;
	char* end = str + strlen(str) - 1;
	for (int i = 0; i < count; i++) {
		char temp = *str;
		*str = *end;
		*end = temp;
		str++; end--;
	}
}

int main(void) {
	char* str = new char[100];

	std::cout << "뒤집고 싶은 문자열 입력: ";
	std::cin >> str;

	Strrev(str);

	std::cout <<"뒤집은 문자열: " << str << std::endl;

	return 0;
}