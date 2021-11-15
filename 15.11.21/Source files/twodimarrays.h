#pragma once
#include<string>
template<typename T>
T** createarraypls(size_t rows, size_t cols) {
    T** arr = new T* [rows];
    for (int k = 0; k < rows; ++k) {
        arr[k] = new T[cols];
    }
    return arr;
}

template<typename T>
void constarray(T** arr, int n, int m, T constant) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = constant;
        }
    }
}

template<typename T>
void onesarray(T** arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j) arr[i][j] = 1;
            else arr[i][j] = 0;
        }
    }
}

template<typename T>
void transponmatrix(T** matrix, int n, int m) {
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            tmp = matrix[i * 4 + j];
            matrix[i * 4 + j] = matrix[j * 4 + i];
            matrix[j * 4 + i] = tmp;
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

template<class T>
void deletearray(T** a, size_t n) {
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
}
