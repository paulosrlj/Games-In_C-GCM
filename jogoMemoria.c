//inserção das bibliotecas

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define TAM 6

int main(void){
	
	int a = 0,b = 0,acertos = 0;
	char f;
	int numeros[6];
	int respostas[6];
	
//inclusao de linguagem
setlocale(LC_ALL,"Portuguese");

//inclusão de titulo no console;
setconsoletitle("jogo da memoria");

//gera os numeros aleatórios
srand(time(NULL));

printf("O programa gera 6 numeros aleatorios entre 1 e 25\n");
printf("Decore os numeros exibidos, e após cinco segundos \nreescreva-os na tela na mesma ordem\n");
printf("Start Game -[ENTER]");

//corresponde ao enter, com o valor de 13 pela tabela ascii
do{
	f = getch();
}while(f != 13);

for(a = 0; a < TAM ; a++){
	numeros[a] = (rand() % 25) + 1;
}


}
