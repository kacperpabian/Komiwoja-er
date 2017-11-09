#include "Traveler.h"

Traveler::Traveler(int n)
{
	this->n = n;
	n2 = n;
	path = new int[2 * n2];
	counter = 0;
	cities = new int*[n];
	for (int i = 0; i < n; i++)
	{
		cities[i] = new int[n];
	}
}

Traveler::~Traveler()
{
	for (int i = 0; i < n2; i++)
	{
		delete[] cities2[i];
	}
	for (int i = 0; i < n; i++)
	{
		delete[] cities[i];
	}
	delete[] cities;
	delete[] cities2;
	delete[] help;
	delete[] help2;
	delete[] path;
}

void Traveler::LoadCities()
{
	cout << "LoadCities()" << endl;
	int m = 0;
	int j = 0, i = 0;
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
				cities[i][j] = rand() % 20;
			}
		}
	}
	//cities[1][1] = 999;
	//cities[2][1] = 78;
	//cities[3][1] = 5;
	//cities[4][1] = 12;
	//cities[5][1] = 3;
	//cities[1][2] = 12;
	//cities[2][2] = 999;
	//cities[3][2] = 56;
	//cities[4][2] = 6;
	//cities[5][2] = 98;
	//cities[1][3] = 3;
	//cities[2][3] = 90;
	//cities[3][3] = 999;
	//cities[4][3] = 8;
	//cities[5][3] = 3;
	//cities[1][4] = 45;
	//cities[2][4] = 21;
	//cities[3][4] = 23;
	//cities[4][4] = 999;
	//cities[5][4] = 2;
	//cities[1][5] = 6;
	//cities[2][5] = 3;
	//cities[3][5] = 98;
	//cities[4][5] = 34;
	//cities[5][5] = 999;

	DisplayCities(cities, n);
}

void Traveler::DisplayCities(int ** cities, int n)
{
	cout << "DisplayCities()" << endl;
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cout << endl << " Macierz miast:";
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < n; j++)
		{
			if (cities[i][j] == 999)
				SetConsoleTextAttribute(hConsole, 12);
			else if (cities[i][j] == 0)
				SetConsoleTextAttribute(hConsole, 2);
			if (j == 0 || i == 0)
				SetConsoleTextAttribute(hConsole, 8);

			cout.width(5);
			cout << cities[i][j];
			SetConsoleTextAttribute(hConsole, 7);
		}
	}
	cout << endl;
}

void Traveler::FindMin()
{
	cout << "FindMin()" << endl;
	int loop = n - 2, i = 0, j = 0;
	help = new int[n];
	help2 = new int[n];

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
			if (cities[i][j] < 900) 
				cities[i][j] = cities[i][j] - help[k];
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
			if (cities[i][j] < 900) 
				cities[i][j] = cities[i][j] - help2[h];
		}
		h++;
	}

	DisplayMin();
	DisplayCities(cities, n);
}

void Traveler::FindMin2()
{
	cout << "FindMin2()" << endl;
	int i, j;
	if (n > 2)
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
	cout << "FindMaxMin()" << endl;
	int i = 0;
	maxminW = help[0];
	for (k = 1; k < n; k++)
	{
		if (help[i] >= maxminW)
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
		if (help2[i] >= maxminK)
		{
			maxminK = help2[i];
			szukj = k;
		}
		i++;
	}

	cout << endl << " Najwieksze min z W: " << maxminW << endl;
	cout << endl << " Najwieksze min z K: " << maxminK << endl;
}

void Traveler::FindZero()
{
	cout << "FindZero()" << endl;
	if (maxminK > maxminW)
	{
		for (int i = 1; i < n; i++)
			if (cities[i][szukj] == 0)
			{
				indi = i;
			}
	}
	else
	{
		for (int j = 1; j < n; j++)
			if (cities[szuki][j] == 0)
			{
				indj = j;
			}
	}

	cout << endl << " wartosc zera: " << max << " dla indexow: i=" << indi << " j=" << indj << endl;
	cout << " szuki: " << szuki << " szukj: " << szukj << endl;
}

