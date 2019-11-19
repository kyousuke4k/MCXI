//MCXI
#include<iostream>
#include<fstream>
#include<string>

class MCXI {
private:
public:
};

int main(void) {
	//txtinclude
	std::ifstream inputfile("input.txt");
	char MCXI[256];
	if (inputfile.fail()) {
		std::cerr << "input-error" << std::endl;
		return -1;
	}

	while (inputfile.getline(MCXI, 256 - 1)) {
		std::cout << MCXI << std::endl;
	}
	return 0;
}