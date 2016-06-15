#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.c"

int main()
{
	int opcao, i, j;
	int id1 = 1, id2 = 2;
	int jogador1[TAM][TAM] = {0}, jogador2[TAM][TAM] = {0}, jogador1v[TAM][TAM] = {0}, jogador2v[TAM][TAM] = {0};
    int resultado, randomico;
    int posx, posy;
    int tamanho = 1;
    char direcao, nome[20];
    int acertou = 0, tirox, tiroy; //para poder atirar
    int contador1 = 20, contador2 = 20; // para contar os navios

    srand(time(NULL));

    //ALOCA ALEATORIAMENTE NAVIOS DO JOGADOR2
    for(i = 1; i < 11; i++)
    {

        do
        {
            posx = rand() % 15;
            posy = rand() % 15;
            randomico = rand() % 4;

            switch(i) //muda tamanho
            {
                case 1: tamanho = 1; break;
                case 5: tamanho = 2; break;
                case 8: tamanho = 3; break;
                case 10: tamanho = 4; break;
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
                    for(i = 1; i < 11; i++)
                    {
                        //muda nomes e tamanho
                        switch(i)
                        {
                            case 1: strcpy(nome, "Submarino"), tamanho = 1; break;
                            case 5: strcpy(nome, "Corveta"), tamanho = 2; break;
                            case 8: strcpy(nome, "Fragata"), tamanho = 3; break;
                            case 10: strcpy(nome, "Porta-Aviao"), tamanho = 4; break;
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

                    imprimetabuleiro(jogador1v, jogador2v, id1, id2);


//=============================================LOOP PRINCIPAL DO JOGO===============================================//

                    while(1) //loop principal
                    {

                        do //determina coordenadas do tiro do jogador1
                        {

                            printf("Escolha uma coordenada\n");
                            scanf("%d %d", &tirox, &tiroy);


                            if(tirox < 0 || tirox > TAM-1 || tiroy < 0 || tiroy > TAM-1) //testa se as coordenadas sao validas
                            {
                                acertou = 1;
                                printf("Escolha coordenada valida\n\n");
                            }

                            else if(jogador2v[tirox][tiroy] == 2 || jogador2v[tirox][tiroy] == 1) //testa se ja atirou neste local
                            {
                                acertou = 1;
                                printf("Atire onde voce ainda nao atirou\n\n");
                            }

                            else if(jogador2[tirox][tiroy] == 1) //coloca tiro no canto certo
                            {
                                acertou = 1;
                                jogador2v[tirox][tiroy] = 1;
                                imprimetabuleiro(jogador1v, jogador2v, id1, id2);
                                printf("Voce acertou! Jogue novamente\n\n");
                                //printf("Falta %d alvos\n\n", contador2); //errado, pois ta contando embaixo
                                system("pause");
                            }

                            else //passa a vez para IA
                            {
                                acertou = 0;
                                jogador2v[tirox][tiroy] = 2;
                                imprimetabuleiro(jogador1v, jogador2v, id1, id2);
                                printf("Voce errou!\n\n");
                                system("pause");
                            }


                        //================TESTA QUANTIDADE DE NAVIOS===========================
                            contador1 = contador2 = 20;

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
                            system("pause");


                            if(contador1 <= 0)
                            {
                                printf("Jogador 2 ganhou!\n\n");
                                system("pause");
                                exit(0);
                                break;
                            }

                            if(contador2 <= 0)
                            {
                                printf("Jogador 1 ganhou!\n\n");
                                system("pause");
                                exit(0);
                                break;
                            }

                        }while(acertou == 1);


                        //determina coordenadas do tiro do jogador2
                        do
                        {
                            tirox = rand() % 15;
                            tiroy = rand() % 15;

                            if(tirox < 0 || tirox > TAM-1 || tiroy < 0 || tiroy > TAM-1) //testa se as coordenadas sao validas
                                acertou = 1;


                            else if(jogador1v[tirox][tiroy] == 2 || jogador1v[tirox][tiroy] == 1) //testa se ja atirou neste local
                                acertou = 1;


                            else if(jogador1[tirox][tiroy] == 1)
                            {
                                acertou = 1;
                                jogador1v[tirox][tiroy] = 1;
                                imprimetabuleiro(jogador1v, jogador2v, id1, id2);
                                printf("O computador acertou!\n\n");
                                system("pause");
                            }

                            else
                            {
                                acertou = 0;
                                jogador1v[tirox][tiroy] = 2;
                                imprimetabuleiro(jogador1v, jogador2v, id1, id2);
                                printf("O computador errou!\n\n");
                                system("pause");
                            }

                            //================TESTA QUANTIDADE DE NAVIOS===========================
                            contador1 = contador2 = 20;

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


                            if(contador1 <= 0)
                            {
                                printf("Jogador 2 ganhou!\n\n");
                                system("pause");
                                exit(0);
                                break;
                            }

                            if(contador2 <= 0)
                            {
                                printf("Jogador 1 ganhou!\n\n");
                                system("pause");
                                exit(0);
                                break;
                            }

                        }while(acertou == 1);

                    }

                    break;
//=============================================LOOP PRINCIPAL DO JOGO===============================================//

			case 2: creditos(); break;
			case 3: exit(0); break;
			default: printf("Digite uma opcao valida!\n\n"); break;
		}
	}while(opcao != 1 && opcao != 2 && opcao != 3);

	return 0;
}
