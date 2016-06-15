#include<stdio.h>
#include "funcoes.h"

int aloca_navio(int jogador1[][TAM], int tam, int x, int y, char direcao) //aloca os navios nas posicoes desejadas
{
    int i, j, ok, modx, mody, origx, origy;

    origx = x; //x = posx
    origy = y; //y = posy

    switch (direcao)
    {
        case 'N': mody = 0; modx = -1; break;
        case 'S': mody = 0; modx = 1; break;
        case 'L': mody = 1; modx = 0; break;
        case 'O': mody = -1; modx = 0; break;
    }

    ok = 0;

    for(i = 0; i<tam; i++)
    {
        if(jogador1[x][y] != 0 || x > TAM-1 || x < 0 ||  y > TAM-1 || y < 0 )
            ok = 1;

        x+=modx;
        y+=mody;

    }

    if (ok == 0)
    {
        for(i = 0; i<tam; i++)
        {
            jogador1[origx][origy] = 1;
            origx+=modx;
            origy+=mody;
        }
    }

    return ok;

}

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
	for(i = 0; i < TAM; i++)
        printf("%02d ", i);
	printf("\n");
}

void imprimetabuleiro(int jogador1[][TAM], int jogador2[][TAM], int id1, int id2) //imprime o tabuleiro dos 2 jogadores
{
	int i, j;

	printf("\t* * * * *  J O G A D O R %d  * * * * * \n\n", id1); //imprime o nome da malha
	printf("     ");

	imprimenum();
	imprimelinha();

	for(i = 0; i < TAM; i++) //percorre um caminho 15X15
	{
		printf("%02d ", i); //imprime a númeração ao lado do tabuleiro

		printf("| "); //imprime traço no inicio da linha

		for(j = 0; j < TAM; j++) //imprime os elementos do tabuleiro
			printf(" %d ", jogador1[i][j]);

		printf("|\n"); //imprime traço no final da linha
	}

	imprimelinha();

	printf("\n\n");


	printf("\t~ ~ ~ ~ ~ J O G A D O R %d ~ ~ ~ ~ ~ \n\n", id2); //imprime o nome da malha
	printf("     ");

	imprimenum();
	imprimelinha();

	for(i = 0; i < TAM; i++) //percorre um caminho 15X15
	{
		printf("%02d ", i); //imprime a númeração ao lado do tabuleiro

		printf("| "); //imprime traço no inicio da linha

		for(j = 0; j < TAM; j++) //imprime os elementos do tabuleiro
			printf(" %d ", jogador2[i][j]);

		printf("|\n"); //imprime traço no final da linha
	}

	imprimelinha();

}

void creditos() //creditos do jogo
{
	printf("**Feito por Ermeson Davi**\n\n");
}


void conta_navios(int jogador1v[][TAM], int jogador2v[][TAM], int contador1, int contador2)
{
    int i, j;
    //*ptr_contador1 = *ptr_contador2 = 20; printf("%d ", jogador2v[i][j]),

    for(i = 0; i < TAM; i++)
    {
        for(j = 0; j < TAM; j++)
        {
            if (jogador1v[i][j] == 1)
                contador1--;
            if (jogador2v[i][j] == 1)
                contador2--;
        }
    }

    printf("Falta %d alvos para voce ganhar!\n\n", contador2);
    printf("Falta %d alvos para o computador ganhar!\n\n", contador1);
    system("pause");

    if(contador1 <= 0)
    {
        printf("O computador ganhou!\n\n");
        system("pause");
        exit(0);
    }

    if(contador2 <= 0)
    {
        printf("Jogador 1 ganhou!\n\n");
        system("pause");
        exit(0);
    }


}
