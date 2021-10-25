#include <iostream>

int randomarray(int* array, int n, int a=1, int b=100);
int minelements(int* array, int n);
double sredarifm(int massiv[], int n);
void swapbyaverage(int massiv[], int n, double average);
int countallnumbers100(int* array, int n);
void sortme(int* array, int n);

int main()
{
	int exit;
	// main code

	int n;
	std::cout << "Input number of elements in random array: ";
	std::cin >> n;
	int* array= new int[n];
	randomarray(array, n);//create an array
	minelements(array,n);//find min elements
	int average = sredarifm(array, n);//find average
	std::cout << "average = " << average << std::endl;
	swapbyaverage(array, n, average);
	for (int i = 0; i < n; ++i) {
		std::cout << array[i] << std::endl;
	}
	std::cout << "most common number is " <<countallnumbers100(array,n) <<std::endl;
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

void swapbyaverage(int massiv[], int n, double average) {
	int tmp = 0, lesscounter = 0;
	for (int i = 0; i < n; ++i) {
		if (massiv[i] < average)
			lesscounter += 1;
	}
	std::cout << "lesscounter = " << lesscounter << std::endl;
	int j = 0;
	for (int i = 0; i < lesscounter; ++i) {
		while (massiv[i] > average) {
			tmp = massiv[i];
			massiv[i] = massiv[n - 1 - j];
			massiv[n - 1 - j] = tmp;
			j += 1;
		}

	}
	std::cout << "After swap" << std::endl;
	for (int i = 0; i < n; ++i) {
		std::cout << massiv[i] << std::endl;
	}
	std::cout << std::endl;
	std::cout << "number of comparisons = " << j << std::endl << std::endl;
}

int minelements(int* array,int n) {
	int minel = 2147483647, counter = 1;
	for (int i = 0; i < n; ++i) {
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
	std::cout << "minel = " << minel << std::endl;
	std::cout << "number of minel = " << counter << std::endl;
	return* array;
}

int randomarray(int* array, int n, int a, int b) {
	for (int i = 0; i < n; ++i) {
		array[i] = rand() % 100 + a;
	}
	return *array;
}

// works only with [1,100]
int countallnumbers100(int* array, int n) { 
	int number=0;
	int numberofnumbers[100];
	for (int i = 0; i < 100; ++i) {
		numberofnumbers[i] = 0;
	}
	for (int i = 0; i < n; ++i) {
		numberofnumbers[array[i]-1] += 1;
	}

	int maxel = 0, ind = -1;
	for (int i = 0; i < 100; ++i) {
		if (numberofnumbers[i] > maxel) {
			maxel = numberofnumbers[i];
			ind = i;
		}
	}
	number = ind + 1;
	return number;
}

