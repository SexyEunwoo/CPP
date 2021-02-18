#include<iostream>
#include<Windows.h>
#include<memory>

char* Strcat(char* dst, const char* src) { // 기존 문자열ㅇ ㅔ추가
	char* pDst = dst;

	dst += strlen(dst);

	while (*src)
		*dst++ = *src++;
	*dst = '\0';

	return pDst;
}

char* Strcat(char* str1, char* str2) { // 새로운 문자열 생성
	int length = strlen(str1) + strlen(str2) + 1; // 마지막 NULL문자
	char* ret = new char[length];

	while (*str1)
		*ret++ = *str1++;
	while (*str2)
		*ret++ = *str2++;
	*ret = '\0';
	ret -= length-1;

	return ret;
}

int main(void) {
	char str1[10] = "asdasd";
	char str2[10] = "dsadsa";

	std::cout << Strcat(str1, str2) << std::endl;
	std::cout << Strcat(str1, "489") << std::endl;
}