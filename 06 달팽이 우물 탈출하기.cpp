#include<iostream>
#include<iomanip>

void EscapeWell(int height, int movement) {
	int count = 0, position = 0;

	do{
		position += movement;
		count++;

		if (position < (movement / 2)) // 0미터 ~ 중간부분은 올라갔다 1미터 떨어짐
			position--;
		else											// 중간부분 ~ 끝까지는 올라갔다 2미터 떨어짐
			position -= 2;

		std::cout.setf(std::ios::right); // 출력 오른쪽 정렬
		std::cout << "[" << std::setw(3) << count
					   << "]달팽이가 이동한 높이 " << std::setw(3) << position << std::endl;
	} while (position < height);

	std::cout << "총 " << count << " 회만에 우물을 탈출하였습니다." << std::endl;
}

int main(void) {
	int height = 0, movement = 0; // 높이, 1회 달팽이 움직임 거리

	std::cout << "우물의 높이와 1회 움직임을 정하시오: ";
	std::cin >> height >> movement;

	if (std::cin.fail()) {
		std::cin.clear();
		std::cin.ignore(INT_MAX, '\n');
		std::cout << "정수만 입력하시오" << std::endl;

		return -1;
	}

	EscapeWell(height, movement);
}