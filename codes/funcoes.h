#include <stdio.h>
#define TAM 15

void aloca_ale(int jogador2[][TAM]); //aloca navios aleatoriamente
void aloca_pedido(int jogador1[][TAM]); //aloca navios conforme desejo do jogador
int aloca_navio(int jogador1[][TAM], int tam, int x, int y, char direcao); //aloca os navios nas posicoes desejadas
void imprimelinha(); //imprime as linhas no começo ou fim do tabuleiro
void imprimenum(); //imprime numeros no inicio do tabuleiro
void imprimetabuleiro(int jogador1[][TAM], int jogador2[][TAM]); //imprime o tabuleiro dos 2 jogadores
void creditos(); //creditos do jogo
int tiro_IA(int jogador1v[][TAM], int jogador2v [][TAM], int jogador1[][TAM], int acertou); //tiros da IA
int tiro_jogador(int jogador1v[][TAM], int jogador2v [][TAM], int jogador2[][TAM], int acertou); //tiros do Jogador
void conta_navios(int jogador1v[][TAM], int jogador2v[][TAM], int contador1, int contador2); //conta os navios p/ condicao de parada
