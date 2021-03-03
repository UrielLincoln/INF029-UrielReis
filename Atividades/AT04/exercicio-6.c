#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Crie um programa que tenha uma função ler3Letras. Essa função deve ler três letras do usuário
e retornar as três letras. A função main deve imprimir essas três letras.*/

void let(char lt[])
{
    int i;
    for(i=0;i<3;i++)
    {
        printf("Digite uma letra: ");
        scanf(" %c", &lt[i]);
        fflush(stdin); 
    }
}
int main(void)
{
    int i;
    char a[3];
    
    let(a);
    
    for(i=0;i<3;i++)
    {
    printf("As letras: %c\n", a[i]);
    }
	
    system("pause");
    return 0;
}

