#include<iostream>

char* Strcpy(char* dst, char* src) {
	char* pDst = dst;

	while (*src) {
		*dst++ = *src++;
	}
	*dst = '\0';

	return pDst;
}

int main(void) {
	char* temp1 = new char[5];
	char* temp2 = new char[10];
	std::cin >> temp1 >> temp2;

	char* c = Strcpy(temp1, temp2);

	std::cout << c << std::endl;
}