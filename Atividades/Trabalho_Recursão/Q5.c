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

int somavetor(int n){
    
    if(n==1)
        return n;
        
    return n+somavetor(n-1);
}

int main()
{
    int num, a;
    printf("Digite o numero para efetuar a soma.\n");
        scanf("%d", &num);
    a=somavetor(num);
    printf("Soma dos numeros de 1 a %d: %d", num,a);

    return 0;
}

