#include<iostream>

bool IsDigit(char n) {
	if (n > 47 && n < 58)
		return true;
	else
		return false;
}

void RemoveChar(char* dst, char* src) {
	while (*src) {
		if (IsDigit(*src)) {
			*dst = *src;
			dst++; src++;
		}
		else
			src++;
	}
	*dst = '\0';
}

int main(void) {
	char dst[100];
	char src[100];

	std::cin >> src;

	RemoveChar(dst, src);

	std::cout << dst << std::endl;
}