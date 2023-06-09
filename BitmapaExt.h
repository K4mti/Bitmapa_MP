#ifndef BITMAPAEXT_H
#define BITMAPAEXT_H

#include "Bitmapa.h"
#include "LibExcp.h"
#include <iostream>


class BitmapaExt : public Bitmapa {
private:
	int rows{ 0 };
	int columns{ 0 };
	bool** map;
public:

	/*
	* Konstruktor, utowrzenie mapy rows x columns i domyslne ustawienie wszystkich wartosci na 0
	* @param rows - liczba wierszy w mapie
	* @param columns - liczb kolumn w mapie
	*/
	BitmapaExt(int rows, int columns);

	/*
	* Konstruktor domyslny
	* Oddelegowywuje do konstruktora dwuargumentowego
	*/
	BitmapaExt() : BitmapaExt(0, 0) {}

	//Getters

	/*
	* Zwraca liczbe wierszy
	* @return Liczba wierszy
	*/
	unsigned length() const;

	/*
	* Zwraca liczbe kolumn
	* @return Liczba kolumn
	*/
	unsigned width() const;

	/*
	* Przeciazenie operatora()
	* @param x - indeks wiersza
	* @param y - indeks kolumny
	* @return Zwraca referencje do wartosci w polu (x, y)
	*/
	bool& operator()(unsigned int x, unsigned int y);

	/*
	* Przeciazenie operatora()
	* @param x - indeks wiersza
	* @param y - indeks kolumny
	* @return Zwraca wartosc w polu (x, y)
	*/
	bool operator()(unsigned int x, unsigned int y) const;

	/*
	* Przeciazenie operatora<<
	* @param os - referencja do obiektu ostream
	* @param map - referencja do obiektu BitmapaExt
	*/
	friend std::ostream& operator<<(std::ostream& os, const BitmapaExt& map);
};

#endif