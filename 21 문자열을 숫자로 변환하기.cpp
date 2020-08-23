#include<iostream>
#include<cmath>

enum DECIMAL_ASCII { ZERO = 48, ONE, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NIGHT};

bool IsitNum(char* str) { // ���ڸ� �ִ��� ���ڰ� �����ִ��� Ȯ��
	if (*str == '-' || *str == '+')
		str++;

	while (*str) {
		if (*str < 48 || *str > 57) // ���ڰ� �ƴ� ���
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
		if (*str < 48 || *str > 57) // ���ڰ� �ƴ� ��� or �Ҽ����� ������ ���� ���
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
	if (!IsitNum(str)) { // �������θ� �̷���� ���� ���(�� �� ��ȣ�� ���X)
		std::cout << "���ڿ��� ���ڰ� �ƴ� ���ڰ� �����ֽ��ϴ�." << std::endl;
		return -1;
	}

	char* string = str;
	long long sum = 0;

	string += strlen(str) - 1; // ������ ���ڸ� ����Ų��
	int cnt = 0;
	
	while (str != string) { // string������ ù ��° ���ڸ� ����ų �� ���� �ݺ�
		sum += CharToInt(*string) * pow(10, cnt);
		string--; cnt++;
	}

	switch (*string) { // ù ��° ���ڰ� + �Ǵ� -�� ��� ���� ó���� ���� switch��
	case '+':
		break;
	case '-':
		sum = -sum;
		break;
	default:
		sum += CharToInt(*string) * pow(10, cnt);
	}

	if (sum > static_cast<long long>(INT_MAX) || sum < static_cast<long long>(-INT_MAX)) // ���� ��ȯ�� ���ڰ� INT�� �������� Ŭ ���
	{
		std::cout << "�Է��Ͻ� ���ڹ��ڿ��� �ʹ� ũ�ų� �۽��ϴ�" << std::endl;
		return -1;
	}

	return static_cast<int>(sum);
}

double Atof(char* str) {
	if (!IsitFloat(str)) { // �������θ� �̷���� ���� ���(�� �� ��ȣ�� �Ҽ���1���� ���X)
		std::cout << "���ڿ��� ���ڰ� �ƴ� ���ڰ� �����ֽ��ϴ�." << std::endl;
		return -1;
	}

	int cnt = 0, dotIdx = 0;
	double sum = 0;
	char* string = str;

	while (*string) { // .�� Idx�� ã��
		if (*string == '.')
			break;
		string++;
	}

	if (string == str + strlen(str)) { // .�� ���� �Ǽ����
		string--;

		while (string != str) {
			sum += CharToInt(*string) * pow(10, cnt);
			cnt++; string--;
		}
		sum += CharToInt(*string) * pow(10, cnt);
	}
	else { // .�� �ִ� �Ǽ����
		char* num = string;
		char* point = string;

		// �Ҽ��� �̻��� �� ���ڷ� ��ȯ
		num--;
		while (num != str) {
			sum += CharToInt(*num) * pow(10, cnt);
			cnt++;
			num--;
		}
		sum += CharToInt(*num) * pow(10, cnt);

		// �Ҽ��� ������ ��  ���ڷ� ��ȯ
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
	std::cout << "�Ҽ��� ���ڹ��ڿ� �Է�: ";
	std::cin >> str;

	double num = Atof(str);
	
	std::cout.precision(10);
	std::cout << "��ȯ�� ����: " << num << std::endl;

}