#include "Przeksztalcenia.h"

void ZlozeniePrzeksztalcen::przeksztalc(Bitmapa& mapa)
{
	/*
	this->result = mapa;
	//wykonywanie przekszta³ceñ od koñca wektora (chronologiczne dodanie przekszta³cen)
	for (int i = this->przeksztalcenia.size() - 1; i >= 0; i--) {
		this->przeksztalcenia.at(i)->przeksztalc(this->result);
	}
	*/
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
	int length = mapa.length();
	int width = mapa.width();

	int white = 0;
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
