#include<iostream>
#include<cmath>

enum DECIMAL_ASCII { ZERO = 48, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NIGHT};

bool IsitNum(char* str) { // 숫자만 있는지 문자가 섞여있는지 확인
	if (*str == '-' || *str == '+')
		str++;

	while (*str) {
		if (*str < 48 || *str > 57) // 숫자가 아닐 경우
			return false;
		str++;
	}

	return true;
}

bool IsitFloat(char* str) {
	if (*str == '-' || *str == '+')
		str++;

	bool cnt = false;
	while (*str) {
		if (*str == '.') {
			if (cnt == true)
				return false;
			else
				cnt = true;

			str++;
		}
		if (*str < 48 || *str > 57) // 숫자가 아닐 경우 or 소수점이 여러개 있을 경우
			return false;
		str++;
	}
}

int CharToInt(char ch) {
	switch (ch) {
	case ZERO:
		return 0;
	case ONE:
		return 1;
	case TWO:
		return 2;
	case THREE:
		return 3;
	case FOUR:
		return 4;
	case FIVE:
		return 5;
	case SIX:
		return 6;
	case SEVEN:
		return 7;
	case EIGHT:
		return 8;
	case NIGHT:
		return 9;
	}
}

int Atoi(char* str) {
	if (!IsitNum(str)) { // 숫자으로만 이루어져 있을 경우(맨 앞 부호는 상관X)
		std::cout << "문자열중 숫자가 아닌 문자가 섞여있습니다." << std::endl;
		return -1;
	}

	char* string = str;
	long long sum = 0;

	string += strlen(str) - 1; // 마지막 문자를 가리킨다
	int cnt = 0;
	
	while (str != string) { // string변수가 첫 번째 문자를 가리킬 때 까지 반복
		sum += CharToInt(*string) * pow(10, cnt);
		string--; cnt++;
	}

	switch (*string) { // 첫 번째 문자가 + 또는 -일 경우 따로 처리를 위한 switch문
	case '+':
		break;
	case '-':
		sum = -sum;
		break;
	default:
		sum += CharToInt(*string) * pow(10, cnt);
	}

	if (sum > static_cast<long long>(INT_MAX) || sum < static_cast<long long>(-INT_MAX)) // 만약 변환된 숫자가 INT형 변수보다 클 경우
	{
		std::cout << "입력하신 숫자문자열이 너무 크거나 작습니다" << std::endl;
		return -1;
	}

	return static_cast<int>(sum);
}

double Atof(char* str) {
	if (!IsitFloat(str)) { // 숫자으로만 이루어져 있을 경우(맨 앞 부호와 소수점1개는 상관X)
		std::cout << "문자열중 숫자가 아닌 문자가 섞여있습니다." << std::endl;
		return -1;
	}

	int cnt = 0, dotIdx = 0;
	double sum = 0;
	char* string = str;

	while (*string) { // .의 Idx값 찾기
		if (*string == '.')
			break;
		string++;
	}

	if (string == str + strlen(str)) { // .이 없는 실수라면
		string--;

		while (string != str) {
			sum += CharToInt(*string) * pow(10, cnt);
			cnt++; string--;
		}
		sum += CharToInt(*string) * pow(10, cnt);
	}
	else { // .이 있는 실수라면
		char* num = string;
		char* point = string;

		// 소수점 이상의 수 숫자로 변환
		num--;
		while (num != str) {
			sum += CharToInt(*num) * pow(10, cnt);
			cnt++;
			num--;
		}
		sum += CharToInt(*num) * pow(10, cnt);

		// 소수점 이하의 수  숫자로 변환
		point++; cnt = -1;
		while (*point) {
			sum += CharToInt(*point) * pow(10, cnt);
			cnt--;
			point++;
		}
	}

	return sum;
}

int main(void) {
	char str[100];
	std::cout << "소수점 숫자문자열 입력: ";
	std::cin >> str;

	double num = Atof(str);
	
	std::cout.precision(10);
	std::cout << "변환된 숫자: " << num << std::endl;

}