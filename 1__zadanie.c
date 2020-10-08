#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct {
	int ID;
	char nazov[20];
	char vyrobca[20];
	int pocet;
	float cena;
}PRODUKT;

typedef struct {
	char meno[6];
	char priezvisko[11];
	float rozpocet;
	PRODUKT kupene[50];
}ZAKAZNIK;

void vyber_ID(PRODUKT *p,ZAKAZNIK z,float *nakup);
void vyhladavanie(PRODUKT *p,ZAKAZNIK z,float *nakup);
void zapis_do_suboru(PRODUKT *p,ZAKAZNIK z,int i);

void zapis_do_suboru(PRODUKT *p,ZAKAZNIK z,int i){
	FILE *fp;
	fp = fopen("C:\\Users\\Simi\\Desktop\\cviko1\\kupeny_tovar.txt","a");
	
	if(fp == NULL){
		printf("Subor neexistuje");
		exit(1);
	}
	fprintf(fp,"ID: %d\n Nazov: %s\n Vyrobca: %s\n Pocet kusov na sklade: %d\n Cena vyrobku: %.2f\n ",z.kupene[i].ID,z.kupene[i].nazov,z.kupene[i].vyrobca,z.kupene[i].pocet,z.kupene[i].cena);
	fclose(fp);
}
void vyber_ID(PRODUKT *p,ZAKAZNIK z,float *nakup)
{	FILE *f2;
	int id,ID=0,sklad,i=0;
	char vyber[1];
	char kupi[] = "A";
	char nekupi[] = "N";
//	float nakup;

	
	printf("Zadajte ID cislo vyrobku o ktory mate zaujem\n");
	scanf("%d",&id);
	ID = id - 1;
	printf("ID :%d\n nazov: %s\n vyrobca: %s\n pocet: %d\n cena: %.2f\n",p[ID].ID,p[ID].nazov,p[ID].vyrobca,p[ID].pocet,p[ID].cena);
		if(p[ID].pocet>0)
		{
		
			printf("Vyrobok je na sklade v pocte kusov: %d\n Cena vyrobku: %.2f\n",p[ID].pocet,p[ID].cena);
			printf("Ak chcete vyrobok kupit zadajte 'A' \nak nie zadajte 'N'\n");
			scanf("%s",vyber);
			
			if (strcmp(vyber,kupi) == 0)
			{	
					
					printf("ID nacitane je %d\n ",ID+1);
					p[ID].pocet = p[ID].pocet - 1;
					z.kupene[i] = p[ID] ;
					
					printf("Vypis kupenych produktov:\n ID:%d\n nazov:%s\n vyrobca: %s\n kusy:%d\n cena:%2.f\n ",z.kupene[i].ID,z.kupene[i].nazov,z.kupene[i].vyrobca,z.kupene[i].pocet,z.kupene[i].cena);
					printf("Aktualny rozpocet: %.2f\n",z.rozpocet);
					
			
					
					if(0 < (z.rozpocet-p[ID].cena)){
						z.rozpocet -=  p[ID].cena;
						printf("Rozpocet po nakupe: %.2f\n",z.rozpocet);
						*nakup += p[ID].cena;
						printf("V eshope ste zatial minuli %.2f\n",*nakup);
						}
						
					else {
						printf("Prekrocili ste hranicu rozpoctu\nAktualny rozpocet%.2f€\n V eshope ste minuli%.2f",z.rozpocet,*nakup);
						exit(1);
					}					
					zapis_do_suboru(p,z,i);
					i++;
					vyhladavanie(p,z,nakup);
		
				
			}	
			if (strcmp(vyber,nekupi) == 0)
			{
				//printf("ID nacitane je %d\n a produkt %d\n",ID+1,p[ID].pocet);
				//p[ID].pocet = p[ID].pocet -1;
				//z.kupene[i] = p[ID] ;
				//printf("Vypis kupenych produktov: ID%d\n nazov:%s\n vyrobca: %s\n kusy:%d\n cena:%2.f\n ",z.kupene[i].ID,z.kupene[i].nazov,z.kupene[i].vyrobca,z.kupene[i].pocet,z.kupene[i].cena);
				//printf("Aktualny rozpocet: %.2f\n",z.rozpocet);
				
//
//				printf("Rozpocet po nakupe: %.2f\n",z.rozpocet);
//				zapis_do_suboru(p,z,i);
//				i++;
				vyhladavanie(p,z,nakup);
				
			}
		}
		else 
		{
			printf("Vyrobok  nie je na sklade");
			vyhladavanie(p,z,nakup);
		}
}

void vyhladavanie(PRODUKT *p,ZAKAZNIK z,float *nakup)
{	char nazov[20];
	char vyrobca[20]; 
	int porovnanie1 =0, porovnanie2=0;
	int ID = 0;
	int i;
	int moznost=0;

	
	printf("Ak chcete vyhladat produkt podla nazvu zadajte '1' \nAk chcete vyhladat produkt podla vyrobku zadajte '2'\nAk chcete ukoncit nakup zadajte '3'\n ");
	scanf("%d",&moznost);	
	
	if(moznost == 1)
	{
		printf("Zadajte nazov vyrobku:\n");
		scanf("%s",&nazov);
		
		for(i=0;i<10;i++)
			{
				porovnanie1 = strcmp(nazov,p[i].nazov);
				if(porovnanie1 == 0) //ak sa dve slova rovnaju
				{	
					printf("ID :%d\n nazov: %s\n vyrobca: %s\n pocet: %d\n cena: %.2f\n",p[i].ID,p[i].nazov,p[i].vyrobca,p[i].pocet,p[i].cena);
				}
			}
		vyber_ID(p,z,nakup);	
	}
	if(moznost == 2)
	{
		printf("Zadajte vyrobca vyrobku:\n");
		scanf("%s",&vyrobca);
		
		for(i=0;i<10;i++)
			{
				porovnanie2 = strcmp(vyrobca,p[i].vyrobca);
				if(porovnanie2 == 0)
				{
				printf("ID :%d\n nazov: %s\n vyrobca: %s\n pocet: %d\n cena: %.2f\n",p[i].ID,p[i].nazov,p[i].vyrobca,p[i].pocet,p[i].cena);
				
				}
			}

		vyber_ID(p,z,nakup);	
	}	
	else if(moznost == 3) 
	{
		printf("Ukoncili ste nakup\n");
		printf("V eshope ste minuli%.2f",*nakup);
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
	
	printf("Zadaj meno:\n");
	scanf("%s",&z1.meno);
	printf("Zadaj priezvisko:\n");
	scanf("%s",&z1.priezvisko);
	printf("Zadaj vyska rozpoctu:\n");
	scanf("%f",&z1.rozpocet);	
	
/*	ZAKAZNIK z1;
	strcpy(z1.meno,"Janka");
	strcpy(z1.priezvisko,"Novomestka");
	z1.rozpocet = 50.50;
	printf("Zakaznik:\nMeno: %s\nPriezvisko: %s\nRozpocet:%.2f\n",z1.meno,z1.priezvisko,z1.rozpocet);
*/	 
	 
//printf("Kupene:%int",z1.kupene.nazov,z1.kupene.vyrobca);
	vyhladavanie(p,z1,&nakup);
//	zapis_do_suboru(p,z);
	return 0;
}

