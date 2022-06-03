#ifndef FUNCAO_H
#define FUNCAO_H

#include <iostream>
#include <cmath>

using namespace std;

int** knapSackIter(int W, int wt[], int val[], int n);
int** knapSack(int W, int wt[], int val[], int n);
int knapSackRec(int W, int wt[],int val[], int i,int** dp);
void calculaItensRec(int i, int j, int* vetorDePesos, int** resp, int* itens);
int* calculaItens(int numeroDeItens, int pesoDaMochila, int* vetorDePesos, int** resp);

#endif // FUNCAO_H
