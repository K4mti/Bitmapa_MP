#ifndef BITMAPA_H
#define BITMAPA_H

/*
* Abstrakcyjna klasa do dziedziczenia
*/
class Bitmapa
{
public:
	virtual unsigned length() const = 0;
	virtual unsigned width() const = 0;
	virtual bool& operator() (unsigned int x, unsigned int y) = 0;
	virtual bool operator() (unsigned int x, unsigned int y) const = 0;
	virtual ~Bitmapa() {}
};

#endif
