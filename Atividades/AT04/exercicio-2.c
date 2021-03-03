#include <stdio.h>
/*Crie um programa que tenha uma função subtrai e a função main. A função main deve ler três
valores, enviar para a função subtrai. A função subtrai deve realizar a subtração dos três valores
(primeiro menos o segundo menos o terceiro) e retornar o valor. A Função main deve imprimir o
resultado da subtração*/


int somar(int x, int y, int z){
    return x-y-z;
    }


int main()
{
    int a,b,c;
    printf("Digite 3 numeros a serem subtraidos: \n");
    scanf("%d%d%d", &a,&b,&c);
    
    int sb = somar(a,b,c);
    printf("O resultado da subtração é: %d", sb);
    
    
	system("pause");
    return 0;
}
