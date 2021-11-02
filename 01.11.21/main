#include <iostream>

void transponmatrix(int* matrix, int n, int m) {
	int tmp = 0;
	for (int i = 0; i<n-1; ++i)
		for (int j = 1+i; j < m; ++j) {
			tmp = matrix[i * 4 + j];
			matrix[i * 4 + j] = matrix[j * 4 + i];
			matrix[j * 4 + i] = tmp;
		}
}

void printmatrix(int* matrix, int n, int m){
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cout << matrix[i * 4 + j] << " ";
		}
		std::cout << std::endl;
	}
}

int main(){
	int matrix[4][4] = { {1,2,3,4},{5,6,7,8},{12,11,10,9},{16,15,14,13} };
	std::cout << "before function: " << std::endl;
	printmatrix(*matrix, 4, 4);
	std::cout << std::endl;
	transponmatrix(*matrix, 4, 4);
	std::cout << "after function: " << std::endl;
	printmatrix(*matrix, 4, 4);
	std::cout << std::endl;
	return 0;
}
