#include <iostream>
#include <fstream>
int main()
{
	std::ifstream inpic("examplechel.bmp", std::ios::in | std::ios::binary);
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
		//read pixel/byte
		inpic.seekg(28);
		int pix = 1;
		inpic.read((char*)&pix, 4);
		//read bdOffBits
		int bdoffbits = 0;
		inpic.seekg(10);
		inpic.read((char*)&bdoffbits, sizeof(int));
		std::cout << bdoffbits << std::endl;
		//cout pixels
		inpic.seekg(bdoffbits);
		int ch = 0;
		int ct = 0;
		int w = 1;
		std::cout << pix << std::endl;
		while (inpic.peek() != EOF) {
			inpic.read((char*)&ch, 1);
			for (int i = 128; i > 0 ; i /= 2) {
				if ((w > iwidth) && (iwidth % 32 != 0)) {
					w = 1;
					std::cout << " " << ++ct << std::endl;
					inpic.seekg((int)inpic.tellg() + (3 - (iwidth % 32) / 8));
					break;
				}
				else if ((w > iwidth) && (iwidth % 32 == 0)) {
					w= 1;
					std::cout << " " << ++ct << std::endl;
				}
				++w;
				std::cout << (i & ch) / i;
			}
		}
		inpic.close();
	}
	return 0;
}

