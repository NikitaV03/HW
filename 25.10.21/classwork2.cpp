#include <iostream>

int array_20_3();
void printarray_20_3(int array);
int swaparray_20_3(int array);

int main()
{
	int exit;
	//int a[2][2] = { {3,2},{4,6} };
	//for (int i = 0; i < 2; ++i) {
	//	for (int j = 0; j < 2; ++j) {
	//		std::cout << a[i][j] << " ";
	//	}
	//	std::cout << std::endl;
	//}

	array_20_3();
	std::cin >> exit;
    return 0;
}

int array_20_3() {
	int array[20][3];
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 3; ++j) {
			array[i][j] = rand() % 100 + 1;
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
	return 0;
}

void printarray_20_3(int array){
	for (int i = 0; i < 20; ++i) {
		for (int j = 0; j < 3; ++j) {
			std::cout << array[i][j] << " ";
		}
		std::cout << std::endl;
	}
}
int swaparray_20_3(int array) {
	printarray_20_3(array)
	return 0;
}
