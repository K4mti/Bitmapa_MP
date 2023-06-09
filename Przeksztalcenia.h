#ifndef PRZEKSZTALCENIA_H
#define PRZEKSZTALCENIA_H

#include "Bitmapa.h"
#include "BitmapaExt.h"
#include "LibExcp.h"
#include <exception>
#include <vector>

/*
* Abstrakcyjna klasa s³u¿¹ca do dziedziczenia dla poszczególnych przekszta³ceñ
*/
template<typename T>
class Przeksztalcenie
{
public:
	/*
	* Wirtualna funkcja do przekszta³cania bitmapy
	*/
	virtual T przeksztalc(Bitmapa&) = 0;
};


/*
* Poszczególne przekszta³cenia ------------------------------------------------------------------------------------------
*/

/*
* Przekszta³ecnie Inwersja
*/
class Inwersja : public Przeksztalcenie<void>
{
public:
	/*
	* Konstruktor domyœlny
	*/
	Inwersja() = default;
protected:

	/*
	* Przes³oniêcie funkcji przekszta³æ
	* @param referencja do obiektu typu Bitmapa
	*/
	void przeksztalc(Bitmapa&) override;
};

/*
* Przekszta³ecnie Erozja
*/
class Erozja : public Przeksztalcenie<void>
{
public:
	/*
	* Konstruktor domyœlny
	*/
	Erozja() = default;
protected:

	/*
	* Przes³oniêcie funkcji przekszta³æ
	* @param referencja do obiektu typu Bitmapa
	*/
	void przeksztalc(Bitmapa&) override;
};

/*
* Przekszta³ecnie Dylatacja
*/
class Dylatacja : public Przeksztalcenie<void>
{
public:
	/*
	* Konstruktor domyœlny
	*/
	Dylatacja() = default;
protected:

	/*
	* Przes³oniêcie funkcji przekszta³æ
	* @param referencja do obiektu typu Bitmapa
	*/
	void przeksztalc(Bitmapa&) override;
};

/*
* Przekszta³ecnie Zerowanie
*/
class Zerowanie : public Przeksztalcenie<void>
{
public:
	/*
	* Konstruktor domyœlny
	*/
	Zerowanie() = default;
protected:

	/*
	* Przes³oniêcie funkcji przekszta³æ
	* @param referencja do obiektu typu Bitmapa
	*/
	void przeksztalc(Bitmapa&) override;
};

/*
* Przekszta³ecnie Usrednienie
*/
class Usrednienie : public Przeksztalcenie<void>
{
public:
	/*
	* Konstruktor domyœlny
	*/
	Usrednienie() = default;
protected:

	/*
	* Przes³oniêcie funkcji przekszta³æ
	* @param referencja do obiektu typu Bitmapa
	*/
	void przeksztalc(Bitmapa&) override;
};


/*
* ----------------------------------------------------------------------------------------------------------------------------
*/

/*
* Z³o¿enie przekszta³cen
*/
class ZlozeniePrzeksztalcen : public Przeksztalcenie<void>
{
private:
	std::vector<Przeksztalcenie*> przeksztalcenia;	//wektor wskaŸników na obiekty typu przekszta³cenie

public:
	/*
	* Konstruktor domyœlny
	*/
	ZlozeniePrzeksztalcen() = default;

	/*
	* Wykonanie przekszta³ceñ
	* @param referencja do obiekt typu bitmapaExt
	*/
	void przeksztalc(Bitmapa&) override;

	/*
	* Dodanie kolejnych przekszta³ceñ do "listy"
	* @param wskaŸnik na obiekt typu przeksztalcenie
	*/
	void dodajPrzeksztalcenie(Przeksztalcenie*);
};

#endif
