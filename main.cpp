#include "CSpi.h"
#include <iostream>
#include <string.h>

using namespace std;


int main()
{
	CSpi spi('0',250000);
	
	char tab[20];
	while(1)
	{
		spi.lire(tab,1);
		tab[1]=0;
		printf(tab);
	}
	
	//strcpy(tab, "Hello World !!!\n");
		
	//spi.ecrire(tab,16);
}
