#include "Przeksztalcenia.h"

void ZlozeniePrzeksztalcen::przeksztalc(Bitmapa& mapa)
{
	//wykonywanie przekszta³ceñ od koñca wektora (chronologiczne dodanie przekszta³cen)
	for (int i = 0; i <przeksztalcenia.size(); i++) {
		this->przeksztalcenia.at(i)->przeksztalc(mapa);
	}
}

void ZlozeniePrzeksztalcen::dodajPrzeksztalcenie(Przeksztalcenie* p)
{
	this->przeksztalcenia.push_back(p);	//dodanie wskaznika na obiekt typu przeksztalcenie do wektora zawieraj¹cego liste przekszta³cen
}

void Inwersja::przeksztalc(Bitmapa& mapa)
{
	//liczba wierszy
	int length = mapa.length();
	//liczba kolumn
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

void Dylatacja::przeksztalc(Bitmapa& map){

	//kontener par
	std::vector < std::pair<int, int>> pairs;

	//para wspolrzednych do zmiany
	std::pair<int, int> toChange;

	//liczba wierszy
	int length = map.length();
	//liczba kolumn
	int width = map.width();

	//liczba sasiadow czarnych
	int blackCells = 0;

	for (int i = 0; i < length; i++) {
		for (int j = 0; j < width; j++) {


			if (map(i, j) == false && i > 0 && map(i - 1, j) == true) blackCells++;
			else if (map(i, j) == false && j > 0 && map(i, j - 1) == true) blackCells++;
			else if (map(i, j) == false && j < width - 1 && map(i, j + 1) == true) blackCells++;
			else if (map(i, j) == false && i < length - 1 && map(i + 1, j) == true) blackCells++;

			if (blackCells != 0) {
				toChange.first = i;
				toChange.second = j;
				pairs.push_back(toChange);
			}

			blackCells = 0;
		}
	}

	for (int i = 0; i < pairs.size(); i++) {
		map(pairs[i].first, pairs[i].second) = true;
	}
}

void Zerowanie::przeksztalc(Bitmapa& mapa)
{
	//liczba wierszy
	int length = mapa.length();
	//liczba kolumn
	int width = mapa.width();

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			mapa(i, j) = false;
		}
	}
}

void Usrednienie::przeksztalc(Bitmapa& mapa)
{
	//liczba wierszy
	int length = mapa.length();
	//liczba kolumn
	int width = mapa.width();

	//liczba sasiadow czarnych
	int white = 0;
	//liczba sasiadow bia³ych
	int black = 0;

	std::vector<bool> color;

	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < width; j++)
		{
			white = 0;
			black = 0;

			if(i != 0)	//jesli ma s¹siadów z góry
			{
				if (mapa(i - 1, j)) { black++; }
				else { white++; }
			}
			if (i != length - 1) //jesli ma s¹siadów z do³u
			{
				if (mapa(i + 1, j)) { black++; }
				else { white++; }
			}
			if (j != 0)	//jesli ma s¹siadów z lewej
			{
				if (mapa(i, j-1)) { black++; }
				else { white++; }
			}
			if (j != width - 1)	//jesli ma s¹siadów z prawej 
			{
				if (mapa(i, j + 1)) { black++; }
				else { white++; }
			}

			if (white > 2) { color.push_back(false); }
			else if (black > 2) { color.push_back(true); }
			else { color.push_back(mapa(i, j)); }
		}
	}

	for (int i = length-1; i >=0 ; i--)
	{
		for (int j = width-1; j >= 0; j--)
		{
			mapa(i, j) = color.back();
			color.pop_back();
		}
	}
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
