#include "Traveler.h"

Traveler::~Traveler()
{
	for (int i = 0; i < n; i++)
	{
		delete[] cities[i];
		delete[] cities2[i];
	}
	delete[] cities;
	delete[] cities2;
	delete[] help;
	delete[] help2;
}
Traveler::Traveler(int n)
{
	this->n = n;
	cities = new int*[n];
	for (int i = 0; i < n; i++)
	{
		cities[i] = new int[n];
	}
}

void Traveler::LoadCities()
{
	int m = 0;
	int j = 0, i=0;
	for (i = 0; i < n; i++)
	{
		cities[i][0] = h;
		h++;
	}
	i = 0;
	h = 0;
	for (j = 0; j < n; j++)
	{
		cities[0][j] = h;
		h++;
	}
	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (i == j)cities[i][j] = 999;
			else
			{
				cities[i][j] = rand()%20;
			}
		}
	}
	DisplayCities(cities, n);
}

void Traveler::DisplayCities(int ** cities , int n)
{
//	system("cls");
	cout << endl << "Macierz miast:";
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			cout.width(5);  cout << cities[i][j];
		}
	}
}

void Traveler::FindMin()
{
	int loop = n - 2, i = 0, j=0;
	help = new int[n];
	help2= new int[n];

		k = 0;
		for (i = 1; i < n; i++)
		{
			min = cities[i][1];
			for (j = 1; j < n; j++)
			{
				if (cities[i][j] <= min && cities[i][j] < 900)
					min = cities[i][j];
			}
		help[k] = min;
		k++;
	}
	k = 0;

	for (i = 1; i < n; i++)
	{
		for (j = 1; j < n; j++)
		{
			if (cities[i][j] < 900) cities[i][j] = cities[i][j] - help[k];
		}
		k++;
	}
	//*********************************************
	h = 0;
	for (j = 1; j < n; j++)
	{
		min = cities[1][j];
		for (i = 1; i < n; i++)
		{
			if (cities[i][j] <= min && cities[i][j] < 900)
				min = cities[i][j];
		}
		help2[h] = min;
		h++;
	}
	h = 0;
	for (j = 1; j < n; j++)
	{
		for (i = 1; i < n; i++)
		{
			if (cities[i][j] < 900) cities[i][j] = cities[i][j] - help2[h];
		}
		h++;
	}

	DisplayMin();
	DisplayCities(cities, n);
}

void Traveler::FindMin2()
{
	int i, j;
	if (n > 3)
	{
		int zeroNumber = 0;
		if (help && help2)
		{
			delete[] help;
			delete[] help2;
		}
		help = new int[n];
		help2 = new int[n];
		//szukamy w wierszach
		k = 0;
		for (i = 1; i < n; i++)
		{
			min = 999;
			for (j = 1; j < n; j++)
			{
				if (cities[i][j] == 0) zeroNumber++;
				if (zeroNumber >= 2) min = 0;
				else
				{
					if (cities[i][j] <= min && cities[i][j] >0 && cities[i][j] < 900)
						min = cities[i][j];
				}
				help[k] = min;
			}
			k++;
			zeroNumber = 0;
		}
		//szukamy w kolumnach

		k = 0;
		for (j = 1; j < n; j++)
		{
			min = 999;
			for (i = 1; i < n; i++)
			{
				if (cities[i][j] == 0) zeroNumber++;
				if (zeroNumber >= 2) min = 0;
				else
				{
					if (cities[i][j] <= min && cities[i][j] >0 && cities[i][j] < 900)
						min = cities[i][j];
				}
				help2[k] = min;
			}	
			k++;
			zeroNumber = 0;
		}
		DisplayMin();
	}
}
void Traveler::FindMaxMin()
{
	int i = 0;
	maxminW = help[0];
	for (k = 1; k < n; k++)
	{
		if (help[i] > maxminW)
		{
			maxminW = help[i];
			szuki = k;
		}
		i++;
	}
	i = 0;
	maxminK = help2[0];
	for (k = 1; k < n; k++)
	{
		if (help2[i] > maxminK)
		{
			maxminK = help2[i];
			szukj = k;
		}
		i++;
	}

	cout << endl << "Najwieksze min z W: " << maxminW << endl;
	cout << endl << "Najwieksze min z K: " << maxminK << endl;
}

void Traveler::FindZero()
{

	for (int j = 1; j<n; j++)
		if (cities[szuki][j] == 0)
		{
			indj = j;
		}

	cout << endl << "wartosc zera: " << max << " dla indexow: i=" << szuki << " j=" << indj << endl;
}

void Traveler::FindInd()
{

	max = 0;
	if (maxminK<maxminW)
	{
		max = maxminW;
	}
	else
	{
		max = maxminK;
	}
	if (max == maxminW)
	{
		for (int j = 1; j<n; j++)
			if (cities[szuki][j] == max)
			{
				indi = szuki;
				indj = j;
			}
	}
	else
		if (max == maxminK)
		{
			for (int i = 1; i<n; i++)
				if (cities[i][szukj] == max)
				{
					indi = i;
					indj = szukj;
				}
		}
	cout << endl << "maks wartosc: " << max << " dla indexow: i=" << indi << " j=" << indj << endl;
}

void Traveler::RemoveRC()
{
	n2 = n -1;
	cities2 = new int*[n2];
	for (int i = 0; i < n2; i++)
	{
		cities2[i] = new int[n2];
	}

	h = 0;
	for (int i = 0; i < n2; i++)
	{
		cities2[i][0] = h;
		h++;
	}

	h = 0;
	for (int j = 0; j < n2; j++)
	{
		cities2[0][j] = h;
		h++;
	}

	int p = 1;
	int o = 1;
	for (int i = 1; i < n; i++)
	{
		if (i == indi)
			i++;
		
		for (int j = 1; j < n; j++)
		{
			if (j == indj)
				j++;
			
			cities2[p][o] = cities[i][j];
			o++;
		}
		p++;
	}
	DisplayCities(cities2, n2);
}

void Traveler::DisplayMin()
{
	cout << endl << endl;
	cout << "Najmniejsze elementy z wierszy:";
	for (h = 0; h < n - 1; h++)
	{
		cout.width(3); cout << help[h];
	}
	cout << endl << endl;
	cout << "Najmniejsze elementy z kolumn:";
	for (h = 0; h < n-1; h++)
	{
		cout.width(3);  cout << help2[h];
	} 
	cout << endl;
}

void Traveler::SumLowerBound()
{
	for (int i = 0; i < n - 1; i++)
	{
		LB += help[i];
		LB += help2[i];
	}
}



