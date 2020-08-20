#include<iostream>
#include<cmath>
#include<time.h>
#include<Windows.h>

bool inline CheckCinIsNum() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "������ �Է��Ͻÿ�" << std::endl;

		return false;
	}

	return true;
}

int main(void) {
	srand(time(NULL)); // ������ ���۰� ����

	int start = 0, end = 0;

	std::cout << "���� ���۰�: ";
	std::cin >> start;
	if (!CheckCinIsNum())
		return -1;

	std::cout << "���� ���ᰪ: ";
	std::cin >> end;
	if (!CheckCinIsNum())
		return -1;

	int random = rand() % (end - start + 1) + start;	// ���� = rand() % ( ���ᰪ - ���۰� + 1 ) + ���۰�
	std::cout << "������ ������: " << random << std::endl;

	return 0;
}