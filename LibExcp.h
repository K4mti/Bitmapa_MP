#ifndef LIBEXCP_H
#define LIBEXCP_H

#include <fstream>
#include<exception>
#include <string>

namespace MylogicExceptions {
	class OutOfRange : public std::runtime_error {
	public:
		OutOfRange() : runtime_error("B�ad zakresu") {}
		OutOfRange(std::string msg) : runtime_error(msg.c_str()) {}
	};

	class InvalidArgument : public std::invalid_argument {
	public:
		InvalidArgument() : invalid_argument("B��dny argument"){}
		InvalidArgument(std::string msg) : invalid_argument(msg.c_str()){}
	};
}

#endif 

