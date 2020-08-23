#include<iostream>

enum DECIMAL_ASCII {
	ZERO = 48, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NIGHT, U_TEN = 65, U_ELEVEN, U_TWELVE, U_THIRTEEN,
	U_FOURTEEN, U_FIFTEEN, L_TEN = 97, L_ELEVEN, L_TWELVE, L_THIRTEEN, L_FOURTEEN, L_FIFTEEN
};

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
	case L_TEN:
	case U_TEN:
		return 10;
	case L_ELEVEN:
	case U_ELEVEN:
		return 11;
	case L_TWELVE:
	case U_TWELVE:
		return 12;
	case L_FOURTEEN:
	case U_FOURTEEN:
		return 14;
	case L_FIFTEEN:
	case U_FIFTEEN:
		return 15;
	}
}

void IntToBinaryString(int num, char* str) {
	int binary_cnt = 0, temp = 0, sum = 0;

	while (temp < num)  // 2������ �� ���鼭 �ٲٰ� ���� ���ں��� ������ ���� ū 2���� ã��
		temp = pow(2, binary_cnt++);
	temp /= 2;

	while (sum != num) { // ���� ū 2�������� ���ذ���
		if (sum + temp > num) {
			*str++ = '0';
			temp /= 2;
		}
		else {
			sum += temp;
			*(str++) = '1';
			temp /= 2;
		}
	}

	while (temp != 0) { // 101101000 ó�� �� �ڿ� 0�� �ִ� ��츦 ���� ���� ó�� ����
		*str++ = '0';
		temp /= 2;
	}

	*str = '\0';
}

void IntToDecimalString(int num, char* str) {
	int numLength = 0, copy_num = num;
	
	while (copy_num != 0) {
		copy_num = num / static_cast<int>(pow(10, numLength));
		numLength++;
	}

	int cnt = 1;
	char* string = str + numLength - 1;
	*string = '\0'; string--;
	for(int i = 0; i < numLength - 1; i++) {
		*string = num % static_cast<int>(pow(10, cnt)) / pow(10, cnt-1) + 48;
		cnt++; string--;
	}
	
}

void IntToHexString(int num, char* str) {

}

int main(void) {
	int num, selec;
	char str[100];

	std::cout << "1. 2����ȯ   2. 10����ȯ   3. 16����ȯ" << std::endl;
	std::cin >> selec >> num;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "���ڸ� �Է��ض�" << std::endl;

		return -1;
	}

	IntToDecimalString(num, str);
	std::cout << str << std::endl;
}