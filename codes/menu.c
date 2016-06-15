#include <stdio.h>
#include <string.h>
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



	//menu do jogo
	do
    {
        aloca_ale(jogador2); //aloca aleatoriamente navios do computador

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
                    aloca_pedido(jogador1);

                imprimetabuleiro(jogador1, jogador2);

//=============================================LOOP PRINCIPAL DO JOGO===============================================//

                    while(1) //loop principal
                    {

                        do //determina coordenadas do tiro do jogador
                        {
                            tiro_jogador(jogador1v,jogador2v, jogador2, acertou);
                        }while(acertou == 1);



                        do //determina coordenadas do tiro da IA
                        {
                            tiro_IA(jogador1v,jogador2v, jogador1, acertou);
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
