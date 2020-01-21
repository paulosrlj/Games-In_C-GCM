/* Implementação das funções */

#include "batalhaNaval.h"

struct tabuleiro {
	char tab[TAM][TAM];
	char gabarito[TAM][TAM];
};


/* Criar tabuleiro */
Tabuleiro *criarTabuleiro(){
	Tabuleiro *t = (Tabuleiro*) malloc(sizeof(Tabuleiro));
	
	int i, j;
	for(i = 0; i< TAM; i++)
		for(j = 0; j < TAM; j++)
			t->tab[i][j] = '~';
	
	return t;
}

void posMachineShips(Tabuleiro *tab){
	int i, j, k;
	int num = 0;
		
	/* Corveta */
	num = rand() % (TAM*TAM);
	
	while(verificaNum(tab, num, 'c') == TRUE)
		num = rand() % (TAM*TAM);

	for(k = 0; k < Cj; k++){
		tab->tab[num/10][num%10+k] = 'c';
	}
	
	/* Submarino */
	num = rand() % 100;
	while(verificaNum(tab, num, 's') == TRUE)
		num = rand() % (TAM*TAM);
	
	for(k = 0; k < Sj; k++){
		tab->tab[num/10][num%10+k] = 's';
	}
	
	/* Fragrata */
	while(verificaNum(tab, num, 'f') == TRUE)
		num = rand() % (TAM*TAM);
	
	for(k = 0; k < Fj; k++){
		tab->tab[num/10][num%10+k] = 'f';
	}
	
	/* Destroyer */
	while(verificaNum(tab, num, 'd') == TRUE)
		num = rand() % (TAM*TAM);
	
	for(k = 0; k < Dj; k++){
		tab->tab[num/10][num%10+k] = 'd';
	}
	
	/* Porta aviões */
	while(verificaNum(tab, num, 'p') == TRUE)
		num = rand() % (TAM*TAM);
	
	for(i = 0; i < Pi; i++){
		for(j = 0; j < Pj; j++){
			tab->tab[num/10+i][num%10+j] = 'p';
		}
	}
	
	/* Bóia */
	while(verificaNum(tab, num, 'p') == TRUE)
		num = rand() % (TAM*TAM);
	
	tab->tab[num/10][num%10] = 'b';
}

int verificaNum(Tabuleiro *tab, int num, char tipo){
	int i, j, k;
	
	switch(tipo){
		//Corveta
		case 'c':
			for(k = 0; k < Cj; k++){
				if(tab->tab[num/10][num%10+k] != '~')
					return TRUE;
			}
			return FALSE;
		break;
		
		//Submarino
		case 's':
			for(k = 0; k < Sj; k++){
				if(tab->tab[num/10][num%10+k] != '~')
					return TRUE;
			}
			return FALSE;		
		break;
		
		//Fragrata
		case 'f':
			for(k = 0; k < Fj; k++){
				if(tab->tab[num/10][num%10+k] != '~')
					return TRUE;
			}
			return FALSE;		
		break;
		
		//Destroyer
		case 'd':
			for(k = 0; k < Dj; k++){
				if(tab->tab[num/10][num%10+k] != '~')
					return TRUE;
			}
			return FALSE;		
		break;
		
		//Porta aviões
		case 'p':
			for(i = 0; i < Pi; i++){
				for(j = 0; j < Pj; j++){
					if(tab->tab[num/10+i][num%10+j] != '~')
						return TRUE;
				}		
			}
			return FALSE;		
		break;
		
		case 'b':
			if(tab->tab[num/10][num%10] != '~')
				return TRUE;
			return FALSE;
		break;
	}
}

/* Imprimir */
void imprimir(Tabuleiro *tab){
	int i, j;
	printf("    ");
	printf("0 1 2 3 4 5 6 7 8 9 10 11 12 13\n");


	printf("     ");
	printf("------------------------------\n");
		
	for(i = 0; i < TAM; i++){
		if(i <= 9)
			printf(" [%d]| ",i);
		else
			printf("[%d]| ",i);
		
		for(j = 0; j< TAM; j++){
			printf("%c ", tab->tab[i][j]);
		} 
		printf("\n");
	}
	printf("\n");
}
