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

	std::cout << "1. 2����ȯ   2. 10����ȯ   3. 16����ȯ" << std::endl;
	std::cin >> num;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "���ڸ� �Է��ض�" << std::endl;

		return -1;
	}


}