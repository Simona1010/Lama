#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;

struct PRODUKT{
	int ID;
	string nazov;
	string vyrobca;
	int pocet;
	float cena;
};

struct ZAKAZNIK{
	string meno;
	string priezvisko;
	float rozpocet;
	PRODUKT kupene[50];
};

void vyber_ID(PRODUKT *p,ZAKAZNIK z,float *nakup);
void vyhladavanie(PRODUKT *p,ZAKAZNIK z,float *nakup);
void zapis_do_suboru(PRODUKT *p,ZAKAZNIK z,int i);

void zapis_do_suboru(PRODUKT *p,ZAKAZNIK z,int i){
	FILE *fp;
	fp = fopen("C:\\Users\\Simi\\Desktop\\cviko1\\kupeny_tovar.txt","a");
	
	if(fp == NULL){
		cout << "Subor neexistuje";
		exit(1);
	}
	fprintf(fp,"ID: %d\n Nazov: %s\n Vyrobca: %s\n Pocet kusov na sklade: %d\n Cena vyrobku: %.2f\n ",z.kupene[i].ID,z.kupene[i].nazov,z.kupene[i].vyrobca,z.kupene[i].pocet,z.kupene[i].cena);
	fclose(fp);
}
void vyber_ID(PRODUKT *p,ZAKAZNIK z,float *nakup)
{	FILE *f2;
	int id,ID=0,sklad,i=0;
	string vyber;
	string kupi = "A";
	string nekupi = "N";

	
	cout << "Zadajte ID cislo vyrobku o ktory mate zaujem" << endl;
	cin >> id; 		
	ID = id - 1;
	cout << "ID: " << p[ID].ID << endl;
	cout << "Nazov: " << p[ID].nazov << endl;
	cout << "Vyrobca: " << p[ID].vyrobca <<endl;
	cout << "Pocet: " << p[ID].pocet << endl;
	cout << fixed << setprecision(2) << p[ID].cena << endl;
	cout << "Cena: " << p[ID].cena << endl;

		if(p[ID].pocet>0)
		{
			cout << "Vyrobok je na sklade v pocte kusov: " << p[ID].pocet << endl;
			cout << "Cena vyrobku: " << p[ID].cena << endl;
			cin >> vyber;
			
			if (strcmp(vyber,kupi) == 0)
			{	
					
					cout <<"ID nacitane je" << ID +1 << ensl;
					p[ID].pocet = p[ID].pocet - 1;
					z.kupene[i] = p[ID] ;
					
					cout << "Vypis kupenych produktov:" <<endl;
					cout << "ID: " << z.kupene[i] << endl;
					cout << "Nazov: " << z.kupene[i].nazov << endl;
					cout << "Vyrobca: " << z.kupene[i].vyrobca <<endl;
					cout << "Pocet: " << z.kupene[i].pocet << endl;
					cout << fixed << setprecision(2) << z.kupene[i].cena << endl;
					cout << "Cena: " << z.kupene[i].cena << endl;
					
					cout << "Aktualny rozpocet:" << z.rozpocet << endl;
					
					if(0 < (z.rozpocet-p[ID].cena)){
						z.rozpocet -=  p[ID].cena;
						cout << "Rozpocet po nakupe:" << z.rozpocet << endl;
						*nakup += p[ID].cena;
						cout << "V eshope ste zatial minuli" << *nakup << endl;
						}
						
					else {
						cout << "Prekrocili ste hranicu rozpoctu" << endl;
						cout << "Aktualny rozpocet:" << z.rozpocet << endl;
						cout << "V eshope ste minuli" << *nakup << endl;
						exit(1);
					}					
					zapis_do_suboru(p,z,i);
					i++;
					vyhladavanie(p,z,nakup);
		
				
			}	
			if (strcmp(vyber,nekupi) == 0){
				vyhladavanie(p,z,nakup);
			}
		}
		else {
			cout << "Vyrobok  nie je na sklade" << endl;
			vyhladavanie(p,z,nakup);
		}
}

