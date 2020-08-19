#include<iostream>
#include<Windows.h>

void PrintRhombus(int num) { 
	// 도스창 기본 너비 = 120
	char command[256] = { '\n', };
	sprintf_s(command, "mode con lines=%d cols=%d", num/2, num);
	system(command);

	for (int i = 0  ; i < (num / 2 + 1); i++) { // 줄바꿈 횟수

		for (int j = (num / 2); j > i; j--) // 스페이스바
			std::cout << " ";

		for (int h = 0; h < (i*2)+1; h++) // 별
			std::cout << "*";

		std::cout<<std::endl;
	}

	for (int i = 0; i < (num / 2); i++) { // 줄바꿈 횟수

		for (int j = 0; j < i+1; j ++) // 스페이스바
			std::cout << " ";

		for (int h = 0; h < (num-2) - i * 2; h++) // 별
			std::cout << "*";

		std::cout << std::endl;
	}
}

int main(void) {
	int num = 0;

	std::cout << "출력할 마름모꼴 숫자 입력: ";
	std::cin >> num;

	if (std::cin.fail()) { // fail() -> 숫자를 입력받아야 하는 곳에 문자를 입력받으면 failbit이 true가 되는데 이 값을 반환
		std::cout << "숫자만 입력하세요" << std::endl;
		std::cin.clear(); // 내부 플래그 초기화
		std::cin.ignore(INT_MAX, '\n'); // 입력버퍼 초기화 1번 파라미터 : 무시 문자 최대길이, 2번 : 마지막으로 읽어들일 문자(보통 NULL)
		return -1;
	}

	if (num % 2 != 1) {
		std::cout << "홀수만 입력하시오" << std::endl;
		return -1;
	}
	
	PrintRhombus(num);
	return 0;
}