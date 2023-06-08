#include "Przeksztalcenia.h"

void ZlozeniePrzeksztalcen::przeksztalc(BitmapaExt& mapa)
{
	this->result = mapa;
	//wykonywanie przekszta³ceñ od koñca wektora (chronologiczne dodanie przekszta³cen)
	for (int i = this->przeksztalcenia.size() - 1; i >= 0; i--) {
		this->przeksztalcenia.at(i)->przeksztalc(this->result);
	}
}

void ZlozeniePrzeksztalcen::dodajPrzeksztalcenie(Przeksztalcenie* p)
{
	this->przeksztalcenia.push_back(p);	//dodanie wskaznika na obiekt typu przeksztalcenie do wektora zawieraj¹cego liste przekszta³cen
}

void Inwersja::przeksztalc(Bitmapa& mapa)
{
	int length = mapa.length();
	int width = mapa.width();

	for (int i = 0; i < length; i++) 
	{
		for (int j = 0; j < width; j++)
		{
			if (mapa(i, j)) { mapa(i, j) = false;}
			else { mapa(i, j) = true; }
		}
	}
}

void Dylatacja::przeksztalc(Bitmapa& mapa)
{

}

void Zerowanie::przeksztalc(Bitmapa& mapa)
{
	int length = mapa.length();
	int width = mapa.width();
}