void vyhladavanie(PRODUKT *p,ZAKAZNIK z,float *nakup)
{	string nazov;
	string vyrobca; 
	int porovnanie1 =0, porovnanie2=0;
	int ID = 0;
	int moznost=0;

	cout << "Ak chcete vyhladat produkt podla nazvu zadajte '1'" << endl;
	cout << "Ak chcete vyhladat produkt podla vyrobku zadajte '2'" << endl;	
	cout << "Ak chcete ukoncit nakup zadajte '3'" << endl;
	cin >> moznost;
	
	
	if(moznost == 1)
	{
		cout << "Zadajte nazov vyrobku:" << endl;
		cin >> nazov;

		
		for(int i=0;i<10;i++)
			{
				porovnanie1 = strcmp(nazov,p[i].nazov);
				if(porovnanie1 == 0) //ak sa dve slova rovnaju
				{	
					cout << "ID: " << p[i].ID << endl << "Nazov: " << p[i].nazov << endl << "Vyrobca: " << p[i].vyrobca << endl << "Pocet: " << p[i].pocet << endl << "Cena: " << p[i].cena << endl;
				}
			}
		vyber_ID(p,z,nakup);	
	}
	if(moznost == 2)
	{
		cout << "Zadajte vyrobca vyrobku:" << endl;
		cin >> vyrobca;
		

		for(i=0;i<10;i++)
			{
				porovnanie2 = strcmp(vyrobca,p[i].vyrobca);
				if(porovnanie2 == 0)
				{
				cout << "ID: " << p[i].ID << endl << "Nazov: " << p[i].nazov << endl << "Vyrobca: " << p[i].vyrobca << endl << "Pocet: " << p[i].pocet << endl << "Cena: " << p[i].cena << endl;
				
				}
			}

		vyber_ID(p,z,nakup);	
	}	
	else if(moznost == 3) 
	{
		cout << "Ukoncili ste nakup" <<endl;
		cout << "V eshope ste minuli" << *nakup << endl;
		exit(1);
	}
}

int main() {
	int n=0;
	FILE* f1;
	ZAKAZNIK kupene_produkty[50];
	PRODUKT *p;
	ZAKAZNIK z1;
	float nakup =0;
    
 	fstream fo;
	fo.open("cvicenie1.txt", ios::in);
	if (!fo.is_open()){
		cout << "Subor sa nepodarilo otvorit!" << endl;
	}   
    
	f1 = fopen("eshop.txt", "r");
	if (f1 == NULL)
	{
		printf("Subor neexistuje");
		exit(1);
	}
	fscanf(f1, "%d", &n); //n = pocet poloziek v zozname
	printf("Vypis prveho riadku %d\n", n);
	int i;
	
	p = ( PRODUKT*) malloc(n * sizeof(PRODUKT));
	if(p == NULL){
		free(p);
	}
	
	for(i=0;i<10;i++ ){
		fscanf(f1,"%d %s %s %d %f",&p[i].ID,&p[i].nazov,&p[i].vyrobca,&p[i].pocet,&p[i].cena);
		printf("ID :%d\n nazov: %s\n vyrobca: %s\n pocet: %d\n cena: %2.f\n",p[i].ID,p[i].nazov,p[i].vyrobca,p[i].pocet,p[i].cena);
		}
	fclose(f1);
/*	
	printf("Zadaj meno:\n");
	scanf("%s",&z1.meno);
	printf("Zadaj priezvisko:\n");
	scanf("%s",&z1.priezvisko);
	printf("Zadaj vyska rozpoctu:\n");
	scanf("%f",&z1.rozpocet);	
*/	

	strcpy(z1.meno,"Janka");
	strcpy(z1.priezvisko,"Novomestka");
	z1.rozpocet = 50.50;
	printf("Zakaznik:\nMeno: %s\nPriezvisko: %s\nRozpocet:%.2f\n",z1.meno,z1.priezvisko,z1.rozpocet);
	 
	 
//printf("Kupene:%int",z1.kupene.nazov,z1.kupene.vyrobca);
	vyhladavanie(p,z1,&nakup);
//	zapis_do_suboru(p,z);
	return 0;
}

