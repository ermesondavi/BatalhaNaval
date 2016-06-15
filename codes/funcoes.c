#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "funcoes.h"


//===============================================FUNCOES DE ALOCACAO============================================================//
void aloca_ale(int jogador2[][TAM]) //aloca navios aleatoriamente
{
    srand(time(NULL));
    int i, posx, posy, randomico,  resultado, tamanho = 1;
    char direcao;

    for(i = 1; i < 11; i++)
    {

        do
        {
            posx = rand() % 15; //sorteia as posicoes dos navios
            posy = rand() % 15;
            randomico = rand() % 4; //sorteia a direcao dos navios

            switch(i) //muda tamanho dos navios
            {
                case 1: tamanho = 1; break;
                case 5: tamanho = 2; break;
                case 8: tamanho = 3; break;
                case 10: tamanho = 4; break;
            }

            switch (randomico) //muda as direcoes dos navios
            {
                case 0: direcao = 'N' ; break;
                case 1: direcao = 'S' ; break;
                case 2: direcao = 'L' ; break;
                case 3: direcao = 'O' ; break;
            }

        }while(posx < 0 && posx > TAM-1 || posy < 0 && posy > TAM-1 || direcao != 'N' && direcao != 'S' && direcao != 'L' && direcao != 'O');

        resultado = aloca_navio(jogador2, tamanho, posx, posy, direcao); //chama funcao para colocar os navios nos seus lugares

        if(resultado != 0) //se nao deu certo, ele tente alocar novamente
                i--;
    }
}

void aloca_pedido(int jogador1[][TAM]) //aloca navios conforme desejo do jogador
{
    srand(time(NULL));
    int i, posx, posy, randomico,  resultado, tamanho = 1;
    char direcao, nome[20];

    for(i = 1; i < 11; i++)
    {

        switch(i) //muda nomes e tamanho dos navios
        {
            case 1: strcpy(nome, "Submarino"), tamanho = 1; break;
            case 5: strcpy(nome, "Corveta"), tamanho = 2; break;
            case 8: strcpy(nome, "Fragata"), tamanho = 3; break;
            case 10: strcpy(nome, "Porta-Aviao"), tamanho = 4; break;
        }

        do //escolhe posicao para os navios
        {
            printf("Escolha posicao (x y) entre 0 - 14 para %s %d\n", nome, i);
            scanf("%d %d", &posx, &posy);
            printf("Escolha uma direcao(N, S, L ou O)\n");
            scanf(" %c", &direcao);

        } while (posx < 0 && posx > TAM-1 || posy < 0 && posy > TAM-1 || direcao != 'N' && direcao != 'S' && direcao != 'L' && direcao != 'O');

        resultado = aloca_navio(jogador1, tamanho, posx, posy, direcao); //chama funcao para colocar os navios nos seus lugares

        if(resultado == 0) //se nao deu certo, ele tente alocar novamente
            printf("A alocacao foi bem sucedida!\n\n");
        else
        {
            printf("A alocacao foi mal sucedida! Digite algo valido\n\n");
            i--;
        }
    }
}


