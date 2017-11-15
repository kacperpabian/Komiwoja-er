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
	Traveler *traveler = new Traveler (++n);

	traveler->LoadCities();
	traveler->InitCities2();
	traveler->Run();

	traveler->End();
	//traveler.DisplayPath();
	delete traveler;
	getchar();
	getchar();
}