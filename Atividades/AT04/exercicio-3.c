#include <stdio.h>
#include <stdlib.h>
int fat(int x)
{
    int i, aux = 0, y;
    
    if(x>0){
    for(i=x-1, aux=x; i>0; i--)
    {
        aux*=i;
    }
    }
    else if(x==0)
    {
        aux=1;
    }
    else if(x<0)
    {
        y = printf("O numero não possui fatorial\n");
        //return y;
    }
    return aux;
}


int main()
{
    int a, fato;
        printf("Digite um numero: \n");
            scanf("%d", &a);
        fato = fat(a);
        printf("Resultado da operação : %d", fato);
   
    
	system("pause");
    return 0;
}
