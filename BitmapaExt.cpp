#include "BitmapaExt.h"

BitmapaExt::BitmapaExt(int rows, int columns) {

	this->rows = rows;
	this->columns = columns;
	this->map = new bool* [this->rows];
	for (int i = 0; i < this->rows; i++) {
		this->map[i] = new bool[columns];
		for (int j = 0; j < columns; j++) {
			this->map[i][j] = false;
		}
	}
}

unsigned BitmapaExt::length() const{
	return this->rows;
}

unsigned BitmapaExt::width() const{
	return this->columns;
}

bool& BitmapaExt::operator()(unsigned int x, unsigned int y){
	return this->map[x][y];
}

bool BitmapaExt::operator()(unsigned int x, unsigned int y) const{
	return this->map[x][y];
}

std::ostream& operator<<(std::ostream& os, const BitmapaExt& map){
	for (int i = 0; i < map.length(); i++) {
		for (int j = 0; j < map.width(); j++) {
			if (map(i, j) == false) os << "O ";
			else os << "X ";
		}
		os << "\n";
	}
	return os;
}
