#include "Traveler.h"

Traveler::~Traveler()
{
	for (int i = 0; i < n; i++)
	{
		delete[] cities[i];
	}
	delete[] cities;
	delete[] help;
	delete[] help2;
}
Traveler::Traveler(int **cities, int n)
{
	this->cities = cities;
	this->n = n;

}

int** Traveler::LoadCities()
{
	int m = 0;
	j = 0;
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
	return cities;
}

void Traveler::DisplayCities()
{
//	system("cls");
	cout << endl << "Macierz miast:";
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (j = 0; j < n; j++)
		{
			cout.width(5);  cout << cities[i][j];
		}
	}
}

void Traveler::FindMin()
{
	int loop = n - 2;
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
}

void Traveler::FindMin2()
{
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
	maxminW = help[1];
	for (k = 1; k < n; k++)
	{
		if (help[k] > maxminW)
		{
			maxminW = help[k];
		}
	}
	maxminK = help2[1];
	for (k = 1; k < n; k++)
	{
		if (help2[k] > maxminK)
		{
			maxminK = help2[k];
		}
	}

	cout << endl << "Najwieksze min z W: " << maxminW << endl;
	cout << endl << "Najwieksze min z K: " << maxminK << endl;
}

void Traveler::FindInd()
{
	max = maxminW;
	for (j = 1; j < n; j++)
	{
	//	if(cities)
	}
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
	for (i = 0; i < n - 1; i++)
	{
		LB += help[i];
		LB += help2[i];
	}
}



