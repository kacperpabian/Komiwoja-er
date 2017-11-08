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
	//traveler.DisplayCities();
	traveler.FindMin();
	//traveler.DisplayCities();
	traveler.SumLowerBound();
	//cout << endl << traveler.LB << endl;
	traveler.FindMin2();
	traveler.FindMaxMin();
	traveler.FindZero();
	traveler.InitCities2();
	traveler.RemoveRC();

	getchar();
}