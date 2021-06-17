#include <stdio.h>
#include <stdlib.h>
int naturais(int x, int y){
    if(x <= 0)
        return 0;
    printf("%d\n", y);      
    if(y==x)
        return 0;
    return naturais(x, y+1);
}
int main()
{
     int x = 100, y = 0;
     //printf("Digite um valor limite: ");
     //sncaf("%d", &x);
     naturais(x,y);
     return 0;
}

