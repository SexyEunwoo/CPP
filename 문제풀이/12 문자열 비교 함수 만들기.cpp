#include<iostream>

template <class T> // template를 활용하여 const char* 및 char* 모두 가능
bool Strcmp(T* str1, T* str2) {
	while (*str1) {
		if (*str1++ != *str2++)
			return false;
	}

	return true;
}

int main(void) {
	char* str1 = new char[10];
	char* str2 = new char[10];

	std::cin >> str1 >> str2;

	std::cout << Strcmp(str1, str2) << std::endl;
	std::cout << Strcmp("assd", "asd") << std::endl;

	return 0;
}