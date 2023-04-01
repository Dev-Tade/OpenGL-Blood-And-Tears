#include "Auxiliary.hpp"

#include <iostream>
#include <fstream>
#include <vector>

namespace AUX {
	
	string readShaderFile(string filePath) {
		string str;
		FILE* fp = fopen(filePath.c_str(), "r");
		if (fp != NULL) {
			int c;
			while ((c = fgetc(fp)) != EOF) {
				str += c;
			}
			return str;
		} else {
			std::cout << "ERROR::FILE::READ -> " << filePath << std::endl;
			exit(-1);
		}
	}
}