#include<iostream>

void StrRTrim(char* str) {
	// 공백종류 스페이스바, \t
	char* string1 = str + strlen(str) - 1; // 마지막 문자를 가리킴
	while (*string1 == ' ' || *string1 == '\t') {
		string1--;
	}
	
	*(++string1) = '\0'; // 오른쪽 공백 중 첫번째 문자 NULL 설정
}

int main(void) {
	char str1[100];


	std::cout << "문자열 입력: ";
	std::cin.getline(str1, sizeof(str1));
	StrRTrim(str1);

	std::cout << "오른쪽 공백 제거된 문자열: " << str1 << std::endl;

	return 0;
}