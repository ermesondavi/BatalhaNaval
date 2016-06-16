#include <stdio.h>
#include <string.h>
#include "funcoes.c"

int main()
{
	int opcao; //para escolher a opcao do menu
	int jogador1[TAM][TAM] = {0}, jogador2[TAM][TAM] = {0}, jogador1v[TAM][TAM] = {0}, jogador2v[TAM][TAM] = {0}; //declaracao de matrizes
    int alocacao; // para verificar qual o tipo de alocacao desejada
    int acertou = 0; //para verificar se acertou o tiro ou nao



	do //imprime menu do jogo
    {
        aloca_ale(jogador2); //aloca aleatoriamente navios do computador

		printf("\t   BATALHA NAVAL\n\n\tEscolha uma opcao!\n\t   1. Novo Jogo\n\t   2. Creditos\n\t   3. Sair\n\n"); //imprime opcoes
		scanf("%d", &opcao);

		switch(opcao)
		{
			case 1:
//=====================================ALOCACAO DOS NAVIOS DO JOGADOR=================================================//
                printf("Deseja alocar os seus navios aleatoriamente? 1-Sim 2-Nao\n"); //escolhe qual o tipo de alocacao
                scanf("%d", &alocacao);

                if(alocacao == 1)
                    aloca_ale(jogador1); //aloca aleatoriamente os navios do jogador
                else
                    aloca_pedido(jogador1); //aloca conforme pedido os navios do jogador

                imprimetabuleiro(jogador1, jogador2); //imprimes os tabuleiros

//=============================================LOOP PRINCIPAL DO JOGO===============================================//

                    while(1) //loop principal
                    {

                        do //determina coordenadas do tiro do jogador
                        {
                            tiro_jogador(jogador1v,jogador2v, jogador2, &acertou);
                        }while(acertou == 1);



                        do //determina coordenadas do tiro da IA
                        {
                            tiro_IA(jogador1v,jogador2v, jogador1, &acertou);
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
