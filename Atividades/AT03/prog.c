#include <stdio.h>
#include <string.h>
#include "auxi.h"
	int main(){
  	int a,fun;	
  		printf("Digite o numero para dobrar seu valor: ");
    			scanf("%d", &a);
  		fun = dobrar(a);	
  		printf("O resultado é: %d\n", fun);
  system("pause");
  return 0;
  }
