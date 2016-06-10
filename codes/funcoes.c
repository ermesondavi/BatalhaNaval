#include<stdio.h>
#include "funcoes.h"

void imprimelinha() //imprime as linhas no começo ou fim do tabuleiro
{
	int i;
	printf("     ");
	for (i = 0; i < 22; i++)
		printf(" -");
	printf("\n");
}

void imprimenum() //imprime numeros no inicio do tabuleiro
{
	int i;
	printf(" ");
	for(i = 0; i < MAX; i++)
        printf("%02d ", i + 1);
	printf("\n");
}

void imprimetabuleiro(int jogador1[][MAX], int jogador2[][MAX], int id1, int id2) //imprime o tabuleiro dos 2 jogadores
{
	int i, j;

	printf("\t* * * * *  J O G A D O R %d  * * * * * \n\n", id1); //imprime o nome da malha
	printf("     ");

	imprimenum();
	imprimelinha();

	for(i = 0; i < MAX; i++) //percorre um caminho 15X15
	{
		printf("%02d ", i + 1); //imprime a númeração ao lado do tabuleiro

		printf("| "); //imprime traço no inicio da linha

		for(j = 0; j < MAX; j++) //imprime os elementos do tabuleiro
			printf(" %d ", jogador1[i][j]);

		printf("|\n"); //imprime traço no final da linha
	}

	imprimelinha();

	printf("\n\n");


	printf("\t~ ~ ~ ~ ~ J O G A D O R %d ~ ~ ~ ~ ~ \n\n", id2); //imprime o nome da malha
	printf("     ");

	imprimenum();
	imprimelinha();

	for(i = 0; i < MAX; i++) //percorre um caminho 15X15
	{
		printf("%02d ", i + 1); //imprime a númeração ao lado do tabuleiro

		printf("| "); //imprime traço no inicio da linha

		for(j = 0; j < MAX; j++) //imprime os elementos do tabuleiro
			printf(" %d ", jogador2[i][j]);

		printf("|\n"); //imprime traço no final da linha
	}

	imprimelinha();

}

void creditos() //creditos do jogo
{
	printf("**Feito por Ermeson Davi**\n\n");
}
