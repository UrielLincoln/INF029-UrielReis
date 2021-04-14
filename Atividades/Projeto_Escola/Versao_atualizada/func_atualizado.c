#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "func.h"
#include <time.h>
#include <math.h>

int ci=1;//contador alunos
int conp = 1;
int cond = 1;

int qtda=0;
int qtdp=0;
int qtdd=0;
int erros = 0;

void menualuno();
void menupro();
void menudisc();

void cadastrar(char nome[], char data[], char sex[], char CPF[], char sexostr[], char copiadata[], int contadorpessoas);
void listar(cadaluno var[], int num, int aux);
void excluir(cadaluno var[], int num, int cont);

int validarSexo(char sex, char strsx[]);
int validarcpf(char abc[], int tam);
int ValidarData(char data[], char data2[]);
int validarNome(char nome[]);// validar nome Aluno e professor


void cadastrardisciplina(char nome[], int sem[], int contador[]);
void listardisc(caddisc var[]);
void inserir(caddisc var[], int num);
void remover(caddisc var[], int cont);
int vg=1;







void menu()
{
    int op;
    do{
        setbuf(stdin,NULL);
        //system("clear");
        printf("//////////////////////////\n");
        printf("/// 1- Menu do aluno\n/// 2- Menu do professor\n/// 3- Menu de disciplina\n/// 0- Encerrar.\n");
        printf("//////////////////////////\n");
            scanf("%d", &op);
            getchar();
        
    switch(op){
        case 1: menualuno(); break;
        case 2: menupro(); break;
        case 3: menudisc();
        case 0: break;
        default: printf("Opção inválida, tente novamente.\n"); break;
        }
    }
    while(op!=0);
       return;
    
}
void menualuno()
{
    char b;
    int i;
    int op;
    In:
    do{
        setbuf(stdin,NULL);
        system("clear");
        printf("/////////////////////////////////////////////////////////////\n");
        printf("/// 1- Cadastrar aluno\n/// 2- Remover ou atualizar aluno\n");
        printf("/// 3- Listagem de alunos geral e por sexo\n");
        printf("///0- Sair do menu aluno\n");
        printf("/////////////////////////////////////////////////////////////\n");
            scanf("%d", &op);
            getchar();
            
    
        switch(op){
            case 1:
            if(ci<=QTD)
            {
              qtda++; 
              alunos[ci].matricula=ci;
              cadastrar(alunos[ci].nome, alunos[ci].dtnasc, &alunos[ci].sexo, alunos[ci].CPF, alunos[ci].sexoc, alunos[ci].copdat, ci); 
              alunos[ci].cadastrado=1;
              
              ci++; break;
            }

            else
            {
                system("clear");
                printf("Não é possível cadastrar.\n");
                getchar();
                break;
            }

            case 2: excluir(alunos, 50, qtda); break;
            case 3: listar(alunos, 50, qtda); break; //50 = aluno; 100 = professor. Valor para diferenciar se é aluno ou professor
            case 0: break;
            default: printf("Opção inválida, tente novamente.\n"); goto In;
                    }
    }
    while(op!=0);
    return;
}
void menupro()
{
    int i;
    int op;
    In:
    do{
        setbuf(stdin,NULL);
        system("clear");
        printf("/////////////////////////////////////////////////////////////\n");
        printf("/// 1- Cadastrar professor\n/// 2- Remover ou atualizar professor\n");
        printf("/// 3- Lista geral e por sexo de professores\n");
        printf("/// 0- Sair do menu professor\n");
        printf("/////////////////////////////////////////////////////////////\n");
            scanf("%d", &op);
            getchar();
    
        switch(op){
          
            case 1:
            if(conp<=QTD)
            {
              qtdp++; 
              prof[conp].matricula=conp;
              cadastrar(prof[conp].nome, prof[conp].dtnasc, &prof[conp].sexo, prof[conp].CPF, prof[conp].sexoc, prof[conp].copdat, conp); 
              prof[conp].cadastrado=1,
              conp++; break;
            }
 
            case 2: excluir(prof, 100, qtdp); break;
            case 3: listar(prof, 100, qtdp); break; //50 = aluno; 100 = professor
            case 0: break;
            default: printf("Opção inválida, tente novamente.\n"); goto In;
                    }
    }
    while(op!=0);
    return;
}
void menudisc()
{
  int op;

  do{
        I:
        setbuf(stdin,NULL);
        system("clear");
        printf("/////////////////////////////////////////////////////////////\n");
        printf("/// 1- Cadastrar disciplina\n/// 2- Listar disciplina\n");
        printf("/// 3- Remover disciplina\n");
        printf("/// 4- Inserir alunos na disciplina\n");
        printf("/// 5- Inserir professores na disciplina\n");
        printf("/// 0- Sair do menu alino\n");
        printf("/////////////////////////////////////////////////////////////\n");
            scanf("%d", &op);
            getchar();

        switch(op)
        {
          
          case 1:
                  if(cond<=QTD)
                  {
                  qtdd++;
                  cadastrardisciplina(disc[cond].nome, &disc[cond].semestre, &cond); 
                  disc[cond].codigo=cond;
                  disc[cond].cadastrado=1;
                  cond++;
                  }
          else
            {
            printf("Não há professores disponiveis para mais disciplina\n");
            }  
            break;
        case 2: listardisc(disc); break;
        case 3: remover(disc,qtdd); break;
        case 4: inserir(disc, 50); break;
        case 5: inserir(disc, 100); break;
        case 0: break; 
        default: printf("Informação inválida! Tente novamente.\n"); getchar(); goto I;
        }

  }
  while(op!=0);


}
//Disciplina
void cadastrardisciplina(char nome[], int sem[], int contador[]){
  int i, op, op2;
  int tam;
  setbuf(stdin, NULL);
  //system("clear");

                  I:
                  system("clear");
                  printf("Digite o nome da disciplina: \n");
                  fgets(nome,50,stdin);
                  setbuf(stdin,NULL);
                  nome[strcspn(nome, "\n")] = 0;
    if(strlen(nome)>20)
    {
      printf("Nome inválido. Tente novamente.\n");
      getchar();
      goto I; 
    }
                  II:
                  system("clear");
                  printf("Informe o semestre da disciplina: \n");
                      scanf("%d", sem);
                      if(*sem<=0 || *sem>=8){
                        printf("Informações inválidas.\n");
                          getchar();
                            goto II;
                      }

                  system("clear");
                  getchar();
                  printf("Cadastro %d concluído!\n\n", *contador);
                  printf("********************************\n");
                  printf("** Disciplina: %s\n", nome);
                  printf("** Código: %d\n", *contador);
                  printf("** Semestre: %d\n", *sem);
                  printf("********************************\n\n\n\n");
                  printf("Pressione enter para continuar...\n\n");
                  getchar();
                  return;


                           
                  
        return;
}
void listardisc(caddisc var[])
{
    system("clear");
    setbuf(stdin, NULL);
    int cont, op, i;

    if(qtdd==0)
    {
      printf("Não há disciplinas.\n");
      getchar();
      return;
    }
    else
    {
      for(i=1;i<=qtdd;i++)
      {
        if(var[i].cadastrado==1)
        {
                                    if(var[i].regprof == 1)
                                    {  
                                      printf("||///////////////////////\n\n");
                                      printf("|| Nome da disciplina: %s\n", var[i].nome);
                                      printf("|| Numero da Matricula: %d\n", var[i].codigo);
                                      printf("|| Semestre: %d\n", var[i].semestre);
                                      printf("|| Professor: %s\n", var[i].prof);
                                      if((var[i].regaluno)!=0)
                                      {
                                        for(int x=1;x<=qtda;x++)
                                        {
                                          printf("|| Aluno: %s\n", var[i].vagas[x]);
                                        }
                                      }
                                      printf("||///////////////////////\n\n");
                                      getchar();
                                    
                                    }
                                      else
                                    {
                                      printf("||///////////////////////\n\n");
                                      printf("|| Nome da disciplina: %s\n", var[i].nome);
                                      printf("|| Numero da Matricula: %d\n", var[i].codigo);
                                      printf("|| Semestre: %d\n", var[i].semestre);
                                      //printf("|| Professor: %s\n", disc[cond].prof);
                                      //printf("|| Situação do aluno: %d\n\n", var[cont].cadastrado);
                                      printf("||///////////////////////\n\n"); 
                                    }
                                      getchar();
        }
        else
        continue;
      }
      
    }

}
void remover(caddisc var[], int cont)
{
  int i, op2, j;
  listardisc(disc); 

      printf("Digite o numero da matricula da disciplina que voce deseja apagar: \n");
      scanf("%d", &op2);

      for(i=1;i<=cont;i++)
      {
        if(var[i].codigo==op2)
            {
            var[i].cadastrado=0;  
            printf("Aluno excluído!\n");
            getchar();
            }
        for(j=i;j<=cont;j++)
        {
          if(var[i].cadastrado==0)
            {
            var[j+1].codigo--;
            cont--;
            cond--;
            }
        }
      }
}

