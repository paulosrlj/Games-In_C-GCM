/* Implementação das funções */

#include "batalhaNaval.h"




/* Criar tabuleiro */
Tabuleiro *criarTabuleiro(){
	Tabuleiro *t = (Tabuleiro*) malloc(sizeof(Tabuleiro));
	
	/*int i, j;
	for(i = 0; i< TAM; i++)
		for(j = 0; j < TAM; j++)
			t->tab[i][j] = '~';*/
	
	return t;
}

void inicializaTab(char *tab){
	int i, j;
	for(i = 0; i< TAM; i++)
		for(j = 0; j < TAM; j++)
			tab[i][j] = '~';
}

void posMachineShips(Tabuleiro *tab){
	int i, j, k;
	int num = 0;
		
	/* Corveta */
	num = rand() % (TAM*TAM) + 1;
	
	while(checkShip(tab, num, 'c') == TRUE)
		num = rand() % (TAM*TAM) + 1;

	for(k = 0; k < Cj; k++){
		tab->tab[num/10][num%10+k] = 'C';
	}
	
	/* Submarino */
	num = rand() % (TAM*TAM) + 1;
	while(checkShip(tab, num, 's') == TRUE)
		num = rand() % (TAM*TAM) + 1;
	
	for(k = 0; k < Sj; k++){
		tab->tab[num/10][num%10+k] = 'S';
	}
	
	/* Fragrata */
	while(checkShip(tab, num, 'f') == TRUE)
		num = rand() % (TAM*TAM) + 1;
	
	for(k = 0; k < Fj; k++){
		tab->tab[num/10][num%10+k] = 'F';
	}
	
	/* Destroyer */
	while(checkShip(tab, num, 'd') == TRUE)
		num = rand() % (TAM*TAM) + 1;
	
	for(k = 0; k < Dj; k++){
		tab->tab[num/10][num%10+k] = 'D';
	}
	
	/* Porta aviões */
	while(checkShip(tab, num, 'p') == TRUE)
		num = rand() % (TAM*TAM) + 1;
	
	for(i = 0; i < Pi; i++){
		for(j = 0; j < Pj; j++){
			tab->tab[num/10+i][num%10+j] = 'P';
		}
	}
	
	/* Bóia */
	for(k = 0; k < 3; k++){
		while(checkShip(tab, num, 'p') == TRUE)
			num = rand() % (TAM*TAM) + 1;
	
		tab->tab[num/10][num%10] = 'B';
	}
}


void posPlayerShips(Tabuleiro *tab){
	int i, j, k;
	int menu, menu1, menu2 = 0;
	int corv, sub, frag, dest, port = 1;
	int boia = 1;
	
	while (menu != 6){
		printf("Escolha o que deseja fazer: \n");
		printf("[1] - Posicionar navios\n");
		printf("[2] - Reposicionar navios\n");
		printf("[3] - Apagar todos os navios posicionados\n");
		printf("[4] - Imprimir tabuleiro\n");
		printf("[5] - Iniciar Jogo\n");
		printf("[6] - Sair\n"); scanf("%d", &menu);
		
		switch(menu){
			case 1:
				
				while(menu1 != 7){
					printf("Existem %d navios para serem posicionados.", corv+sub+frag+dest+port+boia);
					printf("[1] - Posicionar corveta | %dx\n", corv);
					printf("[2] - Posicionar submarino | %dx\n", corv);
					printf("[3] - Posicionar fragrata | %dx\n", corv);
					printf("[4] - Posicionar destroyer | %dx\n", corv);
					printf("[5] - Posicionar porta-aviões | %dx\n", corv);
					printf("[6] - Posicionar bóia | %dx\n", corv);
					printf("[7] - Voltar\n"); scanf("%d", &menu1);
					
					switch(menu1){
						case 1:
							
						break;
					}
				}
				
			break;
		}
	}
}

int checkShip(Tabuleiro *tab, int num, char tipo){
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
void imprimir(char *tab){
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
