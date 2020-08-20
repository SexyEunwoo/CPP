#include<iostream>
#include<cmath>
#include<time.h>
#include<Windows.h>

bool inline CheckCinIsNum() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "정수만 입력하시오" << std::endl;

		return false;
	}

	return true;
}

int main(void) {
	srand(time(NULL)); // 난수의 시작값 설정

	int start = 0, end = 0;

	std::cout << "난수 시작값: ";
	std::cin >> start;
	if (!CheckCinIsNum())
		return -1;

	std::cout << "난수 종료값: ";
	std::cin >> end;
	if (!CheckCinIsNum())
		return -1;

	int random = rand() % (end - start + 1) + start;	// 난수 = rand() % ( 종료값 - 시작값 + 1 ) + 시작값
	std::cout << "생성된 난수값: " << random << std::endl;

	return 0;
}