void Traveler::FindInd()
{
	cout << "FindInd()" << endl;
	max = 0;
	if (maxminK < maxminW)
	{
		max = maxminW;
	}
	else
	{
		max = maxminK;
	}
	if (max == maxminW)
	{
		for (int j = 1; j < n; j++)
			if (cities[szuki][j] == max)
			{
				indi = szuki;
				indj = j;
			}
	}
	else
		if (max == maxminK)
		{
			for (int i = 1; i < n; i++)
				if (cities[i][szukj] == max)
				{
					indi = i;
					indj = szukj;
				}
		}
	cout << endl << " maks wartosc: " << max << " dla indexow: i=" << indi << " j=" << indj << endl;
}

void Traveler::InitCities2()
{
	cout << "InitCities2()" << endl;
	cities2 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		cities2[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cities2[i][j] = cities[i][j];
		}
	}
}
void Traveler::RemoveRC()
{
	cout << "RemoveRC()" << endl;
	if (maxminK > maxminW)
	{
		cout << " k " << cities[indi][0] << "/" << cities[0][szukj] << endl;
		path[counter++] = cities[indi][0];
		path[counter++] = cities[0][szukj];

		
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (cities[0][szukj] == cities[i][0] && cities[indi][0] == cities[0][j])
				{
					cities[i][j] = 999;
				}
			}
		}

		//cities2[szukj][indi] = 999;
		//cities2[szuki][szukj] = 999;
	}
	else
	{
		cout << " w " << cities[szuki][0] << "/" << cities[0][indj] << endl;
		path[counter++] = cities[szuki][0];
		path[counter++] = cities[0][indj];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (cities[0][indj] == cities[i][0] && cities[szuki][0] == cities[0][j])
				{
					cities[i][j] = 999;
				}
			}
		}

		//cities2[indj][szuki] = 999;
		//cities2[szuki][szukj] = 999;
	}
	

	n = n - 1;
	cities3 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		cities3[i] = new int[n];
	}

	int p = 0;
	int o = 0;
	if (maxminK > maxminW)
	{
		for (int i = 0; i < n; i++)
		{
			if (i == indi)
				p++;

			o = 0;

			for (int j = 0; j < n; j++)
			{
				if (j == szukj)
					o++;

				cities3[i][j] = cities[p][o];
				o++;
			}
			p++;
		}
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (i == szuki)
				p++;

			o = 0;

			for (int j = 0; j < n; j++)
			{
				if (j == indj)
					o++;

				cities3[i][j] = cities[p][o];
				o++;
			}
			p++;
		}
	}
	for (int i = 0; i < n; i++)
	{
		delete[] cities[i];
	}
	delete[] cities;

	cities = cities3;
	DisplayCities(cities, n);
	//DisplayCities(cities2, n2);
}

void Traveler::DisplayPath()
{
	cout << endl << " Wyswietlam sciezke: " << endl;
	for (int i = 0; i < counter; i++)
	{
		cout << " (" << path[i++] << " " << path[i] << ") ";
	}
	cout << endl;
}

void Traveler::DisplayMin()
{
	cout << "DisplayMin()" << endl;
	cout << endl << endl;
	cout << " Najmniejsze elementy z wierszy:";
	for (h = 0; h < n - 1; h++)
	{
		cout.width(3); cout << help[h];
	}
	cout << endl << endl;
	cout << " Najmniejsze elementy z kolumn:";
	for (h = 0; h < n - 1; h++)
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

void Traveler::Reset() 
{
	cout << "Reset()" << endl;
	max = 0;
	maxminW = 0;
	maxminK = 0;
	szuki = 1;
	szukj = 1;
	indi = 0;
	indj = 0;
}

void Traveler::End()
{
	cout << "End()" << endl;
	DisplayCities(cities2, n2);
}