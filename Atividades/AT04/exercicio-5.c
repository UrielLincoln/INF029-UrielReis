#include <stdio.h>
#include <stdlib.h>

struct ler4numeros{
    int numer;
    }; 
struct ler4numeros regnum[4];
/////////////////////////////
void ltr(int v[])
{
    int i;
    for(i=1;i<=4;i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &regnum[i].numer);   
    }
}
/////////////////////////////////////
int main(void)
{
    int a[4],i;
    
    ltr(4);
    
    for(i=1;i<=4;i++)
    {
    printf("Os numeros: %d\n", regnum[i].numer);
    }

    system("pause");
    return 0;
}

