#include <stdio.h>
#include <stdlib.h>
int main(void)
{
int op;
int a,b;
do
{
  printf("Digite os numeros para a operação: \n");
    scanf("%d%d", &a,&b);
  printf("//////Selecione a opção desejada//////\n");
  puts("0- Sair\n1 - Somar\n2 - Subtrair\n3 - Multiplicar\n4 - Dividir\n");
    scanf("%d", &op);
    switch(op)
    {
      case 1: 
        printf("%d + %d = %d\n", a,b,a+b); 
          break;
      case 2: 
        printf("%d - %d = %d\n", a,b,a-b); 
          break;
      case 3: 
        printf("%d * %d = %d\n", a,b,a*b); 
          break;
      case 4: 
        printf("%d / %d = %d\n", a,b,a/b); 
          break;
      default: 
        printf("Opção inválida"); 
          break;           
    }
  puts("Deseja continuar?\n(1) Sim\t(0) Não");
    scanf("%d", &op);

}
while(op!=0);
printf("Programa encerrado\n");

return 0;
}


