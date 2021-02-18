#include<iostream>
#include<Windows.h>

int Get_num_multiple(int num, int end) {
	int ret = 0, temp = 0;

	do {
		ret += temp;
		temp += num;
	} while (temp <= end);

	return ret;
}

int main(void) {
	int n = 0, result = 0;

	while (true) {
		std::cout << "N입력: "; // I Changed
		std::cin >> n;

		if (!std::cin) {
			std::cin.clear();
			std::cin.ignore(INT_MAX, '\n');
			system("cls");
			continue;
		}
		else
			break;
	} // Get Number
	
	result = Get_num_multiple(n, 100);// Call Get_num_multiple Func
	
	std::cout << "result: " << result << std::endl;

	return 0;
}