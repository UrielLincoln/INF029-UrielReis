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

int mdc(int a, int b)
{
    if(b==0)
    {
        return a;
    }
    mdc(b, a % b);
}

int main()
{
    int x = 0,y = 0, z = 0;
    printf("Digite dois numeros para o mdc: ");
        scanf("%d%d", &x,&y);
    z=mdc(x,y);
    
    printf("MDC: %d", z);
    return 0;
}


  


