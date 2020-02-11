/* Protótipo das funções */

#define TAM 14 //Tabuleiro 10x10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define C 2 //Colunas ocupadas pela corveta

#define S 3 //Submarino

#define F 3 //Fragrata

#define D 4 //Destroyer

#define Pi 2 //Porta-aviões
#define Pj 6 

/* ~ -> água
   * -> tiro foi dado e não havia nada
   X -> tiro foi dado e acertou */
   
/* Cada jogador possui 6 navios:
1 Corveta; 		 1x2
1 Submarino; 	 1x3
1 Fragata; 		 1x3
1 Destroyer; 	 1x4
1 Cruzador; 	 1x5
1 Porta-Aviões;  2x6 */

char playerTab[TAM*TAM];		//onde a máquina vai jogar
char playerGab[TAM*TAM];		//onde seráo guardado os navios do jogador
char machineTab[TAM*TAM];	
char machineGab[TAM*TAM];


/* Inicializar o tabuleiro com água */
void inicializaTab(char *tab);

/* Posiciona os navios da máquina */
void prepareMShips(char *machineTab, char *machineGab);

/* Posicionar os navios do jogador */
void posPlayerShips(char *playerTab, char *playerGab);

/* Verifica se a posição já não é usada */
int checkShip(char *tab, int num, char tipo);

/* Posiciona o tipo de navio na posição indicada*/
void setShip(char *playTab, char *gabTab, char type, int pos);

/* Imprime o tabuleiro */
void imprimir(char *tab);

