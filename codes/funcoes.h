#include<stdio.h>
#define TAM 15

int aloca_navio(int jogador1[][TAM], int tam, int x, int y, char direcao); //aloca os navios nas posicoes desejadas
void imprimelinha(); //imprime as linhas no começo ou fim do tabuleiro
void imprimenum(); //imprime numeros no inicio do tabuleiro
void imprimetabuleiro(int jogador1[][TAM], int jogador2[][TAM], int id1, int id2); //imprime o tabuleiro dos 2 jogadores
void creditos(); //creditos do jogo
