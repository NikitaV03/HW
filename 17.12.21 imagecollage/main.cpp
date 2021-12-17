// 06.12.21.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

int** createarraypls(size_t rows, size_t cols) {
	int** arr = new int * [rows];
	for (int k = 0; k < rows; ++k) {
		arr[k] = new int[cols];
	}
	return arr;
}

void perevorot(int** matrix, size_t n, size_t m) {
	for (int i = 0; i < n / 2; ++i)
		for (int j = 0; j < m; ++j) {
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n - i - 1][j];
			matrix[n - i - 1][j] = tmp;
		}
}

void vertperevorot(int** matrix, size_t n, size_t m) {
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m/2; ++j) {
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[i][m - j - 1];
			matrix[i][m - j - 1] = tmp;
		}
}


void diagonalperevorot(int** matrix, size_t n, size_t m) {
	for (int i = 0; i < n / 2; ++i)
		for (int j = 0; j < m; ++j) {
			int tmp = matrix[i][j];
			matrix[i][j] = matrix[n - i - 1][m - j - 1];
			matrix[n - i - 1][m - j - 1] = tmp;
		}
	if (n % 2 == 1) for (int j = 0; j <= m / 2 ; ++j) {
		int tmp = matrix[n / 2][j];
		matrix[n / 2][j] = matrix[n / 2][m - j - 1];
		matrix[n / 2][m - j - 1] = tmp;
	}
}

void deletearray (int** a, size_t n) {
	for (int i = 0; i < n; ++i) {
		delete[] a[i];
	}
	delete[] a;
}

