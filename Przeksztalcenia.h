#ifndef PRZEKSZTALCENIA_H
#define PRZEKSZTALCENIA_H

#include "Bitmapa.h"
#include "BitmapaExt.h"
#include <vector>

/*
* Abstrakcyjna klasa s�u��ca do dziedziczenia dla poszczeg�lnych przekszta�ce�
*/
class Przeksztalcenie
{
public:
	/*
	* Wirtualna funkcja do przekszta�cania bitmapy
	*/
	virtual void przeksztalc(Bitmapa&) = 0;
};


/*
* Poszczeg�lne przekszta�cenia ------------------------------------------------------------------------------------------
*/

/*
* Przekszta�ecnie Inwersja
*/
class Inwersja : public Przeksztalcenie
{
public:
	/*
	* Konstruktor domy�lny
	*/
	Inwersja() = default;

	/*
	* Przes�oni�cie funkcji przekszta��
	* @param referencja do obiektu typu Bitmapa
	*/
	void przeksztalc(Bitmapa&) override;
};

/*
* Przekszta�ecnie Erozja
*/
class Erozja : public Przeksztalcenie
{
public:
	/*
	* Konstruktor domy�lny
	*/
	Erozja() = default;

	/*
	* Przes�oni�cie funkcji przekszta��
	* @param referencja do obiektu typu Bitmapa
	*/
	void przeksztalc(Bitmapa&) override;
};

/*
* Przekszta�ecnie Dylatacja
*/
class Dylatacja : public Przeksztalcenie
{
public:
	/*
	* Konstruktor domy�lny
	*/
	Dylatacja() = default;

	/*
	* Przes�oni�cie funkcji przekszta��
	* @param referencja do obiektu typu Bitmapa
	*/
	void przeksztalc(Bitmapa&) override;
};

/*
* Przekszta�ecnie Zerowanie
*/
class Zerowanie : public Przeksztalcenie
{
public:
	/*
	* Konstruktor domy�lny
	*/
	Zerowanie() = default;

	/*
	* Przes�oni�cie funkcji przekszta��
	* @param referencja do obiektu typu Bitmapa
	*/
	void przeksztalc(Bitmapa&) override;
};

/*
* Przekszta�ecnie Usrednienie
*/
class Usrednienie : public Przeksztalcenie
{
public:
	/*
	* Konstruktor domy�lny
	*/
	Usrednienie() = default;

	/*
	* Przes�oni�cie funkcji przekszta��
	* @param referencja do obiektu typu Bitmapa
	*/
	void przeksztalc(Bitmapa&) override;
};


/*
* ----------------------------------------------------------------------------------------------------------------------------
*/

/*
* Z�o�enie przekszta�cen
*/
class ZlozeniePrzeksztalcen : public Przeksztalcenie 
{
private:
	std::vector<Przeksztalcenie*> przeksztalcenia;	//wektor wska�nik�w na obiekty typu przekszta�cenie
public:
	/*
	* Konstruktor domy�lny
	*/
	ZlozeniePrzeksztalcen() = default;

	/*
	* Wykonanie przekszta�ce�
	* @param referencja do obiekt typu bitmapaExt
	*/
	void przeksztalc(Bitmapa&);

	/*
	* Dodanie kolejnych przekszta�ce� do "listy"
	* @param wska�nik na obiekt typu przeksztalcenie
	*/
	void dodajPrzeksztalcenie(Przeksztalcenie*);
};

#endif
