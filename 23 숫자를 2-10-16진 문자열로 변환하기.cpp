#include<iostream>

char* IntToBinaryString(int num) {

}

char* IntToDecialString(int num) {

}

char* IntToHexString(int num) {

}

int main(void) {
	int num;
	char str[100];

	std::cout << "1. 2진변환   2. 10진변환   3. 16진변환" << std::endl;
	std::cin >> num;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "숫자만 입력해라" << std::endl;

		return -1;
	}


}