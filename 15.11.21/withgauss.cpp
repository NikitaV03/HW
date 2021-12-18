
#include <iostream>
#include "twodimarrays.h"
#include <cmath>

int gaussmatrix(double** matrix, int n) {
    int countswaps = 1;
    for (int i = 0; i < n; ++i) {
        int maxint = i;
        for (int j = i; j < n; ++j) {
            if (abs(matrix[j][i]) > abs(matrix[maxint][i])) {
                maxint = j;
            }
        }
        if (abs(matrix[maxint][i]) <= 0.00000001) {
            continue;
        }
        for (int k = i; k < n; ++k) {
            std::swap(matrix[maxint][k], matrix[i][k]);
        }
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

double gaussdeterminant(double** matrix, int n) {
    double product = 1;
    for (int i = 0; i < n; ++i) {
        product *= matrix[i][i];
    }
    return product;
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

    double** arr3 = createarraypls<double>(4, 4);
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            arr3[i][j] = rand() % 10;
        }
    }
    for (int i = 1; i < 2; ++i) {
        for (int j = 1; j < 2; ++j) {
            arr3[i][j] = 0;
        }
    }

    printnicearray<double>(arr, rows, cols, 10);
    gaussmatrix(arr, rows);
    std::cout << "determinant is:    " << gaussdeterminant(arr, rows) << std::endl;
    printnicearray<double>(arr, rows, cols, 20);
    printnicearray<double>(arr2, 5, 5, 10);
    gaussmatrix(arr2, 5);
    std::cout << "determinant is:    " << gaussdeterminant(arr2, 5) << std::endl;
    printnicearray<double>(arr2, 5, 5, 20);
    printnicearray<double>(arr3, 4, 4, 10);
    gaussmatrix(arr3, 4);
    std::cout << "determinant is:    " << gaussdeterminant(arr3, 4) << std::endl;
    printnicearray<double>(arr3, 4, 4, 20);
}
