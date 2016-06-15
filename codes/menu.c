#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "funcoes.c"

int main()
{
	int opcao, i, j;
	int jogador1[TAM][TAM] = {0}, jogador2[TAM][TAM] = {0}, jogador1v[TAM][TAM] = {0}, jogador2v[TAM][TAM] = {0};
    int resultado, randomico;
    int posx, posy;
    int tamanho = 1;
    char direcao, nome[20];
    int alocacao;

    int acertou = 0, tirox, tiroy; //para poder atirar
    int contador1 = 20, contador2 = 20; // para contar os navios

    aloca_ale(jogador2);

	//menu do jogo
	do
    {
		printf("\t   BATALHA NAVAL\n\n\tEscolha uma opcao!\n\t   1. Novo Jogo\n\t   2. Creditos\n\t   3. Sair\n\n");
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:

            printf("Deseja alocar aleatoriamente? 1-sim 2-nao\n");
            scanf("%d", &alocacao);

            if(alocacao == 1)
                aloca_ale(jogador1);
            else
            {
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
            }

            imprimetabuleiro(jogador1, jogador2);

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

                            else if(jogador2v[tirox][tiroy] == 2 || jogador2v[tirox][tiroy] == 1) //testa se ja atirou ou se tem barco neste local
                            {
                                acertou = 1;
                                printf("Atire onde voce ainda nao atirou\n\n");
                            }

                            else if(jogador2[tirox][tiroy] == 1) //coloca tiro no canto certo
                            {
                                acertou = 1;
                                jogador2v[tirox][tiroy] = 1;
                                imprimetabuleiro(jogador1v, jogador2v);
                                printf("Voce acertou! Jogue novamente\n\n");
                                system("pause");
                                conta_navios(jogador1v, jogador2v, contador1, contador2);
                            }

                            else //passa a vez para IA
                            {
                                acertou = 0;
                                jogador2v[tirox][tiroy] = 2;
                                imprimetabuleiro(jogador1v, jogador2v);
                                printf("Voce errou!\n\n");
                                system("pause");
                            }

                        }while(acertou == 1);


                        //determina coordenadas do tiro do jogador2 // IA!!!!
                        do
                        {
                            tirox = rand() % 15;
                            tiroy = rand() % 15;

                            if(tirox < 0 || tirox > TAM-1 || tiroy < 0 || tiroy > TAM-1) //testa se as coordenadas sao validas
                                acertou = 1;


                            else if(jogador1v[tirox][tiroy] == 2 || jogador1v[tirox][tiroy] == 1) //testa se ja atirou ou se tem barco neste local
                                acertou = 1;


                            else if(jogador1[tirox][tiroy] == 1)
                            {
                                acertou = 1;
                                jogador1v[tirox][tiroy] = 1;
                                imprimetabuleiro(jogador1v, jogador2v);
                                printf("O computador acertou!\n\n");
                                system("pause");
                                conta_navios(jogador1v, jogador2v, contador1, contador2);
                            }

                            else
                            {
                                acertou = 0;
                                jogador1v[tirox][tiroy] = 2;
                                imprimetabuleiro(jogador1v, jogador2v);
                                printf("O computador errou!\n\n");
                                system("pause");
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
