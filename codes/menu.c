#include <stdio.h>
#include <string.h>
#include "funcoes.c"

int main()
{
	int opcao, i, j;
	int id1 = 1, id2 = 2;
	int jogador1[TAM][TAM] = {0}, jogador2[TAM][TAM] = {0};
    int resultado, randomico;
    int posx, posy;
    int tamanho = 1;
    char direcao, nome[20];


//ALOCA ALEATORIAMENTE NAVIOS DO JOGADOR2
    for(i = 1; i < 5; i++)
    {

        do
        {
            posx = rand() % 15;
            posy = rand() % 15;
            randomico = rand() % 4;

            switch(i) //muda tamanho
            {
                case 1: tamanho = 1; break;
                case 2: tamanho = 2; break;
                case 3: tamanho = 3; break;
                case 4: tamanho = 4; ; break;
            }

            switch (randomico)
            {
                case 0: direcao = 'N' ; break;
                case 1: direcao = 'S' ; break;
                case 2: direcao = 'L' ; break;
                case 3: direcao = 'O' ; break;
            }

        }while(posx < 0 && posx > TAM-1 || posy < 0 && posy > TAM-1 || direcao != 'N' && direcao != 'S' && direcao != 'L' && direcao != 'O');

        resultado = aloca_navio(jogador2, tamanho, posx, posy, direcao);

        if(resultado != 0)
                i--;
    }

	//menu do jogo
	do
    {
		printf("\t   BATALHA NAVAL\n\n\tEscolha uma opcao!\n\t   1. Novo Jogo\n\t   2. Creditos\n\t   3. Sair\n\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
                    //ALOCA NAVIOS DO JOGADOR1
                    for(i = 1; i < 5; i++)
                    {
                        //muda nomes e tamanho
                        switch(i)
                        {
                            case 1: strcpy(nome, "Submarino"), tamanho = 1; break;
                            case 2: strcpy(nome, "Corveta"), tamanho = 2; break;
                            case 3: strcpy(nome, "Fragata"), tamanho = 3; break;
                            case 4: strcpy(nome, "Porta-Aviao"), tamanho = 4; ; break;
                        }

                        do
                        {
                            printf("Escolha posicao para %s %d\n", nome, i);
                            scanf("%d %d", &posx, &posy);
                            printf("Escolha uma direcao\n");
                            scanf(" %c", &direcao);

                        } while (posx < 0 && posx > TAM-1 || posy < 0 && posy > TAM-1 || direcao != 'N' && direcao != 'S' && direcao != 'L' && direcao != 'O');

                        resultado = aloca_navio(jogador1, tamanho, posx, posy, direcao);

                        if(resultado == 0)
                                printf("Deu certo %d\n", i);
                        else
                        {
                            printf("Digite algo valido%d\n", i);
                            i--;
                        }
                    }

                    imprimetabuleiro(jogador1, jogador2, id1, id2);

                    break;

			case 2: creditos(); break;
			case 3: exit(0); break;
			default: printf("Digite uma opcao valida!\n\n"); break;
		}
	}while(opcao != 1 && opcao != 2 && opcao != 3);

	return 0;
}
