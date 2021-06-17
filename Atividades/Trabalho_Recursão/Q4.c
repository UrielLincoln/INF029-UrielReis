#include <stdio.h>
#include <stdlib.h>

int contador(int vet[]){
    int a, cont;
    
        for(a=0; vet[a]!='\0';a++)
    {
        if(vet[a]=='\0') 
            continue;
        else{   
            cont++;  
            }
    }
    return cont - 1;
}

int somavetor(int vetor[], int qtd){
    
    if(qtd==1)
        return (vetor[0]);
        
    return vetor[qtd - 1] + somavetor(vetor, qtd - 1);
}

int main()
{
    int num = 5, y[5] = {1,2,3,4,5}, a,b=0;
    b = contador(y);
    a=somavetor(y,b);
    printf("Soma dos vetores: %d", a);

    return 0;
}