void printnicearray(int* a[], size_t n, size_t m, size_t symb = 3) {
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


// 1.1 Считывает данные о пикселях в массив и возвращает список.
int** getdata(const char* filename){ 
	size_t row=1;
	size_t col=0;
	size_t width;
	size_t height;
	int** arr;
	std::ifstream inpic(filename, std::ios::in | std::ios::binary);
	if (!inpic.is_open()) {
		arr = createarraypls(1, 1);
		std::cout << " whoops... Something went wrong " << std::endl;
	}
	else {
		inpic.seekg(18);
		inpic.read((char*)&width, sizeof(int));
		inpic.read((char*)&height, sizeof(int));
		int actualwidth;
		if (width % 32 != 0)actualwidth = width + (32 - (width % 32));
		else actualwidth = width;
		arr = createarraypls(height, width);
		int bdoffbits = 0;
		inpic.seekg(10);
		inpic.read((char*)&bdoffbits, sizeof(int)); // Где находится информация о пикселях.
		inpic.seekg(bdoffbits); 
		int ch = 0; // переменная, считывающая пискели по байтам.
		int arrheight = 0;
		int arrwidth = 0;
		while (inpic.peek() != EOF) { //считываем пиксели до конца файла.
			inpic.read((char*)&ch, 1);
			for (int i = 128; i > 0; i /= 2) {
				if (arrwidth + 1 <= width){
					arr[arrheight][arrwidth] = 1 - (i & ch) / i;
				}
				arrwidth++;
			}
			if (arrwidth == actualwidth) {
				arrheight++;
				arrwidth = 0; // переход на следующую строку
			}
		}
		inpic.close();
	}
	return arr;
}

// 1.2 Возвращает ширину и высоту картинки.
int* getwh(const char* filename) {
	int wh[2];
	size_t width;
	size_t height;
	std::ifstream inpic(filename, std::ios::in | std::ios::binary);
	if (!inpic.is_open()) {
		wh[0] = -1;
		wh[1] = -1;
		std::cout << " whoops... Something went wrong " << std::endl;
	}
	else {
		inpic.seekg(18);
		inpic.read((char*)&width, sizeof(int));
		inpic.read((char*)&height, sizeof(int));
		wh[0] = width;
		wh[1] = height;
		inpic.close();
	}
	return wh;
}

// 2. Меняет значения в одном массиве на значения из другого, начиная с определенной точки.
void replacepixels(int** main, size_t rowsm, size_t colsm, int** input, size_t rowsi, size_t colsi, size_t dotrow = 0, size_t dotcol = 0) {
	if ((dotrow < rowsm) && (dotcol < colsm)) {
		for (int i = 0; i < rowsi; ++i) {
			for (int j = 0; j < colsi; ++j) {
				if ((dotrow + i < rowsm) && (dotcol + j < colsm)) {
					main[dotrow + i][dotcol + j] = input[i][j];
				}
			}
		}
	}
	else {
		std::cout << "cant write here" << std::endl;
	}
}

// 3. Записывает массив в файл
void newbmpfromold(const char* oldname, const char* newname, int** arr, size_t height, size_t width) {
	std::ifstream inpic(oldname, std::ios::in | std::ios::binary);
	if (!inpic.is_open()) {
		std::cout << " whoops... Something went wrong " << std::endl;
	}
	else {
		std::ofstream outpic(newname, std::ios::out | std::ios::binary);
		if (!outpic.is_open()) {
			std::cout << " whoops... Something went wrong " << std::endl;
			inpic.close();
		}
		else {
			int bdoffbits = 0;
			int widthcount;
			char x;
			inpic.seekg(10);
			inpic.read((char*)&bdoffbits, sizeof(int)); // Где находится информация о пикселях.
			inpic.seekg(0);
			for (int i = 0; i < bdoffbits; ++i) {
				inpic.read((char*)&x, sizeof(char));
				outpic.write((char*)&x, sizeof(char));
			}
			size_t row = 0;
			while (inpic.peek() != EOF) {
				std::string onerow = "";
				// записываем в строку одну строчку массива
				for (int i = 0; i<width;++i){
					if (arr[row][i]) onerow.push_back('0');
					else onerow.push_back('1');
				}
				// записываем в файл побайтово строчку
				for (int i = 0; i < width / 8; ++i) {
					char x = 0;
					for (int j = 0; j < 8; ++j) {
						x += (int)(onerow[i * 8 + j] - '0') * pow(2, 7 - j);
					}
					outpic.write((char*)&x, sizeof(char));
				}
				inpic.seekg((width / 8), std::ios::cur);
				row++;
			}
			inpic.close();
			outpic.close();
		}
	}
}

int** normalizearray(int** main, size_t height, size_t width) {
	int** nicearray;
	if (width % 32 == 0) nicearray = main;
	else {
		size_t newwidth = width + (32 - (width % 32));
		nicearray = createarraypls(height, newwidth);
		for (int i = 0; i < height; ++i) {
			for (int j = 0; j < newwidth; ++j) {
				if (j < width) {
					nicearray[i][j] = main[i][j];
				}
				else {
					nicearray[i][j] = 0;
				}
			}
		}
	}
	return nicearray;
}

int main() {	
	// первая картинка (меньшая)
	const char* filename = "star.bmp";
	int* widthheight = getwh(filename);
	int width = widthheight[0];
	int height = widthheight[1];
	int** pixels = getdata(filename);
	perevorot(pixels, height, width);

	//вторая картинка (большая)
	const char* filename2 = "emptysky.bmp";
	int* widthheight2 = getwh(filename2);
	int width2 = widthheight2[0];
	int height2 = widthheight2[1];
	int** pixels2 = getdata(filename2);
	diagonalperevorot(pixels2,height2,width2);
	vertperevorot(pixels2, height2, width2);

	//вставляем первую картинку во вторую
	replacepixels(pixels2, height2, width2, pixels, height, width, 0, 44);
	replacepixels(pixels2, height2, width2, pixels, height, width, 15, 27);
	replacepixels(pixels2, height2, width2, pixels, height, width, 6, 11);
	replacepixels(pixels2, height2, width2, pixels, height, width, 40, 35);
	replacepixels(pixels2, height2, width2, pixels, height, width, 48, 6);

	//создаем массив из старого с шириной % 32 = 0 и заполняем 0 пустую часть
	int** finalpixels = normalizearray(pixels2, height2, width2);
	size_t finalwidth = width2 + (32 - (width2 % 32));
	vertperevorot(finalpixels, height2, finalwidth);

	//записываем второй массив в файл
	diagonalperevorot(finalpixels, height2, finalwidth);
	newbmpfromold(filename2, "mychel.bmp", finalpixels, height2, finalwidth);


	deletearray(pixels, height);
	deletearray(pixels2, height2);
	deletearray(finalpixels, height2);
	return 0;
}
