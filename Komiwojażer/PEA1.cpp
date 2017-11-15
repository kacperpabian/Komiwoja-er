#include "Traveler.h"
#include <ctime>

int main()
{
	srand(time(NULL));
	int n;
	system("cls");

	cout << "/******Komiwojazer dla n miast********" << endl;
	cout << "Podaj ilosc miast:" << endl;
	cin >> n;
	Traveler traveler(++n);

	traveler.LoadCities();
	traveler.InitCities2();
	traveler.Run();

	traveler.End();
	traveler.FindLastPath();
	//traveler.DisplayPath();
	getchar();
}