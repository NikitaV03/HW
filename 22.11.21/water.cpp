#include <iostream>
#include<string>

template<typename T>
T** createarraypls(size_t rows, size_t cols) {
    T** arr = new T * [rows];
    for (int k = 0; k < rows; ++k) {
        arr[k] = new T[cols];
    }
    return arr;
}

void zeroarray(int** arr, int n, int m) {
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            arr[i][j] = 0;
        }
    }
}

void randomintarray(int** a,size_t rows, size_t cols,size_t symb = 5) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            a[i][j] = rand() % (symb + 1);
        }
    }
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

int **createb() {
    int** b = new int*[1];
    b[0] = new int[1];
    b[0][0] = -1;
    return b;
}
int** createmap(int** a, size_t n, size_t m, size_t ny = 0, size_t mx = 0, int **b = createb(),int constant = -1) {
    if (b[0][0] == -1) {
        int** b = createarraypls<int>(n,m);
        zeroarray(b, n, m);
        b[ny][mx] = 1;
        constant = a[ny][mx];
        if ((ny > 0) && (b[ny - 1][mx] == 0) && (constant+1 >= a[ny - 1][mx])) {
            b[ny - 1][mx] = 1;
            createmap(a, n, m, ny - 1, mx, b, constant);
        }
        if ((mx > 0) && (b[ny][mx-1] == 0) && (constant + 1 >= a[ny][mx-1])) {
            b[ny][mx - 1] = 1;
            createmap(a, n, m, ny, mx - 1, b, constant);
        }
        if ((ny < n-1) && (b[ny + 1][mx] == 0) && (constant + 1 >= a[ny + 1][mx])) {
            b[ny+1][mx] = 1;
            createmap(a, n, m, ny + 1, mx, b, constant);
        }
        if ((mx < m - 1) && (b[ny][mx+1] == 0) && (constant + 1 >= a[ny][mx+1])) {
            b[ny][mx+1] = 1;
            createmap(a, n, m, ny, mx + 1, b, constant);
        }
        //printnicearray(b, n, m);
        return b;
    }
    else {
        if ((ny > 0) && (b[ny - 1][mx] == 0) && (constant + 1 >= a[ny - 1][mx])) { 
            b[ny - 1][mx] = 1;
            createmap(a, n, m, ny - 1, mx, b, constant);
        }
        if ((mx > 0) && (b[ny][mx - 1] == 0) && (constant + 1 >= a[ny][mx - 1])) {
            b[ny][mx - 1] = 1;
            createmap(a, n, m, ny, mx-1, b, constant);
        }
        if ((ny < n - 1) && (b[ny + 1][mx] == 0) && (constant + 1 >= a[ny + 1][mx])) {
            b[ny + 1][mx] = 1;
            createmap(a, n, m, ny + 1, mx, b, constant);
        }
        if ((mx < m - 1) && (b[ny][mx + 1] == 0) && (constant + 1 >= a[ny][mx + 1])) {
            b[ny][mx + 1] = 1;
            createmap(a, n, m, ny, mx + 1, b, constant);
        }
    }
}

void waterfill(int** a, size_t n, size_t m, size_t ny = 0, size_t mx = 0, size_t skolko = -1) {
    int **b = createmap(a, n, m, ny, mx);
    const int z = a[ny][mx]+1;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if(b[i][j] == 1) a[i][j] = z;
        }
    }
    deletearray(b, n);
}

void water(int** a, size_t n, size_t m, size_t steps = 1, size_t ny = 0, size_t mx = 0) {
    for (int i = 0; i < steps; i++) {
        waterfill(a, n, m, ny, mx);
        //printnicearray(a, n, m);
    }
}

int main()
{
    int n=-1, m=-1, ny=-1, mx=-1, steps=-1;
    while ((ny < 0) || (mx < 0) || (ny >= n) || (mx >= m) || (steps < 0)) {
        std::cout << "Input area (n, m): " << std::endl;
        std::cin >> n >> m;
        std::cout << "Input coord of crane (y, x): " << std::endl;
        std::cin >> ny >> mx;
        std::cout << "Input number of steps: " << std::endl;
        std::cin >> steps;
    }
    std::cout << std::endl;
    int** terrain = createarraypls<int>(n, m);
    randomintarray(terrain, n, m, 10);
    std::cout << "Before flood: " << std::endl;
    printnicearray(terrain, n, m);
    water(terrain, n, m,steps,ny,mx);
    std::cout << "After flood: " << std::endl;
    printnicearray(terrain, n, m);
    deletearray<int>(terrain, n);
    return 0;
}
