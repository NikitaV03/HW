#include <iostream>
void minelements(int n);
double sredarifm(int massiv[], int n);
double swapbyaverage(int massiv[], int n, double average);

int main()
{
	int exit;
	// main code
	int n;
	std::cout << "Input number of elements in random array: ";
	std::cin >> n;
	minelements(n);
	// exit
	std::cout << "Type something to leave ";
	std::cin >> exit;
    return 0;
}

double sredarifm(int massiv[],int n) {
	int countersrednevo=0;
	for (int i = 0; i < n; ++i) {
		countersrednevo += massiv[i];
	}
	double average = double(countersrednevo)/double(n);
	return average;
}

double swapbyaverage(int massiv[],int n, double average) {
	int tmp=0,lesscounter=0;
	for (int i = 0; i < n; ++i) {
		if (massiv[i] < average)
			lesscounter += 1;
	}
	std::cout << "lesscounter = " << lesscounter << std::endl;
	for (int i = 0; i < lesscounter; ++i) {
		int j = 0;
		while (massiv[i] > average) {
			tmp = massiv[i];
			massiv[i] = massiv[n - 1 -j];
			massiv[n - 1 - j] = tmp;
			j += 1;
		}

	}
	std::cout << std::endl;
	std::cout << "After swap" << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cout << massiv[i] << std::endl;
	}
	return 0;
}

void minelements(int n) {
	int* array = new int[n];
	int minel = 100, counter = 1;
	for (int i = 0; i < n; ++i) {
		array[i] = rand() % 100 + 1;
		if (array[i] < minel) {
			minel = array[i];
			counter = 1;
		}
		else if (array[i] == minel) {
			counter += 1;
		}
	}
	for (int i = 0; i < n; ++i) {
		std::cout << array[i] << std::endl;
	}
	int average = sredarifm(array, n);
	std::cout << "average = " << average << std::endl;
	std::cout << "minel = " << minel << std::endl;
	std::cout << "number of minel = " << counter << std::endl;
	swapbyaverage(array, n, average);
}