int aloca_navio(int jogador1[][TAM], int tam, int x, int y, char direcao) //aloca os navios nas posicoes desejadas
{
    int i, j, ok, modx, mody, origx, origy;

    origx = x;
    origy = y;

    switch (direcao) //seta as variaveis conforme a direcao escolhida
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
//===============================================FUNCOES DE ALOCACAO============================================================//

//===============================================FUNCOES DE IMPRESSAO============================================================//
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

void imprimetabuleiro(int jogador1[][TAM], int jogador2[][TAM]) //imprime o tabuleiro dos 2 jogadores
{
	int i, j;

	printf("\t* * * * *  J O G A D O R * * * * * \n\n"); //imprime o nome da malha
	printf("     ");

	imprimenum();
	imprimelinha();

	for(i = 0; i < TAM; i++) //percorre um caminho 15X15
	{
		printf("%02d ", i); //imprime a numeracao ao lado do tabuleiro

		printf("| "); //imprime traco no inicio da linha

		for(j = 0; j < TAM; j++) //imprime os elementos do tabuleiro
			printf(" %d ", jogador1[i][j]);

		printf("|\n"); //imprime traco no final da linha
	}

	imprimelinha();

	printf("\n\n");


	printf("\t~ ~ ~ ~ ~ C O M P U T A D O R ~ ~ ~ ~ ~ \n\n"); //imprime o nome da malha
	printf("     ");

	imprimenum();
	imprimelinha();

	for(i = 0; i < TAM; i++) //percorre um caminho 15X15
	{
		printf("%02d ", i); //imprime a numeracao ao lado do tabuleiro

		printf("| "); //imprime traco no inicio da linha

		for(j = 0; j < TAM; j++) //imprime os elementos do tabuleiro
			printf(" %d ", jogador2[i][j]);

		printf("|\n"); //imprime traco no final da linha
	}

	imprimelinha();

}
//===============================================FUNCOES DE IMPRESSAO============================================================//

void creditos() //creditos do jogo
{
	printf("**Feito por Ermeson Davi**\n\n");
}


//================================================FUNCOES DOS TIROS=============================================================//
void tiro_jogador(int jogador1v[][TAM], int jogador2v [][TAM], int jogador2[][TAM], int *ptr_acertou)
{
    int tirox, tiroy;
    int contador1, contador2;
    contador1 = contador2 = 20;


    printf("Onde voce quer atirar? (x y)\n");
    scanf("%d %d", &tirox, &tiroy);


    if(tirox < 0 || tirox > TAM-1 || tiroy < 0 || tiroy > TAM-1) //testa se as coordenadas sao validas
    {
        *ptr_acertou = 1;
        printf("Escolha coordenada valida!\n\n");
    }

    else if(jogador2v[tirox][tiroy] == 2 || jogador2v[tirox][tiroy] == 1) //testa se ja atirou ou se tem barco neste local
    {
        *ptr_acertou = 1;
        printf("Dica: Atire onde voce ainda nao atirou!\n\n");
    }

    else if(jogador2[tirox][tiroy] == 1) //coloca tiro no canto certo
    {
        *ptr_acertou = 1;
        jogador2v[tirox][tiroy] = 1;
        imprimetabuleiro(jogador1v, jogador2v);
        printf("Voce acertou! Jogue novamente\n\n");
        system("pause");
        conta_navios(jogador1v, jogador2v, contador1, contador2);
    }

    else //passa a vez para IA
    {
        *ptr_acertou = 0;
        jogador2v[tirox][tiroy] = 2;
        imprimetabuleiro(jogador1v, jogador2v);
        printf("Voce errou! Agora eh a vez do computador!\n\n");
        system("pause");
    }

}


void tiro_IA(int jogador1v[][TAM], int jogador2v [][TAM], int jogador1[][TAM], int *ptr_acertou)
{
    int tirox, tiroy;
    int contador1, contador2;
    contador1 = contador2 = 20;

    tirox = rand() % 15;
    tiroy = rand() % 15;

    if(tirox < 0 || tirox > TAM-1 || tiroy < 0 || tiroy > TAM-1) //testa se as coordenadas sao validas
        *ptr_acertou = 1;

    else if(jogador1v[tirox][tiroy] == 2 || jogador1v[tirox][tiroy] == 1) //testa se ja atirou ou se tem barco neste local
        *ptr_acertou = 1;


    else if(jogador1[tirox][tiroy] == 1)
    {
        *ptr_acertou = 1;
        jogador1v[tirox][tiroy] = 1;
        imprimetabuleiro(jogador1v, jogador2v);
        printf("O computador acertou!\n\n");
        system("pause");
        conta_navios(jogador1v, jogador2v, contador1, contador2);
    }

    else
    {
        *ptr_acertou = 0;
        jogador1v[tirox][tiroy] = 2;
        imprimetabuleiro(jogador1v, jogador2v);
        printf("O computador errou!\n\n");
        system("pause");
    }

}

void conta_navios(int jogador1v[][TAM], int jogador2v[][TAM], int contador1, int contador2)
{
    int i, j;

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
        printf("Voce ganhou!\n\n");
        system("pause");
        exit(0);
    }

}
//================================================FUNCOES DOS TIROS=============================================================//
