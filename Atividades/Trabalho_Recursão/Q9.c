#include <stdio.h>
#include <stdlib.h>
int contador(int x, int y, int cont){
    if(x % 10 == y) {cont++; }    
    if((x % 10) == x)   return cont;
    return contador(x/10,y, cont);    
}

int main()
{
     int num = 457975802;//numero de o onde vai ser pesqui]
     int numa = 5;//numero a ser pesquisado
     int a = 0, cont = 0;
    a=contador(num,numa, cont);
    
    printf("Quantidade de aparições: %d", a);

    return 0;
}

