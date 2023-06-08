#ifndef LIBEXCP_H
#define LIBEXCP_H

#include <fstream>
#include<exception>
#include <string>

namespace MyRuntimeExceptions {
	class FileOpenException : public std::runtime_error {
	public:
		FileOpenException() : runtime_error("Nie mozna otworzyc pliku") {
		}
		FileOpenException(std::string msg) : runtime_error(msg.c_str()) {
		}
	};
}

namespace MylogicExceptions {
	class OutOfRange : public std::runtime_error {
	public:
		OutOfRange() : runtime_error("B³ad zakresu") {}
		OutOfRange(std::string msg) : runtime_error(msg.c_str()) {}
	};
}

#endif 

