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

void Erozja::przeksztalc(Bitmapa& map){

	//kontener par
	std::vector < std::pair<int, int>> pairs;

	//para wspolrzednych do zmiany
	std::pair<int, int> toChange;

	//liczba wierszy
	int length = map.length();
	//liczba kolumn
	int width = map.width();

	//liczba sasiadow bialych
	int whiteCells = 0;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {


			if (map (i, j) == true && i > 0 && map(i - 1, j) == false) whiteCells++;
			else if (map(i, j) == true && j > 0 && map(i, j - 1) == false) whiteCells++;
			else if (map(i, j) == true && j < width - 1 && map(i, j + 1) == false) whiteCells++;
			else if (map(i, j) == true && i < length - 1 && map(i + 1, j) == false) whiteCells++;

			if (whiteCells != 0) {
				toChange.first = i;
				toChange.second = j;
				pairs.push_back(toChange);
			}

			whiteCells = 0;
		}
	}
	
	for (int i = 0; i < pairs.size(); i++) {
		map(pairs[i].first, pairs[i].second) = false;
	}
}
