#include<iostream>
#include<iomanip>

void EscapeWell(int height, int movement) {
	int count = 0, position = 0;

	do{
		position += movement;
		count++;

		if (position < (movement / 2)) // 0���� ~ �߰��κ��� �ö󰬴� 1���� ������
			position--;
		else											// �߰��κ� ~ �������� �ö󰬴� 2���� ������
			position -= 2;

		std::cout.setf(std::ios::right); // ��� ������ ����
		std::cout << "[" << std::setw(3) << count
					   << "]�����̰� �̵��� ���� " << std::setw(3) << position << std::endl;
	} while (position < height);

	std::cout << "�� " << count << " ȸ���� �칰�� Ż���Ͽ����ϴ�." << std::endl;
}

int main(void) {
	int height = 0, movement = 0; // ����, 1ȸ ������ ������ �Ÿ�

	std::cout << "�칰�� ���̿� 1ȸ �������� ���Ͻÿ�: ";
	std::cin >> height >> movement;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "������ �Է��Ͻÿ�" << std::endl;

		return -1;
	}

	EscapeWell(height, movement);
}