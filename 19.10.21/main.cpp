// ConsoleApplication3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

void collats();
void krivaya();
void randomkrug();
void nerandomkrug();
void sumandpros();
double rowpi();
void rowtaylor();
void rowsinusov();
void goosesnrabbits();

int main()
{
	int vihod;
	goosesnrabbits();

	std::cin >> vihod;
	return 0;
}

void collats() {
	int chislik;
	std::cout << "Input number: ";
	std::cin >> chislik;
	while (chislik != 1) {
		if (chislik % 2 == 1) {
			chislik = chislik * 3 + 1;
		}
		else {
			chislik /= 2;
		}
		std::cout << chislik << " ";
	}
}
void krivaya() {
	//doesn't work
	//double A[2];
	//double b[2];
	//double c[2];

	//std::cin >> a[0] >> a[1];
	//std::cin >> b[0] >> b[1];
	//std::cin >> c[0] >> c[1];
	//std::cout << c[0] << " " << c[1] << std::endl;
	//double acsq = pow((c[0] - a[0]), 2) + pow((c[1] - a[1]), 2);
	//double bcsq = pow((c[0] - b[0]), 2) + pow((c[1] - b[1]), 2);
	//double summa = sqrt(ac) + sqrt(bc);
	//double right = 4 * acsq*bcsq;
	///*double left = idk*/
	//std::cout << summa << std::endl;
	//std::cin >> x;
}
void randomkrug() {
	double radius, a1, a2;
	int tochnost = 3000;
	int counterkrug = 0;
	std::cout << "Input radius";
	std::cin >> radius;
	for (int i = 1; i <= tochnost; i++) {
		a1 = (rand() / double(RAND_MAX)) * radius;
		a2 = (rand() / double(RAND_MAX)) * radius;
		if (a1 * a1 + a2 * a2 <= radius * radius)
			counterkrug += 1;
	}
	std::cout << counterkrug << " " << tochnost << std::endl;
	std::cout << 4 * double(counterkrug) / double(tochnost);

}
void nerandomkrug() {
	double radius;
	int r;
	int counter = 0;
	std::cin >> radius;
	r = floor(radius);
	for (int i = 0; i <= r; i++) {
		for (int j = 1; j <= r; j++) {
			if ((pow(i, 2) + pow(j, 2)) <= pow(r, 2)) {
				counter += 1;
			}
		}
	}
	std::cout << (counter * 4 + 1) / (r * 2 - 1) * (r * 2 - 1);
}
void sumandpros() {
	int chislo, sumch = 0, proisch = 1;
	std::cin >> chislo;
	do {
		sumch += chislo % 10;
		proisch *= chislo % 10;
		chislo /= 10;
	} while (chislo != 0);
	std::cout << proisch << " " << sumch << std::endl;
}
double rowpi() {
	double pi = 0;
	int tochn = 10000;
	std::cout << std::endl;
	for (int i = 1; i <= tochn; i++) {
		pi += (pow(-1, i + 1) * 1 / (2 * i - 1));
	}
	pi *= 4;
	return pi;
}
void rowtaylor() {
	double x, s = 0;
	int n;
	double fact = 1;
	double pi;
	pi = rowpi();
	std::cin >> x >> n;
	for (int i = 1; i <= 2 * n; i += 2) {
		s += pow((-1), i % 4 / 2 + 1) * pow(pi, i) / fact;
		fact *= (i + 1) * (i + 2);
		std::cout << s << " " << i << " ";
	}
	std::cout << s;
}
void rowsinusov() {
	double pi;
	double lastvar, toch, x, s;
	pi = rowpi();
	s = 0;
	std::cin >> x >> toch;
	lastvar = pi;
	for (int i = 1; i <= toch; i++) {
		lastvar = sin(lastvar);
		s += lastvar;
	}
	std::cout << s << std::endl;
}
void goosesnrabbits() {
	int paws,gooses,rabbits,counter=0;
	std::cout << "Input number of paws: ";
	std::cin >> paws;
	if (paws % 2 == 0) {
		gooses = paws / 2;
		rabbits = 0;
		do {
			std::cout << "gooses: " << gooses << " " << "rabbits: " << rabbits << std::endl;
			rabbits += 1;
			gooses -= 2;
			counter += 1;
		} while (gooses != -1 and gooses != -2);
	}
	else {
		std::cout << "Invalid number";
	}
	std::cout << counter;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
