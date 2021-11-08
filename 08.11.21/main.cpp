#include <iostream>

void integralsum(int a[][3],int rows) {
    int integr = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i > 0 && j > 0) {
                a[i][j] = a[i][j] + a[i][j - 1] + a[i - 1][j] + a[i - 1][j - 1];
            }
            else if (i > 0) {
                a[i][j] = a[i][j] + a[i - 1][j];
            }
            else if (j > 0) {
                a[i][j] = a[i][j] + a[i][j - 1];
            }
            //std::cout << a[i][j] << std::endl;
        }
    }
}

void integralsum2(int a[], size_t n, size_t m) {
    int integr = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i > 0 && j > 0) {
                a[i * m + j] = a[i*m + j] + a[i*m + j - 1] + a[(i - 1)*m + j] + a[(i - 1)*m + j - 1];
            }
            else if (i > 0) {
                a[i * m + j] = a[i * m + j] + a[(i - 1) * m + j];
            }
            else if (j > 0) {
                a[i * m + j] = a[i * m + j] + a[i * m + j - 1];
            }
            //std::cout << a[i * m + j] << std::endl;
        }
    }
}

void printarray(int a[], size_t n, size_t m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << a[i * m + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

void printpartarray(int a[], size_t n, size_t m, int *coord) {
    for (int i = coord[2]; i <= coord[3]; ++i) {
        for (int j = coord[0]; j <= coord[1]; ++j) {
            std::cout << a[i * m + j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

int* countones(int a[], size_t n, size_t m) {
    int count, x1, y1, x2, y2, countiter, maxone = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            for (int k = i; k < n; ++k) {
                for (int l = j; l < m; ++l) {
                    count = 0;
                    countiter = 0;
                    for (int a1 = i; a1 <= k; ++a1) {
                        for (int a2 = j; a2 <= l; ++a2) {
                            ++countiter;
                            count += a[a1 * m + a2];
                        }
                    }
                    if (count == countiter) {
                        //std::cout << count << "  "  << std::endl;
                        if (count > maxone) {
                            maxone = count;
                            y1 = i;
                            y2 = k;
                            x1 = j;
                            x2 = l;
                        }
                    }
                }
            }
        }
    }
    std::cout << x1 << " " << x2 << " " << y1 << " " << y2 << " " << std::endl;
    int coord[4] = { x1,x2,y1,y2 };
    return coord;
}

int main() {
    // Write C++ code here
    int a[2][3] = { {1,2,3},{4,5,6} };
    integralsum(a,2); // 1,3,6; 5,14,29
    int bigarray[3][3] = {{1,5,9},{6,7,8},{19,2,20}};
    //integralsum(bigarray,3);
    integralsum2(*bigarray,3,3);
    printarray(*bigarray,3,3);
    int oz[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            oz[i][j] = rand() % 2;
        }
    }
    int oz2[10][10];
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            oz2[i][j] = rand()/5 % 2;
        }
    }
    int* coord = countones(*oz, 10, 10);
    //printarray(*oz, 10, 10);
    //integralsum2(*oz, 10, 10);
    printarray(*oz, 10, 10);
    std::cout << "Ones only array: " << std::endl;
    printpartarray(*oz, 10, 10, coord);

    int* coord2 = countones(*oz2, 10, 10);
    printarray(*oz2, 10, 10);
    std::cout << "Ones only array: " << std::endl;
    printpartarray(*oz2, 10, 10, coord2);
    return 0;
}
