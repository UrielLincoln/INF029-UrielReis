//Crie um programa que tenha uma função cadastrarCliente. Essa função deve ler os dados do
//cliente (nome, dataNascimento, cpf, sexo) e retornar os dados do cliente. A função main deve
//imprimir os dados do cliente.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define QTD 0

int conti = 0 ;
struct cad_cliente
{
    char nome[30];
    int dd,mm,aa;
    double cpf;
    char sexo, sex[12];
};
struct cad_cliente CAD[QTD];

void cadclt();

int main(){
    setlocale(LC_ALL, "Portuguese");	
    int op;
    int op2;
    do{
    Incp:
    printf("Selecione a opção desejada\n1- Cadastrar\n2- Sair");
      scanf("%d", &op);
    switch(op){
      case 1: cadclt();break;
      case 2: printf("Programa encerrado."); break;
      default:printf("Opção inválida.\n"); goto Incp;
    }
    }
      while(op2==1);
    return 0;
}

void cadclt(){
    int op;
    do{
    setbuf(stdin, NULL);
      printf("Digite o nome do cliente: ");
          fgets( CAD[conti].nome,50,stdin);
      printf("Digite a data de nascimento: \n");
          scanf("%d%d%d", &CAD[conti].dd,&CAD[conti].mm,&CAD[conti].aa);
      printf("Informe o seu CPF: \n");
          scanf("%lf", &CAD[conti].cpf);
    CDSX:
    setbuf(stdin, NULL);
    printf("Informe o sexo: \nM- Masculino\nF- Feminino\n");
        fgets(CAD[conti].sex,50,stdin); 
    printf("Informaçoes de cadastro\nNome: %s\nData de nascimento: %d/%d/%d\nCPF: %.0lf\nSexo: %s\n", CAD[conti].nome,CAD[conti].dd,CAD[conti].mm,CAD[conti].aa,CAD[conti].cpf,CAD[conti].sex);
    printf("Fim do cadastro.");
    printf("Deseja continuar o programa?\n1- Sim\n0- Não");
        scanf("%d", &op);
    setbuf(stdin, NULL);
    conti++;
    }
    while(op!=0);
    return;
}












