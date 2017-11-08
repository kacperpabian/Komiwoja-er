#include "Traveler.h"

int main()
{
	int n;
	system("cls");

	cout << "/******Komiwojazer dla n miast********" << endl;
	cout << "Podaj ilosc miast:" << endl;
	cin >> n;
	Traveler traveler(++n);

	traveler.LoadCities();
	traveler.FindMin();
	traveler.SumLowerBound();
	traveler.FindMin2();
	traveler.FindMaxMin();
	traveler.FindZero();
	traveler.InitCities2();
	traveler.RemoveRC();

	for (int i = n - 1; i > 2; i--)
	{
		traveler.FindMin();
		traveler.FindMin2();
		traveler.FindMaxMin();
		traveler.FindZero();
		traveler.RemoveRC();
	}

	getchar();
}