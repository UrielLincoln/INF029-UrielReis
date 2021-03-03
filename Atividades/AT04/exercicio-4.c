#include <stdio.h>
#include <stdlib.h>


/*Crie um programa que tenha uma função ler3Numeros. Essa função deve ler três números do
usuário e retornar os três números. A função main deve imprimir esses três números. Utilize vetor
para fazer o retorno.*/

int ltr(int v[])
{
    int i;
    for(i=1;i<=3;i++)
    {
    printf("Digite um numero: ");
    scanf("%d", &v[i]);
    }
    puts("O numeros foram: ");
    for(i=1;i<=3;i++)
    {
    printf("%d\n", v[i]);
    }
}

int main(void)
{
    int a[3];
    ltr(a);
	system("pause");
}

