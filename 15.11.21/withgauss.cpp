#include <iostream>
#include "twodimarrays.h"
#include <cmath>
int gaussmatrix(double** matrix, int n) {
    int countswaps = 0;
    for (int i = 0; i < n; ++i) {
        int maxint = i;
        for (int j = i; j < n; ++j) {
            if (abs(matrix[j][i]) > abs(matrix[maxint][i])) {
                maxint = j;
            }
        }
        if (abs(matrix[maxint][i]) < 0.00000001) {
            continue;
        }
        for (int k = 0; k < n; ++k) {
            std::swap(matrix[maxint][k], matrix[i][k]);
        }
        if (maxint != i) {
            countswaps++;
        }
        for (int j = i + 1; j < n; ++j)
        {
            double q = -matrix[j][i] / matrix[i][i];
            for (int k = n - 1; k >= i; --k) {
                matrix[j][k] += q * matrix[i][k];
            }
        }
    }
    return (countswaps % 2 == 0) ? 1 : -1;
}

double gaussdeterminant(double** matrix, int n) {
    double product = 1;
    for (int i = 0; i < n; ++i) {
        product *= matrix[i][i];
    }
    return product;
}


//1. проверка, что под диагональю числа меньше 0.00000001 (из-за неточности в вычислениях не можем проверять, что числа равны 0)
bool gausstest(double** matrix, int n) {
    bool isok = true;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (abs(matrix[i][j]) > 0.00000001){
                isok = false;
            }
        }
    }
    if (isok) {
        std::cout << " only zeros under diagonal: + " << std::endl;
    }
    else {
        std::cout << " only zeros under diagonal: - " << std::endl;
    }
    return isok;
}

int main()
{
    //создаем и заполняем матрицы
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

    // проверяем на трех матрицах
    std::cout << "before: " << std::endl;
    printnicearray<double>(arr, rows, cols, 10);
    int ct1 = gaussmatrix(arr, rows);
    gausstest(arr, rows);
    std::cout << "determinant: " << ct1 * gaussdeterminant(arr, rows) << std::endl;
    std::cout << "after: " << std::endl;
    printnicearray<double>(arr, rows, cols, 20);
    std::cout << "before: " << std::endl;
    printnicearray<double>(arr2, 5, 5, 10);
    int ct2 = gaussmatrix(arr2, 5);
    gausstest(arr2, 5);
    std::cout << "determinant: " << ct2 * gaussdeterminant(arr2, 5) << std::endl;
    std::cout << "after: " << std::endl;
    printnicearray<double>(arr2, 5, 5, 20);
    std::cout << "before: " << std::endl;
    printnicearray<double>(arr3, 4, 4, 10);
    int ct3 =  gaussmatrix(arr3, 4);
    gausstest(arr3, 4);
    std::cout << "determinant: " << ct3 * gaussdeterminant(arr3, 4) << std::endl;
    std::cout << "after: " << std::endl;
    printnicearray<double>(arr3, 4, 4, 20);
    deletearray<double>(arr, rows);
    deletearray<double>(arr2, 5);
    deletearray<double>(arr3, 4);
}
