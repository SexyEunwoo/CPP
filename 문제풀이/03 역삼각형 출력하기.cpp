#include<iostream>
#include<Windows.h>

void PrintTriangle(int num) {
	for (int i = 0; i < num; i++) {
		for (int j = num-i; j > 0; j--) {
			std::cout << "*";
		}
		std::cout << std::endl;
	}
}

int main(void) {
	int num = 0;

	std::cout << "역삼각형 별모양 출력을 원하는 개수 입력: ";
	std::cin >> num;

	if (std::cin.fail()) { // fail() -> 숫자를 입력받아야 하는 곳에 문자를 입력받으면 failbit이 true가 되는데 이 값을 반환
		std::cout << "숫자만 입력하세요" << std::endl;
		std::cin.clear(); // 내부 플래그 초기화
		std::cin.ignore(INT_MAX, '\n'); // 입력버퍼 초기화 1번 파라미터 : 무시 문자 최대길이, 2번 : 마지막으로 읽어들일 문자(보통 NULL)
		return -1;
	}

	PrintTriangle(num);

	return 0;
}

