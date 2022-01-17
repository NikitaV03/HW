// examination.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>

int main(int argс, char *argv[])
{
	char *inputfilename = argv[1];
	char* outputfilename = argv[2];
	std::ifstream infile(inputfilename);
	if (infile.is_open()) {
		char* number1 = new char[1024];
		char* number2 = new char[1024];
		int pos = 0;
		for (int i = 0; i < 1024; ++i) {
			number1[i] = '=';
			number2[i] = '=';
		}
		while (!infile.eof()){
			infile.getline(number1, 1024);
			infile.getline(number2, 1024);
		}
		int countsymb1 = -1;
		for (int i = 0; (number1[i]!= '=') && (i<1024); ++i) {
			std::cout << (int)number1[i]-48 << " ";
			++countsymb1;
		}
		std::cout << std::endl;
		int countsymb2 = -1;
		for (int i = 0; (number2[i] != '=') && (i < 1024); ++i) {
			std::cout << (int)number2[i]-48 << " ";
			++countsymb2;
		}
		std::cout << std::endl;
		std::cout << countsymb1 << " " << countsymb2 << std::endl;
		std::ofstream outfile(outputfilename);
		if (outfile.is_open()) {
			bool p = 0;
			int passed = 0;
			int lenofnumber = (countsymb1 > countsymb2) ? countsymb1 + 1 : countsymb2 + 1;
			int* number = new int[lenofnumber];
			std::cout << " coutsym1:" << countsymb1 << std::endl;
			for (int i = countsymb1 - 1, j = countsymb2 - 1; (countsymb1 > countsymb2) ? j >= 0 : i >= 0; --i, --j) {
				int digit = (int)number1[i] - 48 + (int)number2[j] - 48 + p;
				int indfornum = (countsymb1 > countsymb2) ? i : j;
				if (digit < 10) {
					std::cout << digit << " ";
					number[indfornum+1] = digit;
					p = 0;
				}
				else {
					std::cout << digit % 10 << " ";
					number[indfornum+1] = digit % 10;
					p = 1;
				}
				passed++;
			}
			
			if (countsymb1 == countsymb2) {
				number[countsymb1 - passed] = p;
			}
			else if (countsymb1 > countsymb2) {
				std::cout << (int)number1[countsymb1 - passed-1] - 48 + p << " ";
				number[countsymb1 - passed] = (int)number1[countsymb1 - passed - 1] - 48 + p;
				passed++;
				for (int i = countsymb1 - passed-1; i >= 0; --i) {
					int digit = (int)number1[i] - 48;
					std::cout << digit << " ";
					number[i+1] = digit;
				}
			}
			else {
				std::cout << (int)number2[countsymb2 - passed-1] - 48 + p << " ";
				number[countsymb2 - passed] = (int)number2[countsymb2 - passed - 1] - 48 + p;
				passed++;
				for (int i = countsymb2 - passed-1; i >= 0; --i) {
					int digit = (int)number2[i] - 48;
					std::cout << digit << " ";
					number[i+1] = digit;
				}
			}
			for (int i = 0; i < lenofnumber; ++i) {
				outfile << number[i];
				std::cout << number[i] << " ";
			}
			delete[] number;
			outfile.close();
		}
		else {
			std::cout << "Something went wrong";
		}
		infile.close();
		delete[] number1;
		delete[] number2;
	}
	else{
		std::cout << "Something went wrong";
	}
}
//   9999 1 не работает :( :( :( :( :( :(
