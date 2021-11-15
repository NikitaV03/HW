
#include <iostream>
#include "twodimarrays.h"

template<typename T>
void test(size_t rows,size_t cols, T yoursymb = 1) {
    T** arr = createarraypls<T>(rows, cols);
    constarray<T>(arr, rows, cols, yoursymb);
    printarray<T>(arr, rows, cols);
    onesarray<T>(arr, rows, cols);
    printnicearray<T>(arr, rows, cols, 3);
    deletearray<T>(arr, rows);
}
int main()
{
    size_t rows, cols;
    std::cout << "number of rows: " << std::endl;
    std::cin >> rows;
    std::cout << "number of columns: " << std::endl;
    std::cin >> cols;
    test<char>(rows, cols);
    test<int>(rows, cols);
}
