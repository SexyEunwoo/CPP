#include<iostream>

enum DECIMAL_ASCII { ZERO = 48, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NIGHT, U_TEN = 65, U_ELEVEN, U_TWELVE, U_THIRTEEN,
										U_FOURTEEN, U_FIFTEEN, L_TEN = 97, L_ELEVEN, L_TWELVE, L_THIRTEEN, L_FOURTEEN, L_FIFTEEN };

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

int BinaryToInt(char* str) {
	char* string = str;
	while (*string) { // ���̳ʸ� ���ڿ��� �ƴ� ��� return -1
		if (*string != '1' && *string != '0') {
			std::cout << "2�� ���ڿ��� �ƴմϴ�." << std::endl;
			return -1;
		}
		string++;
	}
	string--;

	int sum = 0, cnt = 0;
	while (string != str) { // ������ ���ں��� ù ��° ���ڱ���
		sum += CharToInt(*string) * pow(2, cnt);
		string--; cnt++;
	}
	sum += CharToInt(*string) * pow(2, cnt);

	return sum;
}

int HexToInt(char* str) {
	char* string = str;
	while (*string) { // 16�� ���ڿ��� �ƴ� ��� return -1
		if ((*string < 48) || (*string > 57 && *string < 65) || (*string > 90 && *string < 97) || (*string > 122)) {
			std::cout << "16�� ���ڿ��� �ƴմϴ�." << std::endl;
			return -1;
		}
		string++;
	}
	string--;

	int sum = 0, cnt = 0;
	while (string != str) {
		sum += CharToInt(*string) * pow(16, cnt);
		string--; cnt++;
	}
	sum += CharToInt(*string) * pow(16, cnt);

	return sum;
}

int main(void) {
	char str[100];
	int selec;
	std::cout << "1. 2�� ���ڿ�   2. 16�� ���ڿ�"<<std::endl;
	std::cin >> selec;
	
	if (std::cin.fail()) {
		std::cin.clear(); // ���� �÷��� �ʱ�ȭ
		std::cin.ignore(INT_MAX, '\n'); // �Է¹��� �ʱ�ȭ
		std::cout << "���ڸ� �Է��ض�.." << std::endl;

		return -1;
	}

	int result = 0;
	switch (selec) {
	case 1:
		std::cin >> str;
		result = BinaryToInt(str);
		if(result != -1)
			std::cout << "��ȯ�� 2�� ���ڿ�: " << BinaryToInt(str) << std::endl;
		break;
	case 2:
		std::cin >> str;
		result = HexToInt(str);
		if (result != -1)
		std::cout << "��ȯ�� 16�� ���ڿ�: " << HexToInt(str) << std::endl;
		break;
	default:
		std::cout << "1,2�� ����ϱ� �� �μ��� �����־�?!" << std::endl;
		break;
	}

	return 0;
}