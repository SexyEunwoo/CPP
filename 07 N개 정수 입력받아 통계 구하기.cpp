#include<iostream>
#include<cmath>
#include<vector>

std::vector<float> numbers;

bool inline CheckCinIsNum() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "������ �Է��Ͻÿ�" << std::endl;

		return false;
	}

	return true;
}

float GetAverage() {
	float sum = 0;

	for (std::vector<float>::iterator it = numbers.begin(); it != numbers.end(); it++)
		sum += *it;

	sum = sum / numbers.size();
	return sum;
}

float GetSD() { // Standard deviation ǥ������
	float temp = 0;

	for (std::vector<float>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		// ���� ������ ��� ���ϰ� ������ŭ ������ ��Ʈ
		temp += pow(*it - GetAverage(), 2);
	}

	temp = sqrt(temp / numbers.size());

	return temp;
}

float GetMaximum() {
	if (numbers.size() == 0)
		return -1;

	float max = numbers.at(0);

	for (std::vector<float>::iterator it = numbers.begin() + 1; it != numbers.end(); it++)
		max = *it > max ? *it : max;

	return max;
}

float GetMinimum() {
	if (numbers.size() == 0)
		return -1;

	float min = numbers.at(0);

	for (std::vector<float>::iterator it = numbers.begin() + 1; it != numbers.end(); it++)
		min = *it < min ? *it : min;

	return min;
}

float GetSum() {
	return 1;
}

int main(void) {
	int num = 0;

	std::cout << "�Է��ϰ� ���� ������ ���� �Է�: ";
	std::cin >> num;

	if (std::cin.fail()) {
		std::cin.clear(); // ���� �÷��� �ʱ�ȭ
		std::cin.ignore(INT_MAX, '\n'); // �Է¹��� �ʱ�ȭ
		std::cout << "���ڸ� �Է��ϼ���" << std::endl;

		return -1;
	}

	float temp = 0;
	for (int i = 0; i < num; i++) {
		std::cout << i + 1 << "�� ����: ";
		std::cin >> temp;

		while (!CheckCinIsNum())
			std::cout << i + 1 << "�� ����: ";

		numbers.push_back(temp);
	}

	std::cout << "Average: " << GetAverage() << std::endl;
	std::cout << "Maximum Number: " << GetMaximum() << std::endl;
	std::cout << "Minimum Number: " << GetMinimum() << std::endl;
	std::cout << "Standard Deviation: " << GetSD() << std::endl;

	return 0;
}