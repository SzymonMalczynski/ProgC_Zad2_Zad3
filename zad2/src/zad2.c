/*
 ============================================================================
 Name        : zad2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================


 Dotychczas zajmowaliśmy się sytuacją, gdy wskaźnik wskazywał na jakąś zmienną.
 Jednak nie tylko zmienna ma swój adres w pamięci. Oprócz zmiennej
 także i funkcja musi mieć swoje określone miejsce w pamięci.
 A ponieważ funkcja ma swój adres[6], to nie ma przeszkód, aby i na nią wskazywał jakiś wskaźnik.








 */

#include <stdio.h>
#include <stdlib.h>

int suma(int a, int b)
	{
		return a+b;
	}

int iloraz(int a, int b)
	{
		return a/b;
	}

void funkcja(int a,int b,int (*wsk)(int a1, int b2))
	{
		if((*wsk)==(1,1))
		{
			wsk=suma;
			 printf("%d+%d=%d\n",a,b,wsk(a,b));
		}
		else
		{
			wsk=iloraz;
			printf("%d/%d=%d\n",a,b,wsk(a,b));
		}

	}


int main(void) {
	puts("!!!Hello Wodrld!!!"); /* prints !!!Hello World!!! */

	 int (*wsk)(int a, int b);
	 wsk=suma;

	 printf("4+5=%d\n", wsk(4,5));

	 wsk=iloraz;

	 printf("20/5=%d\n", wsk(20,5));

	 // Zadanie 3

	 // Jezeli wsk(1,1) to bedzie suma inne wartosci beda oznaczaly iloraz :)
	 funkcja(3,3,wsk(1,1));

	 funkcja(100,5,wsk(1,2));


	 funkcja(1000,5,suma);
	 funkcja(10000,5,iloraz);
	 funkcja(100000,5,NULL);
	 // Tak program sie kompiluje w funkcji przekazujemy adresy do funkcji suma, iloraz
	 //poniewaz zgadzaja sie typy zmiennych , aczkolwiek gdy tak przekaze agrument moj program nie
	 //dziala poprawnie

	return EXIT_SUCCESS;
}


