#include <stdio.h>
#include <stdlib.h>
int naturais(int x){
    if(x < 0)
        return 0;
    printf("%d\n", x);
    return naturais(x-1);
}
int main()
{
     int x = 100, y = 0;
     //printf("Digite um valor limite: ");
     //sncaf("%d", &x);
     naturais(x);
     return 0;
}

