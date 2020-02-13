#define TRUE 1
#define FALSE 0

//imprimir;

void imprimir(int jogo[3][3]);

// procedimento de jogo;

void jogar(char jogador[50], int jogo[3][3]);

////Limpa a matriz e transformar vencedor em FALSE;

void iniciar(int jogo[3][3]);

//verifica

int verificaD(int jogo[3][3]);

int verificaC(int jogo[3][3]);

int verificaL(int jogo[3][3]);

void menuVelha ();
