#include "funcao.hpp"

void calculaItensRec(int i, int j, int* vetorDePesos, int** resp, int* itens) {
    if(resp[i][j] == 0);
    else if(resp[i][j] == resp[i-1][j]) calculaItensRec(i-1, j, vetorDePesos, resp, itens);
    else {
        itens[i] = 1;
        calculaItensRec(i-1, j-vetorDePesos[i], vetorDePesos, resp, itens);
    }
}

int* calculaItens(int numeroDeItens, int pesoDaMochila, int* vetorDePesos, int** resp) {
    int* itens =(int*) calloc(numeroDeItens, sizeof(int));
    calculaItensRec(numeroDeItens-1, pesoDaMochila, vetorDePesos, resp, itens);
    return itens;
}

int** knapSackIter(int W, int wt[], int val[], int n)
{
    int** K;
    int result;
    K = new int*[n + 1];
    for (int i = 0; i < n + 1; i++)
        K[i] = new int[W + 1];
    for (int i = 0; i < n + 1; i++){
        for (int j = 0; j < W + 1; j++){
            K[i][j] = -1;
        }        
    }
 
    for (int i = 0; i < n + 1; i++) {
        for (int w = 0; w < W + 1; w++) {
            if (i == 0 || w == 0) K[i][w] = 0;
            else if (wt[i] <= w) {
                K[i][w] = max(val[i] + K[i - 1][w - wt[i]],
                	       K[i - 1][w]);
            }
            else K[i][w] = K[i - 1][w];
        }
    }

    return K;
}

int knapSackRec(int W, int wt[],int val[], int i, int** K){
   
    if (i < 0) return 0;

    if (K[i][W] != -1) return K[i][W];
 
    if (wt[i] > W) {
 
        K[i][W] = knapSackRec(W, wt, val, i - 1, K);

        return K[i][W];
    }
    else {
        K[i][W] = max(val[i] + knapSackRec(W - wt[i], wt, val, i - 1, K),
                       knapSackRec(W, wt, val, i - 1, K));
    
        return K[i][W];
    }
}
 
int** knapSack(int W, int wt[], int val[], int n) {
   
    int** K;
    int result;
    K = new int*[n];
    for (int i = 0; i < n; i++)
        K[i] = new int[W + 1];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < W + 1; j++){
            K[i][j] = -1;
        }        
    }
    
    knapSackRec(W, wt, val, n - 1, K);
    
    return K;
}
