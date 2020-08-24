#include<iostream>

void StrReplace(char* str, char* dst, char* src) {
	/*
		ex) "dmsdn dla 123", "n d", "nd"
	*/
	char* string = str;
	int length = strlen(dst), idx = 0;

	for (int i = 0; i < strlen(str) - length + 1; i++) { // 모든 dst문자열을 src로 바꿈
		int cnt = 0;
		char* searchStr = dst;

		for(int j = 0; j < length; j++) { // dst와 동일한 문자열을 발견했을 경우 idx가 그 인덱스 위치를 나타냄
			if (*(string+cnt) == *searchStr) {
				cnt++;
				searchStr++;
			}
			else {
				string++;
				break;
			}
		}

		if (cnt == length) { // cnt는 문자열의 개수를 세서 동일한 문자열을 가지고 있는지 확인
			for (int h = 0; h < strlen(src); h++) // 문자열 변환
				*(str + idx + h) = *(src + h);
			for (int z = idx + strlen(src); z < strlen(str); z++) { // 바뀐 문자열이 이전 문자열보다 짧다면 앞으로 땡김
				*(str + z) = *(str + z + strlen(dst) - strlen(src));
			}
		}
		idx++;
	}
}

int main(void) {
	char str1[100];
	char str2[100];
	char str3[100];

	std::cout << "문자열 입력: ";
	std::cin >> str1;

	std::cout << "문자열에서 찾을 문자열, 바꿀 문자열 입력: ";
	std::cin >> str2 >> str3;

	StrReplace(str1, str2, str3);

	std::cout << str1 << std::endl;
}