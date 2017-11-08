#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>

using namespace std;

class Traveler
{
public: 
	int i, j, n, min, k = 0, sum = 0, h = 0;
	int max = 0, maxminW = 0, maxminK = 0, szuki = 0, szukj = 0;
	int** cities, *help, *help2;
	int LB;

	int** LoadCities();
	void DisplayCities();
	void FindMin();
	void DisplayMin();
	void SumLowerBound();
	void FindMin2();
	void FindMaxMin();
	void FindInd();
	Traveler(int** cities, int n);
	~Traveler();
};
