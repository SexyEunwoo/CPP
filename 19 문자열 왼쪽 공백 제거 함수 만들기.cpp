#include<iostream>

void StrLTrim(char* str) {
	// 공백종류 스페이스바, \t
	int count = 0;		// 왼쪽 공백 갯수
	char* string1 = str;
	while (*string1 == ' ' || *string1 == '\t') {
		count++;
		string1++;
	}

	if (count != 0) { // 왼쪽에 공백이 존재한다면
		int length = strlen(str) - count; // 공백을 제외한 문자열 길이 만큼 옆으로 옮길 길이 저장
		char* string2 = str + count; // 옮기기 시작할 문자를 가리킴
		for (int i = 0; i < length; i++) {
			*str++ = *string2++;
		}
		*str = '\0'; // 다 옮기고 나서 마지막에 널문자 추가
	}
}

int main(void) {
	char str1[100];


	std::cout << "문자열 입력: ";
	std::cin.getline(str1, sizeof(str1));
	StrLTrim(str1);

	std::cout << "왼쪽 공백 제거된 문자열: " << str1 << std::endl;

	return 0;
}