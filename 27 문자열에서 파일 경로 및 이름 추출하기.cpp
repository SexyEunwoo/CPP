#include<iostream>
#include<string>

void GetDirectoryAndFileName(std::string str, std::string& directory, std::string& fileName) {
	int idx = 0;
	for (int i = 0; i < str.length(); i++) // ������ ��α����� �ε��� ����
		if (str[i] == '\\')
			idx = i;

	directory = str.substr(0, idx); // �������
	fileName = str.substr(idx + 1); // �����̸� ����
}

int main(void) {
	std::string str("c:\\users\\dmsdn\\source\\repos\\c++practice\\c++practice\\c++practice.exe");
	std::string fileName;
	std::string directory;

	GetDirectoryAndFileName(str, directory, fileName);
	// std::getline(std::cin, str);  c:\\users\\dmsdn\\source\\repos\\c++practice\\c++practice\\c++practice.exe


}