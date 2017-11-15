#pragma once
#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

class Traveler
{
public:
	int n, n2;
	int maxminW, maxminK; // maksymalne minima

		// póki co nie sysematyzowane, jeœli >1 to wybrany ostatni(?)
	int	szuki, // [+1] - index w help - najwiêkszy z minimów w wierszach
		szukj; // [+1] - index w help2 - najwiêkszy z minimów w kolumnach

	int indi, // indeks zera (wiersz) jesli maxmin w kolumnach, inaczej 0
		indj; // indeks zera (kolumna) jesli maxmin w wierszy, inaczej 0

	int **cities, **cities2, **cities3, *help, *help2;
	int LB;
	int *path, counter, *fPath, *reservePath;

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
	void Run();
	void RecursiveRun();
	void RecursiveRunZero();
	void LoadFromFile();
	Traveler(int n);
	Traveler(int n, int n2, int maxminW, int maxminK, int szuki, int szukj, int indi, int indj, int counter, int ** cities, int * help, int * help2, int * path, int LB);
	~Traveler();
};