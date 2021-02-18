#include<iostream>
#include<string>

void GetDirectoryAndFileName(std::string str, std::string& directory, std::string& fileName) {
	int idx = 0;
	for (int i = 0; i < str.length(); i++) // 마지막 경로까지의 인덱스 추출
		if (str[i] == '\\')
			idx = i;

	directory = str.substr(0, idx); // 경로저장
	fileName = str.substr(idx + 1); // 파일이름 저장
}

int main(void) {
	std::string str("c:\\users\\dmsdn\\source\\repos\\c++practice\\c++practice\\c++practice.exe");
	std::string fileName;
	std::string directory;

	GetDirectoryAndFileName(str, directory, fileName);
	// std::getline(std::cin, str);  c:\\users\\dmsdn\\source\\repos\\c++practice\\c++practice\\c++practice.exe


}