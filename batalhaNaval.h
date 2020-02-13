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
1 Porta-Aviões;  2x6 */

char playerTab[TAM*TAM];		//onde a máquina vai jogar
char playerGab[TAM*TAM];		//onde seráo guardado os navios do jogador
char machineTab[TAM*TAM];	
char machineGab[TAM*TAM];


/* Inicializar o tabuleiro com água */
void inicializaTab(char *tab);

/* Posiciona os navios da máquina */
void prepareMShips(char *machineGab);

/* Posicionar os navios do jogador */
int posPlayerShips(char *playerGab);

/* Verifica se a posição já não é usada */
int checkShip(char *tab, int num, char tipo);

/* Posiciona o tipo de navio na posição indicada*/
void setShip(char *gabTab, char type, int pos);

/* Joga */
void play(char *playerTab, char *playerGab, char *machineTab, char *machineGab);

/* Verifica se o jogador ou a máquina fez uma jogada repitida */
int checkMove(char *Tab, int position);

/* Verifica se a posição informada pelo jogador é valida */

int posicaoValida(int pos);

/* Verifica se o jogador ou máquina acertou um navio */
int hitAShip(char *gabTab, int position);


/* Imprime o tabuleiro */
void imprimirTab(char *tab);

