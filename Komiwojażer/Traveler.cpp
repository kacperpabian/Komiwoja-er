#include "Traveler.h"

Traveler::Traveler(int n)
{
	maxminW = 0;
	maxminK = 0;
	szuki = 1;
	szukj = 1;
	indi = 0;
	indj = 0;
	this->n = n;
	n2 = n;
	reservePath = new int[2 * n2];
	finalPath = new int[2 * n2];
	
	counter = 0;
	cities = new int*[n];
	for (int i = 0; i < n; i++)
		cities[i] = new int[n];

	path = new int[2 * n2];
	for (int i = 0; i < 2*n2; i++)
		path[i] = 0;
}

Traveler::Traveler(int n, int n2, int maxminW, int maxminK, int szuki, int szukj, int indi, int indj, int counter,
	int **cities, int **cities2, int *help, int *help2, int * path, int LB)
{
	this->maxminW = maxminW;
	this->maxminK = maxminK;
	this->szuki = szuki;
	this->szukj = szukj;
	this->indi = indi;
	this->indj = indj;
	this->n = n;
	this->n2 = n2;
	this->LB = LB;
	reservePath = new int[2 * n2];
	finalPath = new int[2 * n2];
	this->counter = counter;

	this->cities = new int*[n];
	for (int i = 0; i < n; i++)
	{
		this->cities[i] = new int[n];
		for (int j = 0; j < n; j++)
			this->cities[i][j] = cities[i][j];
	}
		
	this->cities2 = new int*[n];
	for (int i = 0; i < n; i++)
	{
		this->cities2[i] = new int[n];
		for (int j = 0; j < n; j++)
			this->cities2[i][j] = cities2[i][j];
	}

	this->help = new int[n];
	for (int i = 0; i < n; i++)
		this->help[i] = help[i];

	this->help2 = new int[n];
	for (int i = 0; i < n; i++)
		this->help2[i] = help2[i];

	this->path = new int[2 * n2];
	for (int i = 0; i < 2*n2; i++)
		this->path[i] = path[i];
}

Traveler::~Traveler()
{
	for (int i = 0; i < n2; i++)
		delete[] cities2[i];

	for (int i = 0; i < n; i++)
		delete[] cities[i];
	
	delete[] cities;
	delete[] cities2;
	delete[] help;
	delete[] help2;
	delete[] path;
	delete[] finalPath;
	delete[] reservePath;
}

void Traveler::LoadCities()
{
	int m = 0, j = 0, i = 0, h = 0;

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
				cities[i][j] = rand() % 40;
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
	int i = 0, j = 0;
	int min = 0;
	help = new int[n];
	help2 = new int[n];

	int k = 0;
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
	int h = 0;
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

	//DisplayMin();
	//DisplayCities(cities, n);
}

