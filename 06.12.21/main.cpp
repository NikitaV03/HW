#include <iostream>
#include <fstream>

int main()
{
	// get width&height
	std::ifstream inpic("paint.bmp", std::ios::in | std::ios::binary);
	if (!inpic.is_open()) {
		std::cout << " whoops... Something went wrong " << std::endl;
	}
	else {
		inpic.seekg(18);
		int iwidth = 0, iheight = 0;
		std::cout << (int)inpic.tellg() << std::endl;
		inpic.read((char*)&iwidth, sizeof(int));
		inpic.read((char*)&iheight, sizeof(int));
		std::cout << " width: " << iwidth << " height: " << iheight << std::endl;
		
		//replace w&h and write new pic
		std::ofstream outpic("tnaip.bmp", std::ios::out | std::ios::binary);
		if (!outpic.is_open()) {
			std::cout << " whoops... Something went wrong " << std::endl;
		}
		else {
			inpic.seekg(0);
			int x = 0;
			while (inpic.peek() != EOF) {
				if ((int)inpic.tellg() == 16) {
					std::cout << "im here" << std::endl;
					inpic.read((char*)&x, sizeof(char));
					outpic.write((char*)&x	, sizeof(char));
					inpic.read((char*)&x, sizeof(char));
					outpic.write((char*)&x, sizeof(char));
					inpic.read((char*)&x, sizeof(int));
					outpic.write((char*)&iheight, sizeof(int));
					std::cout << x << " " << int(iheight) << " " << iwidth << std::endl;
					inpic.read((char*)&x, sizeof(int));
					outpic.write((char*)&iwidth, sizeof(int));
					std::cout << x << " " << int(iheight) << " " << iwidth << " " << (int)inpic.tellg() << std::endl;
					inpic.read((char*)&x, sizeof(char));
					outpic.write((char*)&x, sizeof(char));
					inpic.read((char*)&x, sizeof(char));
					outpic.write((char*)&x, sizeof(char));
				}
				else {
					inpic.read((char*)&x, sizeof(int));
					outpic.write((char*)&x, sizeof(int));
				}
			}
			outpic.close();
		}
		inpic.close();
	}


	return 0;
}
