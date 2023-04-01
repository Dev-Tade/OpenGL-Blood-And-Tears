#ifndef AUX_HPP
#define AUX_HPP

#include <string>
using std::string;

#include <glad/glad.h>

#define ARRSIZE(arr) (sizeof(arr)/sizeof(arr[0]))

namespace AUX {
	string readShaderFile(string filePath);
	
}

#endif // !AUX_H
