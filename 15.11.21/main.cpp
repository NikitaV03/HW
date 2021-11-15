#include <iostream>
#include <string>
void printarray(int* a[], size_t n, size_t m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printnicearray(int* a[], size_t n, size_t m, size_t symb = 4) {
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


void deletearray(int** a, size_t n) {
    for (int i = 0; i < n; ++i) {
        delete[] a[i];
    }
    delete[] a;
}

int** createzeroarray(size_t rows, size_t cols) {
    int** arr = new int* [rows];
    for (int k = 0; k < rows; ++k) {
        arr[k] = new int [cols];
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            arr[i][j] = 0;
        }
    }
    return arr;
}
void horizontalsnake(int** arr,size_t n,size_t m) {
    int counter = 1;
    for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
            for (int k = 0; k < m; ++k) {
                arr[i][k] = counter++;
            }
        }
        else {
            for (int k = m - 1; k >= 0; --k) {
                arr[i][k] = counter++;
            }
        }
    }
}

void diagonalsnake(int** arr, size_t n, size_t m) {
    // first step
    int counter = 1;
    int diag = 0;
    while ((diag < n-1) && (diag<m-1)){
        diag += 1;
        if (diag % 2 == 0) {
            for (int i = 0; i < diag; ++i) {
                arr[diag - i - 1][i] = counter++;
            }
        }
        else {
            for (int i = 0; i < diag; ++i) {
                arr[i][diag - i - 1] = counter++;
            }
        }
    }
    // second step
    int maxdim = (n > m) ? n : m, yadd = (m>n) ? 1:0, xadd = (n > m) ? 1 : 0;
    diag++;
    int evenness = diag;
    for (int j = 0; j < maxdim - diag + 1; ++j) {
        if (yadd > 0) {
            if (evenness % 2 == 0) {
                for (int i = 0; i < diag; ++i) {
                    arr[diag - i - 1][i + yadd - 1] = counter++;
                }
            }
            else {
                for (int i = 0; i < diag; ++i) {
                    arr[i][diag - i - 1 + yadd - 1] = counter++;
                }
            }
            yadd++;
        }
        else if (xadd > 0) {
            if (evenness % 2 == 0) {
                for (int i = 0; i < diag; ++i) {
                    arr[diag - i - 1 +xadd -1][i] = counter++;
                }
            }
            else {
                for (int i = 0; i < diag; ++i) {
                    arr[i+xadd-1][diag - i - 1] = counter++;
                }
            }
            xadd++;
        }
        else{
            if (evenness % 2 == 0) {
                for (int i = 0; i < diag; ++i) {
                    arr[diag - i - 1][i] = counter++;
                }
            }
            else {
                for (int i = 0; i < diag; ++i) {
                    arr[i][diag - i - 1] = counter++;
                }
            }
            xadd++;
        }
        evenness++;
    }

    // third step
    --diag;
    while (diag > 0) {
        if (evenness % 2 != 0) {
            for (int i = 0; i < diag; ++i) {
                arr[n - diag + i][m - i - 1] = counter++;
            }
        }
        else {
            for (int i = 0; i < diag; ++i) {
                arr[n - i - 1][m - diag + i] = counter++;
            }
        }
        --diag;
        evenness++;
    }
}

void spiralsnake(int** arr, size_t n, size_t m) {
    int direction = 1, counter = 1, x=0, y=-1;
    int iters = 0;
    while (direction!=0) {
        switch (direction) {
        case 1:
            iters = 0;
            ++y;
            while ((direction == 1)&& (y<m)) {
                if (arr[x][y] == 0) {
                    arr[x][y] = counter++;
                    ++y;
                    ++iters;
                }
                else {
                    direction = 2;
                    --y;
                    ++iters;
                }
            }
            if (iters == 1) {
                direction = 0;
            }
            if (y == m) {
                y--;
                direction = 2;
            }

        case 2:
            iters = 0;
            x++;
            while ((direction == 2)&&(x<n)) {
                if (arr[x][y] == 0) {
                    arr[x][y] = counter++;
                    ++x;
                    ++iters;
                }
                else {
                    direction = 3;
                    --x;
                    ++iters;
                }
            }
            if (iters == 1) {
                direction = 0;
            }
            if (x == n) {
                --x;
                direction = 3;
            }

        case 3:
            --y;
            iters = 0;
            while ((direction == 3) && (y >= 0)) {
                if (arr[x][y] == 0) {
                    arr[x][y] = counter++;
                    --y;
                    ++iters;
                }
                else {
                    ++y;
                    direction = 4;
                    ++iters;

                }
            }
            if (iters == 1) {
                direction = 0;
            }
            if (y == -1) {
                ++y;
                direction = 4;
            }

        case 4:
            x--;
            iters = 0;
            while ((direction == 4) && (x >= 0)) {
                if (arr[x][y] == 0) {
                    arr[x][y] = counter++;
                    --x;
                    ++iters;
                }
                else {
                    ++x;
                    ++iters;
                    direction = 1;
                }
            }
            if (iters == 1) {
                direction = 0;
            }
        }
    }
}

void constarray(int** arr, int n, int m, int constant) {
    for (int i=0;i<n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = constant;
        }
    }
}

bool testarray(int** arr, int n, int m) {
    bool test = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if ((arr[i][j] <= 0) || (arr[i][j] > n * m)) {
                return false;
            }
            if (arr[i][j] == n * m) {
                test = true;
            }
        }
    }
    return test;
}


int main()
{
    int rows = 0, cols = 0;
    while ((rows <= 0) || (cols <= 0)) {
        std::cout << " Input rows : ";
        std::cin >> rows;
        std::cout << " Input columns : ";
        std::cin >> cols;
    }
    int** arr = createzeroarray(rows, cols);
    std::cout << " Diagonal snake array: " << std::endl;
    diagonalsnake(arr, rows, cols);
    printnicearray(arr, rows, cols);
    std::cout << (testarray(arr, rows, cols) ? "general test passed" : "general test failed") << std::endl << std::endl;
    deletearray(arr, rows);

    int** arr2 = createzeroarray(rows, cols);
    std::cout << " Spiral snake array: " << std::endl;
    spiralsnake(arr2, rows, cols);
    printnicearray(arr2, rows, cols);
    std::cout << (testarray(arr2, rows, cols) ? "general test passed" : "general test failed") << std::endl << std::endl;
    deletearray(arr2, rows);


    int** arr3 = createzeroarray(rows, cols);
    std::cout << " Horizontal snake array: " << std::endl;
    horizontalsnake(arr3, rows, cols);
    printnicearray(arr3, rows, cols);
    std::cout << (testarray(arr3, rows, cols) ? "general test passed": "general test failed") << std::endl << std::endl;
    deletearray(arr3, rows);

    int** arr4 = createzeroarray(rows, cols);
    std::cout << " Constants array: " << std::endl;
    constarray(arr4, rows, cols, 5);
    printnicearray(arr4, rows, cols);
    deletearray(arr4, rows);

    return 0;
}