void Traveler::FindMin2()
{
	int min = 0;
	int zeroNumber = 0;
	if (help && help2)
	{
		delete[] help;
		delete[] help2;
	}
	help = new int[n];
	help2 = new int[n];
	//szukamy w wierszach
	int k = 0;
	for (int i = 1; i < n; i++)
	{
		min = 999;
		for (int j = 1; j < n; j++)
		{
			if (cities[i][j] == 0) 
				zeroNumber++;
			if (zeroNumber > 1) 
				min = 0;
			else
			{
				if (cities[i][j] <= min && cities[i][j] > 0 && cities[i][j] < 900)
					min = cities[i][j];
			}
			help[k] = min;
		}
		k++;
		zeroNumber = 0;
	}
	//szukamy w kolumnach
		k = 0;
	for (int j = 1; j < n; j++)
	{
		min = 999;
		for (int i = 1; i < n; i++)
		{
			if (cities[i][j] == 0) 
				zeroNumber++;
			if (zeroNumber >= 2)
				min = 0;
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
	//DisplayMin();
}

void Traveler::FindMaxMin()
{
	int i = 0;
	maxminW = help[0];
	for (int k = 1; k < n; k++)
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
	for (int k = 1; k < n; k++)
	{
		if (help2[i] >= maxminK)
		{
			maxminK = help2[i];
			szukj = k;
		}
		i++;
	}

	if (maxminW > maxminK)
	{
		i = 0;
		for (int k = 1; k < n; k++)
		{
			if (help[i] == maxminW)
			{
				Traveler *traveler = new Traveler(n, n2, maxminW, maxminK, k, szukj, indi, indj, counter, cities, cities2, help, help2, path, LB);
				traveler->RecursiveRun();
			}
			i++;
		}
	}
	else if (maxminW < maxminK)
	{
		i = 0;
		for (int k = 1; k < n; k++)
		{
			if (help2[i] == maxminK)
			{
				Traveler *traveler = new Traveler(n, n2, maxminW, maxminK, szuki, k, indi, indj, counter, cities, cities2, help, help2, path, LB);
				traveler->RecursiveRun();
			}
			i++;
		}
	}
	else if (maxminW == maxminK)
	{
		i = 0;
		for (int k = 1; k < n; k++)
		{
			if (help[i] == maxminW)
			{
				Traveler *traveler = new Traveler(n, n2, maxminW, maxminK, k, szukj, indi, indj, counter, cities, cities2, help, help2, path, LB);
				traveler->RecursiveRun();
			}
			i++;
		}
		i = 0;
		for (int k = 1; k < n; k++)
		{
			if (help2[i] == maxminK)
			{
				Traveler *traveler = new Traveler(n, n2, maxminW, maxminK, szuki, k, indi, indj, counter, cities, cities2, help, help2, path, LB);
				traveler->RecursiveRun();
			}
			i++;
	}
		//go1
		//go2
	}
	

	//cout << endl << " Najwieksze min z W: " << maxminW << endl;
	//cout << endl << " Najwieksze min z K: " << maxminK << endl;
}

void Traveler::FindZero()
{
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

	//cout << endl << " zero dla wiekszego z minimow:" << " szuki(wiersze)= " << szuki << " szukj(kolumny)= " << szukj << endl;
	//cout << " jest w: (kolumny)i=" << indi << " (wiersze)j=" << indj << endl;
	
}

void Traveler::FindInd()
{
	int max = 0;
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
	cities2 = new int*[n];
	for (int i = 0; i < n; i++)
		cities2[i] = new int[n];

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			cities2[i][j] = cities[i][j];
}
void Traveler::RemoveRC()
{
	if (maxminK > maxminW)
	{
		//cout << " k " << cities[indi][0] << "/" << cities[0][szukj] << endl;
		path[counter++] = cities[indi][0];
		path[counter++] = cities[0][szukj];

		
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (cities[0][szukj] == cities[i][0] && cities[indi][0] == cities[0][j])
					cities[i][j] = 999;
			}			
	}
	else
	{
		//cout << " w " << cities[szuki][0] << "/" << cities[0][indj] << endl;
		path[counter++] = cities[szuki][0];
		path[counter++] = cities[0][indj];
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
			{
				if (cities[0][indj] == cities[i][0] && cities[szuki][0] == cities[0][j])
					cities[i][j] = 999;
			}
	}
	
	n = n - 1;
	cities3 = new int*[n];
	for (int i = 0; i < n; i++)
		cities3[i] = new int[n];

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
		delete[] cities[i];

	delete[] cities;

	cities = cities3;
	//DisplayCities(cities, n);
}

void Traveler::DisplayPath(int* path)
{
	if (path[0] == path[counter - 1])
	{
		cout << endl << " Wyswietlam sciezke: " << endl;
		for (int i = 0; i < counter; i++)
			cout << " (" << path[i++] << " " << path[i] << ") ";
		cout << endl;
	}
}

void Traveler::DisplayMin()
{
	cout << endl << endl;
	cout << " Najmniejsze elementy z wierszy:";
	for (int h = 0; h < n - 1; h++)
	{
		cout.width(3); 
		cout << help[h];
	}

	cout << endl << endl;
	cout << " Najmniejsze elementy z kolumn:";
	for (int h = 0; h < n - 1; h++)
	{
		cout.width(3);
		cout << help2[h];
	}

	cout << endl;
}

void Traveler::SortPath(int* path)
{
	int it = 2;
	finalPath[0] = path[0];
	finalPath[1] = path[1];
	path[0] = 0;
	path[1] = 0;

	int buffor = finalPath[1];
	for(int j = 0; j < counter; j++)
		for (int i = 0; i < counter; i++)
		{
			if (buffor == path[i])
			{
				finalPath[it++] = path[i];
				path[i++] = 0;
				buffor = finalPath[it++] = path[i];
				path[i++] = 0;
				i = counter;
			}
		}
}

void Traveler::FindLastPath()
{
	for (int i = 0; i < counter; i++)
		reservePath[i] = path[i];

	path[counter++] = cities[2][0];
	path[counter++] = cities[0][1];
	path[counter++] = cities[1][0];
	path[counter++] = cities[0][2];
	counter -= 4;
	reservePath[counter++] = cities[1][0];
	reservePath[counter++] = cities[0][1];
	reservePath[counter++] = cities[2][0];
	reservePath[counter++] = cities[0][2];


	//DisplayPath(path);
	//DisplayPath(reservePath);

	SortPath(path);
	if (finalPath[0] == finalPath[counter - 1])
		DisplayPath(finalPath);

	else 
	{
		SortPath(reservePath);
		DisplayPath(finalPath);
	}
}

void Traveler::Run()
{
	for (int i = n - 1; i > 2; i--)
	{
		//cout << endl << " Run" << endl;
		FindMin();
		FindMin2();
		FindMaxMin();
		FindZero();
		RemoveRC();
		Reset();
	}
	FindLastPath();
}

void Traveler::RecursiveRun()
{
	//cout << endl << " RecRun" << endl;
	FindZero();
	RemoveRC();
	Reset();

	for (int i = n - 2; i > 2; i--)
	{
		FindMin();
		FindMin2();
		FindMaxMin();
		FindZero();
		RemoveRC();
		Reset();
	}
	FindLastPath();
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
	//DisplayCities(cities2, n2);
}