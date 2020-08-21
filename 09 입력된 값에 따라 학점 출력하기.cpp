#include<iostream>

bool CheckIsItChar() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "���ڸ� �Է��ϼ���" << std::endl;

		return true;
	}
	return false;
}

bool CheckIsItNegative(int num) {
	if (num < 0) {
		std::cout << "������ ������ �� �� �����ϴ�" << std::endl;
		return true;
	}
	else
		return false;
}

int main(void) {
	int score = 0;

	std::cout << "���� �Է�: ";
	std::cin >> score;

	if (CheckIsItChar() || CheckIsItNegative(score)) return -1;

	switch (score / 10) {
	case 10:
	case 9 :
		std::cout << "A" << std::endl;
		break;
	
	case 8 :
		std::cout << "B" << std::endl;

	case 7 :
		std::cout << "C" << std::endl;

	case 6 :
		std::cout << "D" << std::endl;

	default :
		std::cout << "F" << std::endl;

	}
}