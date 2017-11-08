#include "Traveler.h"

int main()
{
	int ** cities;
	int m, n;
	system("cls");

	cout << "/******Komiwojazer dla n miast********" << endl;
	cout << "Podaj ilosc miast:" << endl;
	cin >> m;
	n = m + 1;

	cities = new int*[n];
	for (int i = 0; i < n; i++)
	{
		cities[i] = new int[n];
	}
	Traveler traveler(cities, n);

	cities = traveler.LoadCities();
	traveler.DisplayCities();
	traveler.FindMin();
	traveler.DisplayCities();
	traveler.SumLowerBound();
	cout << endl << traveler.LB << endl;
	traveler.FindMin2();
	traveler.FindMaxMin();
	traveler.FindZero();


	getchar();
}