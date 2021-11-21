
#include <iostream>
#include "twodimarrays.h"
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