void inserir(caddisc var[], int num)
{
      setbuf(stdin,NULL);
      int i,op, op2, j,x=1,y=1;

      if(qtdd==0)
      {
        printf("Não há registro de disciplinas no sistema.\n");
        getchar(); 
        return;    
      }

      if(num == 50){
        if(qtda==0){
          printf("Não há alunos registrados!\n");
          getchar();
          return;
        }
      }

      if(num == 100){
        if(qtdp==0){
          printf("Não há professores registrados!\n");
          getchar();
          return;
        }
      }



      printf("Disciplinas no sistema: \n");
      listardisc(disc);

      if(num==50)
      {
      printf("Digite o codigo da matricula que deseja incluir um aluno\n"); 
      scanf("%d", &op);
      }
      if(num==100)
      {
      printf("Digite o codigo da matricula que deseja incluir um professor\n"); 
      scanf("%d", &op);
      }


      if(num == 50)
    {
      for(i=1;i<=qtdd;i++)
      {
                          if(var[i].codigo==op)
                          {
                              listar(alunos, 50, qtda);
                              printf("Digite o numero da matricula do aluno que você deseja inserir na disciplina: \n");
                                scanf("%d", &op2);
                              for(j=1;j<=qtdd;j++)
                              { 
                               if(alunos[i].matricula==op2)
                               {
                                strcpy(var[i].vagas[x], alunos[j].nome);
                                printf("Aluno incluso!");
                                var[i].regaluno=1;
                                return;  
                               }  
                              }
                         
                          }
                          else{
                            printf("Opção inválida!");
                            getchar();
                            return;
                          }
      }
    }
      if(num == 100)
    {
      for(i=1;i<=qtdd;i++)
      {
                          if(var[i].codigo==op)
                          {
                              listar(prof, 100, qtdp);
                              printf("Digite o numero da matricula do professor que você deseja inserir na disciplina: \n");
                                scanf("%d", &op2);
                              for(j=1;j<=qtdd;j++)
                              { 
                               if(prof[i].matricula==op2)
                               {
                                strcpy(var[i].vagas[x], prof[j].nome);
                                var[i].regprof = 1;
                                printf("Professor incluso!");
                                return;  
                               }  
                              }
                         
                          }
                          else{
                            printf("Opção inválida!");
                            getchar();
                            return;
                          }
      }
    }
}
//ENCERRA AREA DE DISCIPLINA




