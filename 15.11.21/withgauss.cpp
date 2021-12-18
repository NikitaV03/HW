
#include <iostream>
#include "twodimarrays.h"
#include <cmath>

int gaussmatrix(double** matrix, int n) {
    int countswaps = 1;
    for (int i = 0; i < n; ++i) {
        int maxint = 0;
        for (int j = i; j < n; ++j) {
            if (abs(matrix[j][i]) > abs(matrix[maxint][i])) {
                maxint = j;
            }
        }
        if (abs(matrix[maxint][i]) <= 0.00000001) {
            continue;
        }
        std::swap(matrix[maxint][i], matrix[i][i]);
        countswaps++;
        for (int j = i + 1; j < n; ++j)
        {
            double q = -matrix[j][i] / matrix[i][i];
            for (int k = n - 1; k >= i; --k) {
                matrix[j][k] += q * matrix[i][k];
            }
        }
    }
    return (countswaps%2==1) ? 1 :-1;
}



int main()
{
    size_t rows, cols;
    std::cout << "number of rows&cols: " << std::endl;
    std::cin >> rows;
    cols = rows;
    double **arr = createarraypls<double>(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = rand() % 10 -5 ;
        }
    }
    for (int i = 1; i < rows-1; ++i) {    
        arr[i][i] = 0;
    }
    double** arr2 = createarraypls<double>(5, 5);
    
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            arr2[i][j] = rand() % 10;
        }
    }
    for (int i = 1; i < 4; ++i) {
        for (int j = 1; j < 4; ++j) {
            arr2[i][j] = 0;
        }
    }
    printnicearray<double>(arr, rows, cols, 10);
    gaussmatrix(arr, rows);
    printnicearray<double>(arr, rows, cols, 20);
    printnicearray<double>(arr2, 5, 5, 10);
    gaussmatrix(arr2, 5);
    printnicearray<double>(arr2, 5, 5, 20);
}
