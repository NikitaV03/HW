#include <iostream>
void minelements(int n);
double sredarifm(int massiv[], int n);

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

void minelements(int n) {
	int* array = new int[n];
	int minel = 100,counter = 1;
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
	std::cout << "average = "<< sredarifm(array, n)<< std::endl;
	std::cout << "minel = " << minel <<std::endl;
	std::cout << "number of minel = " << counter << std::endl;
}

double sredarifm(int massiv[],int n) {
	int countersrednevo=0;
	for (int i = 0; i < n; ++i) {
		countersrednevo += massiv[i];
	}
	double average = double(countersrednevo)/double(n);
	return average;
}
