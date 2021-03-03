#include <stdio.h>

int somar(int x, int y){
    return x+y;
    }


int main()
{
    int a,b;
    printf("Digite dois numeros a serem somados: \n");
    scanf("%d%d", &a,&b);
    
    int sm = somar(a,b);
    printf("O resultado da soma é: %d", sm);
    
    
    system("pause");	
    return 0;
}
