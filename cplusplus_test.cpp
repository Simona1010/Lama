#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

struct PRODUKT {
	int ID;
	string nazov;
	string vyrobca;
	int pocet;
	float cena;
};

int main(){
	fstream afile;
	int n;
	PRODUKT p[10];
	
	afile.open("eshop.txt", ios::in);
	if (afile.is_open()){
		afile >> n;
		cout << "Nacitany na pocet produktov " << n << endl;
		
		for(int i=0;i<n;i++ ){
			afile >> p[i].ID >> p[i].nazov >> p[i].vyrobca >> p[i].pocet >> p[i].cena;
			cout << "ID: " << p[i].ID << endl;
			cout << "Nazov: " << p[i].nazov << endl;
			cout << "Vyrobca: " << p[i].vyrobca <<endl;
			cout << "Pocet: " << p[i].pocet << endl;
			cout << fixed << setprecision(2) << p[i].cena << endl;
			cout << "Cena: " << p[i].cena << endl;
		}
	//	new p[n];
	
	}
	else {
		cout << "Subor sa nepodarilo otvorit" << endl;
	}


	
	/*
	f1 = fopen("eshop.txt", "r");
		if (f1 == NULL)
		{
			printf("Subor neexistuje");
			exit(1);
		}
	fscanf(f1, "%d", &n); //n = pocet poloziek v zozname
	printf("Vypis prveho riadku %d\n", n);
	
	p = ( PRODUKT*) malloc(n * sizeof(PRODUKT));
		if(p == NULL){
		free(p);
	}
	
	for(int i=0;i<n;i++ ){
		fscanf(f1,"%d %s %s %d %f",&p[i].ID,&p[i].nazov,&p[i].vyrobca,&p[i].pocet,&p[i].cena);
		cout << "ID: " << p[i].ID << endl;
		cout << "Nazov: " << p[i].nazov << endl;
		cout << "Vyrobca: " << p[i].vyrobca <<endl;
		cout << "Pocet: " << p[i].pocet << endl;
		cout << fixed << setprecision(2) << p[ID].cena << endl;
		cout << "Cena: " << p[i].cena << endl;
		}
	fclose(f1);
	*/
	return 0;
}
