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

template<typename T> //7
void multyplybynum(T** matrix, int n, int m, int num) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            matrix[i][j] *= num;
        }
    }
}

template<typename T> //8
T** newmultiplybynum(T** matrix, int n, int m, int num) {
    T** b = createarraypls<T>(n, m);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            b[i][j] =  matrix[i][j] * num;
        }
    }
    return b;
}

template<typename T> //9
T** newaddtwomatrix(T** matrix1, int n1, int m1, T** matrix2) {
    int** c;
    c = createarraypls<int>(n1, m1);
    for (int i = 0; i < n1; ++i) {
        for (int j = 0; j < m1; ++j) {
            c[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    return c;
}

template<typename T> //10
T** multiplytwomatrix(T** matrix1, int n1, int m1, T** matrix2, int n2, int m2) {
    T** c;
    if (m1 == n2) {
        c = createarraypls<T>(n1, m2);
        for (int i = 0; i < n1; ++i) {
            for (int j = 0; j < m2; ++j) {
                c[i][j] = 0;
                for (int k = 0; k < m1; ++k) {
                    c[i][j] += matrix1[i][k] * matrix2[k][j];
                }
            }
        }
    }
    else {
        c = createarraypls<T>(1, 1);
        c[0][0] = -1;
    }
    return c;
}

template<typename T> //11
void replacerowscols(T** matrix, int n, int m, size_t r1, size_t r2, bool isrows = 1) {
    int tmp;
    if (isrows) {
        for (int j = 0; j < m; ++j) {
            tmp = matrix[r1][j];
            matrix[r1][j] = matrix[r2][j];
            matrix[r2][j] = tmp;
        }
    }
    else {
        for (int i = 0; i < n; ++i) {
            tmp = matrix[i][r1];
            matrix[i][r1] = matrix[i][r2];
            matrix[i][r2] = tmp;
        }
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
T returnel(T** matrix, size_t n, size_t m) {
    return matrix[n][m];
}

template<typename T>
void test(size_t rows, size_t cols, T yoursymb = 1) {
    T** arr = createarraypls<T>(rows, cols);
    std::cout << "const:" << std::endl;
    constarray<T>(arr, rows, cols, yoursymb);
    printarray<T>(arr, rows, cols);
    std::cout << "ones:" << std::endl;
    onesarray<T>(arr, rows, cols);
    printnicearray<T>(arr, rows, cols, 3);

    std::cout << "transposed: " << std::endl;
    T** b = transponmatrix<T>(arr, rows, cols);
    printnicearray<T>(b, cols, rows, 3);

    std::cout << "upsidedown:" << std::endl;
    perevorot<T>(arr, rows, cols);
    printnicearray<T>(arr, rows, cols, 3);
    std::cout << "multiplied:" << std::endl;
    multyplybynum<T>(arr, rows, cols, 5);
    printnicearray<T>(arr, rows, cols, 3);
    std::cout << "newmultipliedbynum:" << std::endl;
    T** c = newmultiplybynum<T>(arr, rows, cols, 10);
    printnicearray<T>(c, rows, cols, 3);
    std::cout << "newsum:" << std::endl;
    T** d = newaddtwomatrix<T>(arr, rows, cols, c);
    printnicearray<T>(d, rows, cols, 3);
    std::cout << "newmultiplied:" << std::endl;
    T** e = multiplytwomatrix<T>(d, rows, cols, b, cols, rows);
    printnicearray<T>(e, rows, rows, 3);
    std::cout << "rowscolsreplaced:" << std::endl;
    replacerowscols<T>(d, rows, cols, 1, 2);
    printnicearray<T>(d, rows, cols, 3);
    deletearray<T>(arr, rows);
    deletearray<T>(b, cols);
    deletearray<T>(c, rows);
    deletearray<T>(d, rows);
    deletearray<T>(e, rows);
}

