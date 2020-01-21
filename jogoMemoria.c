//inserção das bibliotecas

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

int main(void){
	
	int a = 0,b = 0,acertos = 0;
	char c;
	int numeros [5];
	int respostas;
	
//inclusao de linguagem
setlocale(LC_ALL,"Portuguese");

//inclusão de titulo no console;
setconsoletitle("jogo da memoria");

//gera os numeros aleatórios
srand(time(NULL));

printf("O programa gera 6 numeros aleatorios entre 1 e 25\n");
printf("Decore os numeros exibidos, e após cinco segundos \nreescreva-os na tela na mesma ordem\n");
printf("Start Game -[ENTER]");

}
