#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define QTD 5
#include "func.h"






int main()
{
        menu(); 
        
}



/*void cadastraraluno(
){
    int op;
    if(ci<QTD){
    do{
    system("clear");    
    setbuf(stdin, NULL);
    printf("Digite o nome do cliente: ");
        fgets(alunos[ci].nome,20-1,stdin);
    setbuf(stdin, NULL); 
    fflush(stdin);
        //printf("Digite o numero de matricula: ");
        //scanf("%ld", &alunos[QTDALUNO].matricula);
        //fgets(alunos[ci].matri, 10,stdin);
        //alunos[ci].matricula = atoi(alunos[ci].matri);
    printf("Digite a data de nascimento no modelo dd/mm/aa: ");
    getchar();
        fgets(alunos[ci].dtnasc,11-1,stdin);
    setbuf(stdin, NULL);    
    printf("Informe uma letra referente ao sexo: \nM- Masculino\nF- Feminino\nO- Outro\n");
        scanf(" %c", &alunos[ci].sexo);
    //setbuf(stdin, NULL);
    getchar();
    printf("Informe somente os numeros do seu CPF: \tExemplo: 12345678901\n");
        fgets(alunos[ci].CPF,12,stdin);
    setbuf(stdin, NULL);
    fflush(stdin);
    //strcpy(copdat,CAD[conti].data);
   // ValidarCPF(CAD[conti].cpf);
   // ValidarData(CAD[conti].data);
    //validarSexo();
    //validarNome();
    system("clear");
    //printf("Informaçoes de cadastro\nNome: %sData de nascimento: %s", alunos[ci].nome,alunos[ci].dtnasc);
	//printf("CPF: %sSexo: %c\nMatricula: %ld\n", alunos[ci].CPF,alunos[ci].sexo,alunos[ci].matricula);
	alunos[ci].cadastrado=1;
	ci++;
	alunos[ci].matricula++;
	fflush(stdin);
	    printf("Deseja continuar cadastrando? 1- Sim\t0- Não");
        scanf("%d", &op);
        //}
    }
    while(op!=0 && ci<QTD);
    menualuno();
    }
    else{
        printf("Não há vagas.");}
    return;
}*/


/*void cadastrarprofessor(){
    int op, i =0;
    char copdat[11];
    do{
        //for(int i; op==1;i++){
    system("clear");    
    setbuf(stdin, NULL);
    printf("Digite o nome do cliente: ");
        fgets(prof[i].nome,20,stdin);
    setbuf(stdin, NULL); 
    fflush(stdin);
    printf("Digite o numero de matricula: \n");
        //scanf("%ld", &alunos[QTDALUNO].matricula);
        fgets(prof[i].matri, 10,stdin);
        prof[i].matricula = atoi(prof[i].matri);
    printf("Digite a data de nascimento no modelo dd/mm/aa\n");
        fgets(prof[i].dtnasc,11,stdin);
    setbuf(stdin, NULL);    
    printf("Informe uma letra referente ao sexo: \nM- Masculino\nF- Feminino\nO- Outro\n");
        scanf(" %c", &prof[i].sexo);
    //setbuf(stdin, NULL);
    getchar();
    printf("Informe somente os numeros do seu CPF: \tExemplo: 12345678901\n");
        fgets(prof[i].CPF,12,stdin);
    setbuf(stdin, NULL);
    fflush(stdin);
    //strcpy(copdat,CAD[conti].data);
   // ValidarCPF(CAD[conti].cpf);
   // ValidarData(CAD[conti].data);
    //validarSexo();
    //validarNome();
    system("clear");
    printf("InformaÃ§oes de cadastro\nNome: %sData de nascimento: %s\n", prof[i].nome,prof[i].dtnasc);
	printf("CPF: %s\nSexo: %c\nMatricula: %ld\n", prof[i].CPF,prof[i].sexo,prof[i].matricula);
	i++;
	    printf("Deseja continuar cadastrando? 1- Sim\t0- NÃ£o");
        scanf("%d", &op);
        //}
    }

    while(op!=0);
    return;
}*/