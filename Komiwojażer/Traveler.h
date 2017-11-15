#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>

using namespace std;

class Traveler
{
public:
	int n, n2;
	int maxminW = 0, maxminK = 0; // maksymalne minima

		// póki co nie sysematyzowane, jeœli >1 to wybrany ostatni(?)
	int	szuki = 1, // [+1] - index w help - najwiêkszy z minimów w wierszach
		szukj = 1; // [+1] - index w help2 - najwiêkszy z minimów w kolumnach

	int indi = 0, // indeks zera (wiersz) jesli maxmin w kolumnach, inaczej 0
		indj = 0; // indeks zera (kolumna) jesli maxmin w wierszy, inaczej 0

	int **cities, **cities2, **cities3, *help, *help2;
	int LB;
	int *path, counter, *finalPath, *reservePath;

	void LoadCities();
	void DisplayCities(int** cities, int n);
	void FindMin();
	void DisplayMin();
	void SumLowerBound();
	void FindMin2();
	void FindMaxMin();
	void FindInd();
	void FindZero();
	void RemoveRC();
	void InitCities2();
	void Reset();
	void End();
	void DisplayPath(int* path);
	void SortPath(int* path);
	void FindLastPath();
	Traveler(int n);
	~Traveler();
};