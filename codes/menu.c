#include <stdio.h>
#include "funcoes.c"

int main()
{
	int opcao, i, j;
	int id1 = 1, id2 = 2;
	int jogador1[MAX][MAX], jogador2[MAX][MAX];
	int posx, posy, posxx, posyy;

	for(i = 0; i < MAX; i++) //inicializa valores da matriz jogador1
	{
		for(j = 0; j < MAX; j++)
			jogador1[i][j] = 0;
	}

	for(i = 0; i < MAX; i++) //inicializa valores da matriz jogador2
	{
		for(j = 0; j < MAX; j++)
			jogador2[i][j] = 0;
	}


//============ALOCACAO DE NAVIOS ========================

//==================JOGADOR1=============================
//SUBMARINOS JOGADOR 1
	for(i = 0; i < 4; i++) //aloca submarinos conforme pedido no campo do jogador1
	{
		do
		{
			printf("Escolha a coordenada do seu submarino %d\n", i+1);
			scanf("%d,%d", &posx, &posy);
		} while(jogador1[posx][posy] == 1 || posx < 0 || posx > MAX -1 || posy < 0 || posy > MAX -1);

		jogador1[posx][posy] = 1; //coloca submarino no local desejado
	}

//CORVETAS JOGADOR1
	for(i = 0; i < 3; i++) //aloca corvetas conforme pedido no campo do jogador1
	{
		do
		{
			printf("Escolha a coordenada da sua corveta %d\n", i+1);
			scanf("%d,%d", &posx, &posy);
		} while(jogador1[posx][posy] == 1 || posx < 0 || posx > MAX -1 || posy < 0 || posy > MAX -1 ||
                jogador1[posx+1][posy+1] == 1 || posx+1 < 0 || posx+1 > MAX -1);

		jogador1[posx][posy] = 1; //coloca corveta no local desejado
		jogador1[posx+1][posy] = 1;
	}

//FRAGATAS JOGADOR1
	for(i = 0; i < 2; i++) //aloca fragatas conforme pedido no campo do jogador1
	{
		do
		{
			printf("Escolha a coordenada da sua fragata %d\n", i+1);
			scanf("%d,%d", &posx, &posy);
		} while(jogador1[posx][posy] == 1 || posx < 0 || posx > MAX -1 || posy < 0 || posy > MAX -1 ||
                jogador1[posx+1][posy] == 1 || posx+1 < 0 || posx+1 > MAX -1 || posy+1 < 0 ||
                jogador1[posx+2][posy] == 1 || posx+2 < 0 || posx+2 > MAX -1 || posy+2 < 0);

		jogador1[posx][posy] = 1; //coloca fragata no local desejado
		jogador1[posx+1][posy] = 1;
		jogador1[posx+2][posy] = 1;
	}

//PORTA-AVIOES JOGADOR1
    for(i = 0; i < 1; i++) //alocar porta-aviao conforme pedido no campo do jogador1
    {

        do
        {
            printf("Escolha a coordenada do seu Porta-Aviao\n");
            scanf("%d,%d", &posx, &posy);
        } while(jogador1[posx][posy] == 1 || posx < 0 || posx > MAX -1 || posy < 0 || posy > MAX -1 ||
                jogador1[posx+1][posy] == 1 || posx+1 < 0 || posx+1 > MAX -1 ||
                jogador1[posx+2][posy] == 1 || posx+2 < 0 || posx+2 > MAX -1 ||
                jogador1[posx+3][posy] == 1 || posx+3 < 0 || posx+3 > MAX -1 );

        jogador1[posx][posy] = 1; //coloca porta-aviao no local desejado
        jogador1[posx+1][posy] = 1;
        jogador1[posx+2][posy] = 1;
        jogador1[posx+3][posy] = 1;

     }


//==================JOGADOR2=============================
//SUBMARINOS JOGADOR2
    for(i = 0; i < 4; i++) //aloca submarinos aleatoriamente no campo do jogador2
	{
		do
		{
		    posxx = rand() % 15;
            posyy = rand() % 15;
		} while(jogador1[posxx][posyy] == 1 || posxx < 0 || posxx > MAX -1 || posyy < 0 || posyy > MAX -1);

		jogador2[posxx][posyy] = 1; //coloca submarino no local desejado
	}

//CORVETAS JOGADOR2
    for(i = 0; i < 3; i++) //alocar corvetas aleatoriamente no campo do jogador2
	{
		do
		{
			posxx = rand() % 15;
            posyy = rand() % 15;
		} while(jogador2[posxx][posyy] == 1 || posxx < 0 || posxx > MAX -1 || posyy < 0 || posyy > MAX -1 ||
                jogador2[posxx+1][posyy] == 1 || posxx+1 < 0 || posxx+1 > MAX -1);

		jogador2[posxx][posyy] = 1; //coloca corvetas no local desejado
		jogador2[posxx+1][posyy] = 1;
	}

//FRAGATAS JOGADOR2
	for(i = 0; i < 2; i++) //aloca fragatas aleatoriamente no campo do jogador2
	{
		do
		{
			posxx = rand() % 15;
            posyy = rand() % 15;
		} while(jogador2[posxx][posyy] == 1 || posxx < 0 || posxx > MAX -1 || posyy < 0 || posyy > MAX -1 ||
                jogador2[posxx+1][posyy] == 1 || posxx+1 < 0 || posxx+1 > MAX -1 ||
                jogador2[posxx+2][posyy] == 1 || posxx+2 < 0 || posxx+2 > MAX -1);

		jogador2[posxx][posyy] = 1; //coloca fragata no local desejado
		jogador2[posxx+1][posyy] = 1;
		jogador2[posxx+2][posyy] = 1;
	}



//PORTA-AVIOES JOGADOR2
     for(i = 0; i < 1; i++)//aloca porta-aviao aleatoriamente no campo do jogador2
     {
        do
        {
            posxx = rand() % 15;
            posyy = rand() % 15;
        } while(jogador2[posxx][posyy] == 1 || posxx < 0 || posxx > MAX -1 || posyy < 0 || posyy > MAX -1 ||
                jogador2[posxx+1][posyy] == 1 || posxx+1 < 0 || posxx+1 > MAX -1 ||
                jogador2[posxx+2][posyy] == 1 || posxx+2 < 0 || posxx+2 > MAX -1 ||
                jogador2[posxx+3][posyy] == 1 || posxx+3 < 0 || posxx+3 > MAX -1);

        jogador2[posxx][posyy] = 1; //coloca porta-aviao no local desejado
        jogador2[posxx+1][posyy] = 1;
        jogador2[posxx+2][posyy] = 1;
        jogador2[posxx+3][posyy] = 1;
     }
//============ALOCACAO DE NAVIOS ========================


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
