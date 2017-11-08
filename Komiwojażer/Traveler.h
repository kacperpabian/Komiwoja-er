#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>

using namespace std;

class Traveler
{
public:
	int n, n2, min, k = 0, sum = 0, h = 0;
	int max = 0, maxminW = 0, maxminK = 0,
		szuki = 1, szukj = 1;
	int indi = 0, indj = 0;
	int **cities, **cities2, **cities3, *help, *help2;
	int LB;

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
	Traveler(int n);
	~Traveler();
};