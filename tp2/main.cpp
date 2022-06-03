#include "funcao.hpp"
#include <chrono>

int main()
{
    int itens = 30;
    int Mochila = 50;  
    
    int* val;
    val = new int[itens];

    int* wt;
    wt = new int[itens];

    FILE *arq;
    arq = fopen ("entrada.txt","r");
    int i = 0;
    int x = 0;
 
    while(!feof(arq)){
        if(i < 30){
            fscanf(arq,"%d",val+i);
        }
        else{
            fscanf(arq,"%d",wt+x);
            x++;          
        }

        i++;
        
    }
    fclose(arq);
    
    int**K;
    int* itensNaMochila;
    auto start = chrono::steady_clock::now();
    K = knapSack(Mochila, wt, val, itens);
    itensNaMochila = calculaItens(itens, Mochila, wt, K);
    auto end = chrono::steady_clock::now();
    cout << "Memoização: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl;
    start = chrono::steady_clock::now();
    K = knapSackIter(Mochila, wt, val, itens);
    itensNaMochila = calculaItens(itens, Mochila, wt, K);
    end = chrono::steady_clock::now();
    cout << "Iterativo: "
        << chrono::duration_cast<chrono::microseconds>(end - start).count()
        << " µs" << endl;
    
    return 0;
}
