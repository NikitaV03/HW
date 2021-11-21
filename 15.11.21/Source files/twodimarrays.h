#pragma once
#include<string>

template<typename T> //1
T** createarraypls(size_t rows, size_t cols) {
    T** arr = new T* [rows];
    for (int k = 0; k < rows; ++k) {
        arr[k] = new T[cols];
    }
    return arr;
}

template<class T> //2
void deletearray(T** a, size_t n) {
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
}

template<typename T> //3
void constarray(T** arr, int n, int m, T constant) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = constant;
        }
    }
}

template<typename T> //4
void onesarray(T** arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
}

template<typename T> //5
T** transponmatrix(T** matrix, int n, int m) {
    T** matrix2 = createarraypls<T>(m, n);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            matrix2[j][i] = matrix[i][j];
        }
    return matrix2;
}

template<typename T> // 6
void perevorot(T** matrix, size_t n, size_t m) {
    for (int i = 0; i < n/2; ++i)
        for (int j = 0; j < m; ++j) {
            T tmp = matrix[i][j];
            matrix[i][j] = matrix[n-i-1][m-j-1];
            matrix[n - i - 1][m - j - 1] = tmp;
        }
    if (n % 2 == 1) for (int j = 0; j <= m/2 + 1; ++j) {
        T tmp = matrix[n/2][j];
        matrix[n/2][j] = matrix[n/2][m - j - 1];
        matrix[n / 2][m - j - 1] = tmp;
    }
}

template<typename T>
void printarray(T* a[], size_t n, size_t m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
void printnicearray(T* a[], size_t n, size_t m, size_t symb = 4) {
    int lenstr = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::string str = std::to_string(a[i][j]);
            lenstr = str.length();
            for (int k = 0; k < symb - lenstr; k++) std::cout << " ";
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

template<typename T>
void test(size_t rows, size_t cols, T yoursymb = 1) {
    T** arr = createarraypls<T>(rows, cols);
    constarray<T>(arr, rows, cols, yoursymb);
    printarray<T>(arr, rows, cols);
    onesarray<T>(arr, rows, cols);
    printnicearray<T>(arr, rows, cols, 3);
    T** b = transponmatrix<T>(arr, rows, cols);
    printnicearray<T>(b, cols, rows, 3);
    perevorot<T>(arr, rows, cols);
    printnicearray<T>(arr, rows, cols, 3);
    deletearray<T>(arr, rows);
    deletearray<T>(b, cols);
}
