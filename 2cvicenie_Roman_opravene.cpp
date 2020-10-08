#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

 struct PRODUKT {
	int id;
	string nazov;
	string vyrobca;
	int pocet_kus;
	int cena;
};

 struct ZAKAZNIK {
	string meno;
	string priezvisko;
	int rozpocet;
	PRODUKT pocet[50];
};

int main()
{
	int n;
	ZAKAZNIK Z;
	int i, j;


	fstream fo;
	fo.open("cvicenie1.txt", ios::in);
	if (!fo.is_open()){
		cout << "Subor sa nepodarilo otvorit!" << endl;
	}
	
	fo >> n;
	PRODUKT* P = new PRODUKT[n];
	if (P == NULL)
	{
		return 3;
	}

	for (i = 0; i < n; i++) {
		fo >> P[i].id >> P[i].nazov >> P[i].vyrobca >> P[i].pocet_kus >> P[i].cena;
	}
	fo.close();
	for (j = 0; j < n; j++)
	{
		cout << P[j].id << " " << P[j].nazov << " " << P[j].vyrobca << " " << P[j].pocet_kus << " " << P[j].cena << endl;
	}
	cout << "zadaj meno, priezvisko a rozpocet: ";
	cin >> Z.meno >> Z.priezvisko >> Z.rozpocet;
	int t = Z.rozpocet;
	cout << " meno: " << Z.meno << endl << "priezvisko: " << Z.priezvisko << endl << "rozpocet v eurach: " << Z.rozpocet << endl;
	string b;
	string s= "stop";
	string naz = "nazov";
	string vyr = "vyrobca";
	int a = 0;
	int u;
	string zx = "aa";
	string g = "id";
	int v = 0;
	int rt;
	int ge = 0;
	int zr;

	do {

		a = 0;
		cout << "zadaj 'nazov' alebo 'vyrobca':";
		cin >> b;

		if (naz.find(b, 0) != -1)
		{
			cout << "zadaj nazov produktu:";
			cin >> b;
			cout << endl;
			if (b.find(s, 0) != -1)
			{
				cout << "nakup skoncil";
				break;
			}
			for (i = 0; i < n; i++)
			{
				if (P[i].nazov.find(b,0) != -1)
				{
					cout << " produkt " << b << " sa nasiel(id produktu je" << P[i].id <<"), zadajte 'id' pre info o produkte(zadajte 'stop' pre ukoncenie nakupu): ";
					a++;
				}
			}
			if (a != 0)
			cin >> zx;
			if (g.find(zx,0) != -1)
			{
				cout << endl << "zadaj id produktu: ";
				cin >> u;
				for (i = 0; i < n; i++)
				{
					if (u == P[i].id)
					{
						rt = i;
						cout << "kusov skladom: " << P[i].pocet_kus << endl << "predajna cena: " << P[i].cena << endl;
					}
				}
				cout << "kupit tovar (1) nekupit tovat(2):";
				cin >> zr;

				if (zr == 1)
				{
					for (i = 0; i < v; i++)
					{
						if (Z.pocet[i].id == P[rt].id)
							ge++;
					}

					if (ge == 0)
					{
						if (Z.rozpocet >= P[rt].cena && P[rt].pocet_kus > 0)
						{
							Z.rozpocet = Z.rozpocet - P[rt].cena;
							P[rt].pocet_kus = P[rt].pocet_kus - 1;
							Z.pocet[v].cena = P[rt].cena;
							Z.pocet[v].id = P[rt].id;
							Z.pocet[v].nazov= P[rt].nazov;
							Z.pocet[v].vyrobca=P[rt].vyrobca;
							Z.pocet[v].pocet_kus = P[rt].pocet_kus - P[rt].pocet_kus + 1;
							cout << " id: " << Z.pocet[v].id << " nazov: " << Z.pocet[v].nazov << " vyrobca: " << Z.pocet[v].vyrobca << " pocet kusov: " << Z.pocet[v].pocet_kus << " cena: " << Z.pocet[v].cena << endl;  
							v++;
						}

					}
					if (ge != 0)
					{
						if (Z.rozpocet >= P[rt].cena && P[rt].pocet_kus > 0)
						{
							for (i = 0; i < v; i++)
							{
								if (u == Z.pocet[i].id)
								{
									Z.pocet[i].pocet_kus++;
									Z.rozpocet = Z.rozpocet - P[rt].cena;
									cout << " id: " << Z.pocet[i].id << " nazov: " << Z.pocet[i].nazov << " vyrobca: " << Z.pocet[i].vyrobca << " pocet kusov: " << Z.pocet[i].pocet_kus << " cena: " << Z.pocet[i].cena << endl;

								}
							}
						}
					}
					ge = 0;
					if (Z.rozpocet < P[rt].cena) cout << "na dalsi produkt nemate dost peniaze  zadajte 'stop' pre ukoncenie nakupu" << endl;
					if (P[rt].pocet_kus <= 0) cout << "tovar uz nie je skladom, zadajte 'stop' pre ukoncenie nakupu" << endl;
				}
				if (zr == 2) cout << "zrusili ste nakup" << endl;
			}
			if (a == 0) cout << " produkt sa nenasiel, zadajte produkt(zadajte 'stop' pre ukoncenie nakupu): ";
		}

		if (vyr.find(b,0) != -1)
		{
			cout << "zadaj nazov vyrobcu: ";
			cin >> b;
			cout << endl;
			if (b.find(s, 0) != -1)
			{
				cout << "nakup skoncil";
				break;
			}
			for (i = 0; i < n; i++)
			{
				if (P[i].vyrobca.find(b, 0) != -1)
				{
					cout << "produkt " << P[i].nazov << " (vyrobca) " << b << " sa nasiel(id produktu je " << P[i].id << "), zadajte 'id' pre info o produkte(zadajte 'stop' pre ukoncenie nakupu): " << endl; 
					a++;
				}
			}
			if (a != 0)
				cin >> zx;
			if (g.find(zx, 0) != -1)
			{
				cout << endl << "zadaj id produktu: ";
				cin >> u;
				for (i = 0; i < n; i++)
				{
					if (u == P[i].id)
					{
						rt = i;
						cout << "kusov skladom: " << P[i].pocet_kus << endl << "predajna cena: " << P[i].cena << endl; 
					}
				}
				cout << "kupit tovar (1) nekupit tovat(2):";
				cin >> zr;

				if (zr == 1)
				{
					for (i = 0; i < v; i++)
					{
						if (Z.pocet[i].id == P[rt].id)
							ge++;
					}

					if (ge == 0)
					{
						if (Z.rozpocet >= P[rt].cena && P[rt].pocet_kus > 0)
						{
							Z.rozpocet = Z.rozpocet - P[rt].cena;
							P[rt].pocet_kus = P[rt].pocet_kus - 1;
							Z.pocet[v].cena = P[rt].cena;
							Z.pocet[v].id = P[rt].id;
							Z.pocet[v].nazov= P[rt].nazov;
							Z.pocet[v].vyrobca=P[rt].vyrobca;
							Z.pocet[v].pocet_kus = P[rt].pocet_kus - P[rt].pocet_kus + 1;
							cout << " id: " << Z.pocet[v].id << " nazov: " << Z.pocet[v].nazov << " vyrobca: " << Z.pocet[v].vyrobca << " pocet kusov: " << Z.pocet[v].pocet_kus << " cena: " << Z.pocet[v].cena << endl;
							v++;
						}

					}
					if (ge != 0)
					{
						if (Z.rozpocet >= P[rt].cena && P[rt].pocet_kus > 0)
						{
							for (i = 0; i < v; i++)
							{
								if (u == Z.pocet[i].id)
								{
									Z.pocet[i].pocet_kus++;
									Z.rozpocet = Z.rozpocet - P[rt].cena;
									cout << " id: " << Z.pocet[i].id << " nazov: " << Z.pocet[i].nazov << " vyrobca: " << Z.pocet[i].vyrobca << " pocet kusov: " << Z.pocet[i].pocet_kus << " cena: " << Z.pocet[i].cena << endl;

								}
							}
						}
					}
					ge = 0;
					if (Z.rozpocet < P[rt].cena) cout << "na dalsi produkt nemate dost peniaze  zadajte 'stop' pre ukoncenie nakupu" << endl;
					if (P[rt].pocet_kus <= 0) cout << "tovar uz nie je skladom, zadajte 'stop' pre ukoncenie nakupu" << endl;
				}
				if (zr == 2) cout << "zrusili ste nakup" << endl;
			}
			if (a == 0) cout << " produkt sa nenasiel, zadajte produkt(zadajte 'stop' pre ukoncenie nakupu): ";
		}
	} while (b.find(s, 0) == -1);
	int o;
	o = t - Z.rozpocet;
	cout << "minuta suma: " << o << endl;
	fstream fr;
	fr.open("vybrane_produkty.txt",ios::out );
	if (!fr.is_open())
	{
		cout << "Subor sa nepodarilo otvorit!" << endl;
	}
	for (i = 0; i < v; i++) {
		fr << Z.pocet[i].id << " " << Z.pocet[i].nazov << " " << Z.pocet[i].vyrobca << " " << Z.pocet[i].pocet_kus << " " << Z.pocet[i].cena <<endl;
	}
	fr.close();

	delete[] P;
}

