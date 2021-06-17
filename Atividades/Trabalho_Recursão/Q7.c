#include <stdio.h>
#include <stdlib.h>

int contador(int vet[]){
    int a, cont = 0;
        for(a=0; vet[a]!='\0';a++)
    {
        if(vet[a]=='\0'){ 
            printf("Aqui\t%d", cont);
            continue;
        }
        else{   
            cont++;  
            }
    }
    printf("%d\n\n\n", cont);
    return cont;
}

int vetin(int vet[], int tam, int i, int auxtam)
{
    int aux = 0, j;
    
    if(i>=tam)
    {
        return vet[tam];
    }

    else
    {
        aux = vet[tam - 1];
        vet[tam - 1] = vet[i];
        vet[i] = aux; 
        return vetin(vet, tam - 1, i + 1,auxtam);
    }
}

int main()
{
    int vetor[10] = {1,2,3,4,5,6,7,8,9,10};
    int tamm = 0, i = 0, j = 0,a = 0, auxtam = 0;
    tamm=contador(vetor);
    
    auxtam = tamm;
    printf("Vetor antes de ser invertido: ");
    //100
  for(j = 0; vetor[j]!='\0';j++)
    {
    printf(" %d", vetor[j]);
    }
    
    a=vetin(vetor,tamm,i,auxtam);
    printf("\nVetor invertido: ");
   for(j = 0; vetor[j]!='\0';j++)
        {
        printf(" %d", vetor[j]);
        }
    
    return 0;
}


  


