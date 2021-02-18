#include<iostream>
#include<cmath>
#include<vector>

std::vector<float> numbers;

bool inline CheckCinIsNum() {
	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "정수만 입력하시오" << std::endl;

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

float GetSD() { // Standard deviation 표준편차
	float temp = 0;

	for (std::vector<float>::iterator it = numbers.begin(); it != numbers.end(); it++) {
		// 절댓값 편차를 모두 더하고 개수만큼 나눈뒤 루트
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

	std::cout << "입력하고 싶은 정수의 개수 입력: ";
	std::cin >> num;

	if (std::cin.fail()) {
		std::cin.clear(); // 내부 플래그 초기화
		std::cin.ignore(INT_MAX, '\n'); // 입력버퍼 초기화
		std::cout << "숫자만 입력하세요" << std::endl;

		return -1;
	}

	float temp = 0;
	for (int i = 0; i < num; i++) {
		std::cout << i + 1 << "번 숫자: ";
		std::cin >> temp;

		while (!CheckCinIsNum())
			std::cout << i + 1 << "번 숫자: ";

		numbers.push_back(temp);
	}

	std::cout << "Average: " << GetAverage() << std::endl;
	std::cout << "Maximum Number: " << GetMaximum() << std::endl;
	std::cout << "Minimum Number: " << GetMinimum() << std::endl;
	std::cout << "Standard Deviation: " << GetSD() << std::endl;

	return 0;
}