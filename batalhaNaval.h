/* Protótipo das funções */

#define TAM 14 //Tabuleiro 10x10

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TRUE 1
#define FALSE 0

#define Ci 1 //Linhas ocupadas pela corveta
#define Cj 2 //Colunas ocupadas pela corveta

#define Si 1 //Submarino
#define Sj 3

#define Fi 1 //Fragata
#define Fj 3 

#define Di 1 //destroyer
#define Dj 4

#define Pi 2 //Porta-aviões
#define Pj 6 

#define Bi 1 //Bóia
#define Bj 1


typedef struct tabuleiro Tabuleiro;

struct tabuleiro {
	char tab[TAM*TAM];
	char gabarito[TAM*TAM];
	char tabMaq[TAM*TAM];
	char gabaritoMaq[TAM*TAM];
};

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


/* Cria o tabuleiro */
Tabuleiro *criarTabuleiro();

void inicializaTab(char *tab);

/* Posiciona os navios da máquina */
void posMachineShips(char *tab);

/* Posicionar os navios do jogador */
void posPlayerShips(Tabuleiro *tab);

/* Imprime o tabuleiro */
void imprimir(char *tab);

/* Verifica se a posição já não é usada */
int checkShip(char *tab, int num, char tipo);
