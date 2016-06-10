#include <stdio.h>
#include "funcoes.c"

int main()
{
	int opcao, i, j;
	int id1 = 1, id2 = 2;
	int jogador1[MAX][MAX], jogador2[MAX][MAX];
	
	for(i = 0; i < MAX; i++) //inicializa valores da matriz jogador1
	{
		for(j = 0; j < MAX; j++)
			jogador1[i][j] = 1;
	}
	
	for(i = 0; i < MAX; i++) //inicializa valores da matriz jogador2
	{
		for(j = 0; j < MAX; j++)
			jogador2[i][j] = 2;
	}
	
	//menu do jogo
	do
	{
		printf("\t   BATALHA NAVAL\n\n\tEscolha uma opcao!\n\t   1. Novo Jogo\n\t   2. Creditos\n\t   3. Sair\n\n");
		scanf("%d", &opcao);
		
		switch(opcao) 
		{
			case 1: imprimetabuleiro(jogador1, jogador2, id1, id2); break; 
			case 2: creditos(); break; 
			case 3: exit(0); break;
			default: printf("Digite uma opcao valida!\n\n"); break;
		}
	}while (opcao != 1 && opcao != 2 && opcao != 3);
	
	return 0;
}
