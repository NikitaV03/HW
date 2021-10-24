// 25.10.21.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>

void sixteen();
void time();

int main()
{
	unsigned char exit;
	//unsigned char n1=1;
	//unsigned short n2=1;
	//unsigned int n3=1;
	//unsigned long long int n4=1;
	//double perem=0,sum=0,sumka=0;
	//std::cout << sizeof(n1) << sizeof(n2) << sizeof(n3) << sizeof(n4) <<  std::endl;
	//while (sum < 4){
	//	sumka = sum;
	//	perem = 1 / double(n1 * n1);
	//	sum += perem;
	//	std::cout << sum << " " << " perem: " << perem << std::endl;
	//	/*if (sumka = sum) {
	//		std::cout << "S_n+1 == s_n!!!   " << n4;
	//		break;
	//	}*/
	//	n1 += 1;
	//}
	//std::cout << n4-1 << " sum: " << sumka;

	time();

	std::cin >> exit;
	return 0;
}

void sixteen() {
	int n, ost, i = 1;
	const char* M[] = { "0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F" };
	std::string str = "";
	std::cout << " Input number: ";
	std::cin >> n;
	while (n != 0) {
		i += 1;
		ost = n % 16;
		n /= 16;
		str = str.append(M[ost]);
	}
	reverse(str.begin(), str.end());
	std::cout << str;
}


void time() {
	std::string ans;
	std::cout << "Doyou need hoursminutesseconds or days(input 'hms' or 'days')";
	std::cin >> ans;
	if (ans == "hms") {
		int T1[3], T2[3]; // t[0] = h ours , t[1] = m inutes , t[2] = s econds
		std::cin >> T1[0] >> T1[1] >> T1[2];
		std::cin >> T2[0] >> T2[1] >> T2[2];
		if ((T1[0] * 3600 + T1[1] * 60 + T1) - (T2[0] * 3600 + T2[1] * 60 + T2[2]) >= 0) {
			std::cout << "equal or greater";
		}
		else {
			std::cout << "lesser";
		}
	}
	else {
		int D1[3], D2[3], sum, fact, differencefirst = 0, differenceall = 0, differencelast = 0, numofdays[] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
		std::cin >> D1[0] >> D1[1] >> D1[2]; // d[0] = day , d[1] = month, d[2] = year
		std::cin >> D2[0] >> D2[1] >> D2[2];
		if ((D1[2] < D2[2]) || (D1[2] == D2[2] && D1[1] < D2[1]) || (D1[2] == D2[2] && D1[1] == D2[1] && D1[0] < D2[0])) {
			std::cout << "equal or greater" << std::endl;
			fact = 1;
		}
		else {
			std::cout << "lesser" << std::endl;
			fact = 0;
		}
		if (fact == 0) {
			std::swap(D1[0], D2[0]);
			std::swap(D1[1], D2[1]);
			std::swap(D1[2], D2[2]);
		}
		// counting:
		if ((D1[1] <= 2) && ((D1[2] % 4 == 0 && D1[2] % 100 != 0) || (D1[2] % 400 == 0))) {
			differencefirst += 1;
		}
		for (int month = D1[1]; month <= 12; month++) {
			differencefirst += numofdays[month - 1];
		}
		differencefirst -= D1[0] - 1;

		for (int year = D1[2] + 1; year < D2[2]; year++) {
			if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
				differenceall += 366;
			}
			else {
				differenceall += 365;
			}
		}
			
		if ((D2[1] <= 2) && ((D2[2] % 4 == 0 && D2[2] % 100 != 0) || (D2[2] % 400 == 0))) {
			differencelast += 1;
		}
		for (int month = D2[1]; month <= 12; month++) {
			differencelast += numofdays[month - 1];
		}
		differencelast -=D2[0] - 1;
		differencelast = 365 - differencelast;
		if (D2[2] == D1[2]) {
			std::cout << "Difference is: " << 365 - (365 - differencefirst + 365 - differencelast) << std::endl;
		}
		else {
			std::cout << "Difference is: " << differenceall + differencefirst + differencelast << std::endl;
		}
	}
}
//7 03 2009
//22 01 2000
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
