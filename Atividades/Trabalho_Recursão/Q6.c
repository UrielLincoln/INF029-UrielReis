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

int multi(int n, int x){
    
    if(x==1)
        return n;
        
    return n * multi(n, x-1);
}

int main()
{
    int num, a, numa;
    printf("Digite os numeros: \n");
        scanf("%d%d", &num, &numa);
    a=multi(num,numa);
    printf("Resultado: %d", a);

    return 0;
}

