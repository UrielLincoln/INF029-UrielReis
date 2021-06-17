#include <stdio.h>


int fato(int n){
    if(n<=1)
        return 1;
    //n! = n . (n – 1). (n – 2). (n – 3)
    else
    {
        //printf("O numero é %d\n", n);
        return n*fato(n - 1);
    }
}

int main()
{
    int num, res;
    printf("Digite um numero: \n");
        scanf("%d", &num);
    res = fato(num);    
    printf("O fatorial de %d é: %d", num,res);
    return 0;
}