void cadastrar(char *nome, char data[], char sex[], char CPF[], char sexostr[], char copiadata[], int contadorpessoas){
    int op;
    char b;
    int tam;

            Iniciocad:
            erros = 0;
            system("clear");
                                        GON:
                                        setbuf(stdin,NULL);
                                        printf("Digite o nome: ");
                                            fgets(nome,50,stdin);
                                            nome[strcspn(nome, "\n")] = 0;
                                            setbuf(stdin,NULL);
                                            //strtok(nome, "\n");
                                            if(validarNome(nome)==1)
                                               {printf("Dados inválidos, insira-os novamente.\n");
                                                goto GON;}
                                        GOD:    
                                        setbuf(stdin,NULL);
                                        system("clear");
                                        printf("Digite a data de nascimento no modelo (dd/mm/aa): ");
                                            fgets(data,12,stdin);
                                            data[strcspn(data, "\n")] = 0;
                                            setbuf(stdin,NULL);
                                            //strtok(data, "\n");
                                            if(ValidarData(data, copiadata)==1)
                                                {printf("Dados inválidos, insira-os novamente.\n"); getchar();
                                                goto GOD;}

                                        GOC: 
                                        system("clear");
                                        printf("Informe o seu CPF com pontuação:\n");
                                            fgets(CPF,15,stdin);
                                            CPF[strcspn(CPF, "\n")] = 0;
                                            //strtok(CPF, "\n");;
                                            tam=strlen(CPF);
                                            setbuf(stdin,NULL);
                                            //getchar();
                                            if(validarcpf(CPF,tam)==1)
                                                {printf("Dados inválidos, insira-os novamente.\n");
                                                getchar();
                                                goto GOC;}
                                            




                                        GOS:
                                        system("clear");
                                        printf("Informe uma letra referente ao sexo: \nM- Masculino F- Feminino O- Outro\n");
                                            scanf("%c", sex);
                                                //getchar();
                                            //scanf("%c", &b);
                                            setbuf(stdin,NULL);
                                            if(validarSexo(*sex, sexostr)==1)
                                                {printf("Dados inválidos, insira-os novamente.\n");
                                                getchar();
                                                goto GOS;}
                                            printf("Sexo: %s\n", sexostr);

 
                                if(erros>1){
                            
                                        printf("Houve erros durante o registro. Refaça criteriosamente.\n");
                                        } 
                                else{
                                        system("clear"); 
                                        //matt++;
                                        setbuf(stdin,NULL);
                                        printf("Informaçoes de cadastro\nNome: %s\nData de nascimento: %s\n", nome, copiadata);
                                    	printf("CPF: %s\nSexo: %s\nMatricula: %d\n", CPF,sexostr, contadorpessoas);
                                    	//*cad=1;//INFORMA SE ESTÁ CADASTRADO
                                    	//INCREMENTA NA STRUCT
                                    	printf("Pressione enter para continuar...\n");
                                    	getchar();
                                      return;
                                    }
                                        

}
void listar(cadaluno var[], int num, int aux)
{
    
    system("clear");
    setbuf(stdin, NULL);
    int cont, op;

    if((num == 50 && aux==0) || (num == 50  && aux>QTD))
    {
        printf("Ainda não há registro de alunos. Pressione enter para continuar...\n");
        getchar();
        return;
    }
    if((num == 100 && aux==0) || (num == 100  && aux>QTD))
    {
        
        printf("Ainda não há registro de professores. Pressione enter para continuar...\n");
        getchar();
        return;
    }

    I:
    system("clear");
    if(num==50){
    printf("Modo de listamento:\n1- Todos\n2- Alunos do Sexo masculino\n3- Alunos do Sexo feminino\n0- Para retornar ao menu aluno\n");
    scanf("%d", &op);
    }

    if(num==100){
    printf("Modo de listamento:\n1- Todos\n2- Professores do Sexo masculino\n3- Professores do Sexo feminino\n0- Para retornar ao menu professor\n");
    scanf("%d", &op);  
    }
    switch(op)
    {
    case 1:
                if(num==50){
                printf("||///////////////////////Alunos cadastrados no sistema///////////////////////||\n");
                }
                if(num==100){
                printf("||///////////////////////Professores cadastrados no sistema///////////////////////||\n");
                }
                for(cont=1;cont<=aux;cont++)
                {
                    if(var[cont].cadastrado == 1)
                    {
                            printf("Valor de CI: %d Valor de cont %d\n", ci,cont);
                            printf("|| Numero da Matricula: %d\n", var[cont].matricula);
                            printf("|| Nome: %s\n", var[cont].nome);
                            printf("|| Data de nascimento: %s\n", var[cont].copdat);
                            printf("|| Sexo: %s\n", var[cont].sexoc);
                            printf("|| CPF: %s\n", var[cont].CPF);
                            //printf("|| Situação do aluno: %d\n\n", var[cont].cadastrado);
                            printf("||///////////////////////\n\n");
                    }
                    else
                        continue;
    }
    getchar();        
    break;        
    
    case 2:
                if(num==50){
                printf("||///////////////////////Alunos cadastrados no sistema///////////////////////||\n");
                }
                if(num==100){
                printf("||///////////////////////Professores cadastrados no sistema///////////////////////||\n");
                }
                for(cont=1;cont<=aux;cont++)
                {
                    if((var[cont].cadastrado == 1 && var[cont].sexo == 'm') || (var[cont].cadastrado == 1 && var[cont].sexo == 'M'))
                    {
                            //printf("Valor de CI: %d Valor de cont %d\n", ci,cont);
                            printf("|| Numero da Matricula: %d\n", var[cont].matricula);
                            printf("|| Nome: %s\n", var[cont].nome);
                            printf("|| Data de nascimento: %s\n", var[cont].copdat);
                            printf("|| Sexo: %s\n", var[cont].sexoc);
                            printf("|| CPF: %s\n", var[cont].CPF);
                            //printf("|| Situação do aluno: %d\n\n", alunos[cont].cadastrado);
                            printf("||///////////////////////\n\n");
                    }
                    else
                        continue;
                }        
    getchar();        
    break;    
    
    case 3:
                if(num==50){
                printf("||///////////////////////Alunos cadastrados no sistema///////////////////////||\n");
                }
                if(num==100){
                printf("||///////////////////////Professores cadastrados no sistema///////////////////////||\n");
                }
                for(cont=1;cont<=aux;cont++)
                {
                    if((var[cont].cadastrado == 1 && var[cont].sexo == 'f') || (var[cont].cadastrado == 1 && var[cont].sexo == 'F'))
                    {
                            //printf("Valor de CI: %d Valor de cont %d\n", ci,cont);
                            printf("|| Numero da Matricula: %d\n", var[cont].matricula);
                            printf("|| Nome: %s\n", var[cont].nome);
                            printf("|| Data de nascimento: %s\n", var[cont].copdat);
                            printf("|| Sexo: %s\n", var[cont].sexoc);
                            printf("|| CPF: %s\n", var[cont].CPF);
                            //printf("|| Situação do aluno: %d\n\n", var[cont].cadastrado);
                            printf("||///////////////////////\n\n");
                    }
                    else
                        continue;
                }        
    getchar();        
    break;
    
    case 0: break;
    default: printf("Opção inválida.\n"); getchar(); goto I;
    }
    
    printf("Pressione Enter para continuar...\n");
    getchar();
    return;
}
void excluir(cadaluno var[], int num, int cont)//EXCLUI E ATUALIZA
{
    setbuf(stdin,NULL);
    int i,j, op, op2;
        
        system("clear");

        if(num == 50 && cont==0)
        {
        printf("Não há alunos no sistema. Tente mais tarde.\n"); 
        getchar();
        return;
        }
        
        if(num == 100 && cont==0)
        {
        printf("Não há professores no sistema. Tente mais tarde.\n"); 
        getchar();
        return;
        }




    else
    {
    I:
                for(i=1;i<=cont;i++)
                    {
                                    if(var[i].cadastrado == 1)
                                    {
                                            printf("||///////////////////////\n\n");
                                            printf("|| Nome: %s\n", var[i].nome);
                                            printf("|| Data de nascimento: %s\n", var[i].copdat);
                                            printf("|| Sexo: %s\n", var[i].sexoc);
                                            printf("|| CPF: %s\n", var[i].CPF);
                                            printf("|| Numero da Matricula: %d\n", var[i].matricula);
                                            printf("||///////////////////////\n\n");
                                    }
                    }                
                                printf("Escolha a opção desejada:\n1- Excluir\n2- Atualizar\n3- Sair\n");
                                            scanf("%d", &op);   
                switch(op)
                {               
                            case 1:
                                            if(num == 50){
                                            printf("Digite o numero da matricula do aluno que quer excluir.\n");
                                                scanf("%d", &op2);}

                                            else if(num==100){
                                            printf("Digite o numero da matricula do professor que quer excluir.\n");
                                                scanf("%d", &op2);}

                                                for(i=1;i<=cont;i++)
                                                {
                                                                if(var[i].matricula==op2)
                                                                    {
                                                                        var[i].cadastrado=0;
                                                                        if(num == 50){
                                                                        printf("Aluno excluído!\n");
                                                                        getchar();
                                                                        }
                                                                        else if(num == 100){
                                                                          printf("Professor excluído!\n");
                                                                          getchar();
                                                                        }
                                                                        for(j=i;j<=cont;j++)
                                                                        {
                                                                        if(var[i].cadastrado==0)
                                                                                  { 
                                                                                   var[j+1].matricula--;
                                                                                   cont--;
                                                                                   if(num == 50){
                                                                                     ci--;
                                                                                   }
                                                                                   if(num == 100){
                                                                                     conp--;
                                                                                   }
                                                                                    }
                                                                        }            
                                                                           
                                                                    }
                                                }                    
                            break;   
                            
                            
                            
                            case 2:
                                            if(num == 50){
                                              setbuf(stdin,NULL);
                                            printf("Digite o numero da matricula do aluno que quer atualizar.\n");
                                                scanf("%d", &op2);
                                                getchar();}

                                            else if(num==100){
                                              setbuf(stdin,NULL);
                                            printf("Digite o numero da matricula do professor que quer atualizar.\n");
                                                scanf("%d", &op2);
                                                getchar();}
                                            
                                            for(i=1;i<=cont;i++)   
                                            {
                                                            if(var[i].matricula==op2)
                                                            {
                                                           // if  
                                                            //var[i].matricula=op2;
                                                            cadastrar(var[op2].nome, var[op2].dtnasc, &var[op2].sexo, var[op2].CPF, var[op2].sexoc, var[op2].copdat, op2);
                                                            var[op2].cadastrado=1;

                                                            printf("Cadastro atualizado com sucesso!\n\n\n");
                                                            getchar();
                                                            return;
                                                            //break;
                                                            
                                                            }  
                                                            else
                                                                continue;
                                            }   
                            
                            break;
                            
                            
                            case 0: break; 
                            default:printf("Opção inválida!\n"); goto I;
                                
                                    
                }                   
                  
    }    
    
    printf("Programa encerrado!\n");
        getchar();
        return;
} 
int validarSexo(char sex, char strsx[]) //VALIDA O SEXO
{    

	  setbuf(stdin, NULL);
    printf("%c\n\n", sex);
    getchar();
    if (strlen(&sex)==0){
        printf("Não há registro.\n");
        erros+= 1;
        return 1;}
    else{    
        if (sex == 'M' || sex == 'm'){
            strcpy(strsx, "Masculino");
				return 0;}
				
        else if (sex == 'F' || sex == 'f'){
            strcpy(strsx, "Feminino");
				return 0;}
                
        else if (sex == 'O' || sex == 'o'){
            strcpy(strsx, "Outro");
				return 0;}
                
        else{
            strcpy(strsx, "Sua opção foi inválida.");
                erros+=1;
        return 1;}
    }
    setbuf(stdin, NULL);
}
int validarcpf(char abc[], int tama) //VALIDA O CPF
{
    int i,j,r1,r2; 
    int soma, soma2;
    int cpfre[11];
    char copia[11] = {'\0'};
    

    
                            if(tama!=14){
                                printf("Deu erro no tamanho da string.\n");
                                getchar();
                                erros+=1;
                                setbuf(stdin,NULL);
                                getchar();
                                return 1;
                            }
                            
                            else
                            {


                                for(i=0,j=0;i<tama;i++)
                                   {
                                        if((abc[i] == '.') || (abc[i] == '-'))
                                        {
                                            continue;                   
                                        }
                                            
                                        else
                                        { 
                                                strcpy(&copia[j], &abc[i]);
                                                 j++;
                                        }
                                                 
                                    }
                            } 


        if(strlen(copia)==11)
        {   
                            for(i=0;i<strlen(copia);i++)
                                {
                            cpfre[i] = copia[i] - '0';
                                }
                                
                                                                            soma = 0;
                                                                            for(i=0,j=10;i<9;i++,j--)
                                                                            {
                                                                                soma+= cpfre[i] * j;
                                                                            }
                                                                            r1=(soma*10)%11;
                                                                            
                                                                            soma2 = 0;
                                                                            for(i=0,j=11;i<10;i++,j--)
                                                                            {
                                                                                soma2+= cpfre[i] * j;
                                                                            }
                                                                            r2=(soma2*10)%11;
                                
                                
                                if(r1 == cpfre[9] && r2 == cpfre[10])
                                    {
                                    printf("CPF válido.\n");
                                    getchar();
                                    setbuf(stdin, NULL);
                                    return 0;
                                    }
                                    
                                else{
                                    printf("CPF inválido\n");
                        			erros+=1;
                        			getchar();
                        			setbuf(stdin, NULL);
                        			return 1;
                                    }

        }
        else{
                              printf("CPF inválido 2\n");
                        			getchar();
                        			setbuf(stdin, NULL);
                        			return 1;
            }        


    
}
int validarNome(char *string)
{
    int i;
    int ctd=0;
    
                if(strlen(string)==0 || string[i]=='\0'){
                    printf("Ocorreu um erro, string em branco");
                    getchar();
                    erros+=1;
                    return 1;}
                    
                else
                {    
                        for(i=0;string[i]!='\0';i++)
                        {
                                                    if(string[i]=='\n')
                                                    continue;
                            
                                                    else    
                                                    ctd++;
                        }
                } 
            if(ctd>20){
                erros+=1;
                return 1;} 
                
            else{
                return 0;}
}      
int ValidarData(char data[], char data2[])
{
    
    strcpy(data2,data);
    int i, idata[11],dd,mm,aa,y=0;
    char *aux;

    if(strlen(data)!=10){
        erros+=1;
        return 1;
    }      
    else{
        aux=strtok(data,"/"); 
        dd = atoi(aux);
        while(aux != NULL){
        if(y==0){    
                aux=strtok(NULL,"/"); 
                mm = atoi(aux);
                y++;
                }
            else if(y==1)
        {
            aux=strtok(NULL,"/"); 
            aa = atoi(aux);
            y++;
        }
        else
            break;
        }
        
    if (aa >= 1900 && aa <= 2100)
    {
        if (mm >= 1 && mm <= 12)
        {
                            if((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                            {
                                erros=0;
                                return 0;
                            }
                                            
                                
                            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                            {
                                erros=0;
                                return 0;
                                
                            }
                                            
                            else if((dd >= 1 && dd <= 28) && (mm == 2))
                            {
                                erros=0;
                                return 0;
                            }
                                           
                                            
                            else if(dd == 29 && mm == 2 && (aa % 400 == 0 || (aa % 4 == 0 && aa % 100 != 0)))
                            {
                                erros=0;
                                return 0;
                            }
                            
                            else
                                {
                                    erros+=1;
                                    return 1;
                                }
                                           
        }
        else
        {   
            erros+=1;
            return 1;
        }
    }
    else
    {
        erros+=1;
        return 1;
    }    
    }
} 


