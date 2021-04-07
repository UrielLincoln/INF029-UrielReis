#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "func.h"
#include <time.h>
#include <math.h>

int ci=1;//contador alunos
int conp = 1;
int qtda=0;
int qtdp=0;
int erros = 0;

void menualuno();
void cadastraraluno(char nome[ci], char data[ci], char sex[ci], int cad[ci], char CPF[ci], int matt[ci]);
void listar();
void listarsx();
void excluir();


void menupro();
void cadastrarprof(char nome[conp], char data[conp], char sex[conp], int cad[conp], char CPF[conp], int matt[conp]);
void listarp();
int validarSexop();
int ValidarDatap(char []);
void listarsxp();
void excluirp();


int validarSexo(char *sexx);
int validarcpf(char abc[], int *tam);
int leitor(char string[]);
int validarNome(char nome[]);
int ValidarData(char data[]);








void menu()
{
    int op;
    do{
        setbuf(stdin,NULL);
        system("clear");
        printf("//////////////////////////\n");
        printf("/// 1- Menu do aluno\n/// 2- Menu do professor\n/// 0- Encerrar.\n");
        printf("//////////////////////////\n");
            scanf("%d", &op);
        
    switch(op){
        case 1: menualuno(); break;
        case 2: menupro(); break;
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
        //setbuf(stdin,NULL);
        system("clear");
        printf("/////////////////////////////////////////////////////////////\n");
        printf("/// 1- Cadastrar aluno\n/// 2- Remover ou atualizar aluno\n");
        printf("/// 3- Listagem de alunos geral e por sexo\n");
        printf("///0- Sair do menu aluno\n");
        printf("/////////////////////////////////////////////////////////////\n");
            scanf("%d", &op);
            
    
        switch(op){
            case 1: qtda++; cadastraraluno(alunos[ci].nome, alunos[ci].dtnasc, &alunos[ci].sexo, &alunos[ci].cadastrado, alunos[ci].CPF, &alunos[ci].matricula); break;
            case 2: excluir(); break;
            case 3: listar(); break;
            case 0: break;
            default: printf("Opção inválida, tente novamente.\n"); goto In;
                    }
    }
    while(op!=0);
    return;
}
void cadastraraluno(char nome[ci], char data[ci], char sex[ci], int cad[ci], char CPF[ci], int matt[ci]){
    int op;
    char b;
    int tam;

    if(ci<=QTD){
    do{
            
            Iniciocad:
            erros = 0;
            system("clear");
                                        GON:
                                        system("clear");
                                        setbuf(stdin,NULL);
                                        printf("Digite o nome do aluno: ");
                                            fgets(nome,50,stdin);
                                            strtok(nome, "\n");
                                            if(validarNome(nome)==1)
                                               {printf("Dados inválidos, insira-os novamente.\n");
                                                goto GON;}
                                        GOD:    
                                        system("clear");
                                        setbuf(stdin,NULL);
                                        printf("Digite a data de nascimento no modelo (dd/mm/aa): ");
                                            fgets(data,12,stdin);
                                            strtok(data, "\n");
                                            if(ValidarData(data)==1)
                                                {printf("Dados inválidos, insira-os novamente.\n"); getchar();
                                                goto GOD;}
                                        
                                        GOS:
                                        setbuf(stdin,NULL);
                                        system("clear");
                                        printf("Informe uma letra referente ao sexo: \nM- Masculino F- Feminino O- Outro\n");
                                            scanf(" %c", sex);
                                            scanf("%c", &b);
                                            setbuf(stdin,NULL);
                                            if(validarSexo(sex)==1)
                                                {printf("Dados inválidos, insira-os novamente.\n");
                                                getchar();
                                                goto GOS;}
                                        GOC: 
                                        system("clear");
                                        printf("Informe o seu CPF com pontuação:\n");
                                            fgets(alunos[ci].CPF,15,stdin);
                                            strtok(CPF, "\n");;
                                            tam=strlen(CPF);
                                            setbuf(stdin,NULL);
                                            //getchar();
                                            if(validarcpf(CPF,&tam)==1)
                                                {printf("Dados inválidos, insira-os novamente.\n");
                                                getchar();
                                                goto GOC;}
                                            
 
                                if(erros>1){
                            
                                        printf("Houve erros durante o registro. Refaça criteriosamente.\n");
                                        } 
                                else{
                                        system("clear"); 
                                        *matt = ci;
                                        setbuf(stdin,NULL);
                                        printf("Informaçoes de cadastro\nNome: %s\nData de nascimento: %s\n", nome, alunos[ci].copdat);
                                    	printf("CPF: %s\nSexo: %s\nMatricula: %d\n", CPF,alunos[ci].sexoc,*matt);
                                    	*cad=1;//INFORMA SE ESTÁ CADASTRADO
                                    	ci++;//INCREMENTA NA STRUCT
                                    	printf("Pressione enter para continuar...\n");
                                    	getchar();
                                    }
                                        
    }
    while(op!=0 && ci<=QTD);
    }
                                        else{
                                            printf("Não há vagas.\n");}
                                        return;
}
void listar()
{
    
    system("clear");
        getchar();
    int cont, op;
    if(qtda==0 || qtda>QTD){
        
        printf("Ainda não há registro de alunos. Pressione enter para continuar...\n");
        getchar();
        return;
    }
    I:
    system("clear");
    printf("Modo de listamento:\n 1- Todos\n2- Alunos do Sexo masculino\n3- Alunos do Sexo feminino\n0- Para retornar ao menu aluno\n");
    scanf("%d", &op);
    switch(op)
    {
    case 1:
                printf("||///////////////////////Alunos cadastrados no sistema///////////////////////||\n");
                for(cont=1;cont<=qtda;cont++)
                {
                    if(alunos[cont].cadastrado == 1)
                    {
                            //printf("Valor de CI: %d Valor de cont %d\n", ci,cont);
                            printf("|| Numero da Matricula: %d\n", alunos[cont].matricula);
                            printf("|| Nome: %s\n", alunos[cont].nome);
                            printf("|| Data de nascimento: %s\n", alunos[cont].copdat);
                            printf("|| Sexo: %s\n", alunos[cont].sexoc);
                            printf("|| CPF: %s\n", alunos[cont].CPF);
                            printf("|| Situação do aluno: %d\n\n", alunos[cont].cadastrado);
                            printf("||///////////////////////\n\n");
                    }
                    else
                        continue;
    }
    getchar();        
    break;        
    
    case 2:
                printf("||///////////////////////Alunos cadastrados no sistema///////////////////////||\n");
                for(cont=1;cont<=qtda;cont++)
                {
                    if((alunos[cont].cadastrado == 1 && alunos[cont].sexo) == 'm' || (alunos[cont].cadastrado == 1 && alunos[cont].sexo == 'M'))
                    {
                            //printf("Valor de CI: %d Valor de cont %d\n", ci,cont);
                            printf("|| Numero da Matricula: %d\n", alunos[cont].matricula);
                            printf("|| Nome: %s\n", alunos[cont].nome);
                            printf("|| Data de nascimento: %s\n", alunos[cont].copdat);
                            printf("|| Sexo: %s\n", alunos[cont].sexoc);
                            printf("|| CPF: %s\n", alunos[cont].CPF);
                            printf("|| Situação do aluno: %d\n\n", alunos[cont].cadastrado);
                            printf("||///////////////////////\n\n");
                    }
                    else
                        continue;
                }        
    getchar();        
    break;    
    
    case 3:
                printf("||///////////////////////Alunos cadastrados no sistema///////////////////////||\n");
                for(cont=1;cont<=qtda;cont++)
                {
                    if((alunos[cont].cadastrado == 1 && alunos[cont].sexo) == 'f' || (alunos[cont].cadastrado == 1 && alunos[cont].sexo == 'F'))
                    {
                            //printf("Valor de CI: %d Valor de cont %d\n", ci,cont);
                            printf("|| Numero da Matricula: %d\n", alunos[cont].matricula);
                            printf("|| Nome: %s\n", alunos[cont].nome);
                            printf("|| Data de nascimento: %s\n", alunos[cont].copdat);
                            printf("|| Sexo: %s\n", alunos[cont].sexoc);
                            printf("|| CPF: %s\n", alunos[cont].CPF);
                            printf("|| Situação do aluno: %d\n\n", alunos[cont].cadastrado);
                            printf("||///////////////////////\n\n");
                    }
                    else
                        continue;
                }        
    getchar();        
    break;
    
    case 0: break;
    default:printf("Opção inválida.\n"); getchar(); goto I;
    }
    
    
    
            
            
    printf("Pressione Enter para continuar...\n");
    getchar();
    return;
}
void excluir()
{
    getchar();
    int i,j, op, op2;
        
        system("clear");
    if(qtda==0) {
        printf("Não há alunos no sistema. Tente mais tarde.\n"); 
        getchar();
        return;}
        
        
    else
    {
    I:
                for(i=1;i<=qtda;i++)
                    {
                                    if(alunos[i].cadastrado == 1)
                                    {
                                            printf("||///////////////////////\n\n");
                                            printf("|| Nome: %s\n", alunos[i].nome);
                                            printf("|| Data de nascimento: %s\n", alunos[i].copdat);
                                            printf("|| Sexo: %s\n", alunos[i].sexoc);
                                            printf("|| CPF: %s\n", alunos[i].CPF);
                                            printf("|| Numero da Matricula: %d\n", alunos[i].matricula);
                                            printf("||///////////////////////\n\n");
                                    }
                    }                
                                printf("Escolha a opção desejada:\n1- Excluir\n2- Atualizar\n3- Sair\n");
                                            scanf("%d", &op);   
                switch(op)
                {               
                            case 1:
                                            printf("Digite o numero da matricula do aluno que quer excluir.\n");
                                                scanf("%d", &op2);
                                                for(i=1;i<=qtda;i++)
                                                {
                                                                if(alunos[i].matricula==op2)
                                                                    {
                                                                        alunos[i].cadastrado=0;
                                                                        printf("Aluno excluído!\n");
                                                                        getchar();
                                                                        for(j=i;j<=qtda;j++)
                                                                        {
                                                                        if(alunos[i].cadastrado==0)
                                                                                  {
                                                                                   alunos[j+1].matricula--;
                                                                                   qtda--;
                                                                                    }
                                                                        }            
                                                                           
                                                                    }
                                                }                    
                            break;   
                            
                            
                            
                            case 2:
                                            printf("Digite o numero da matricula do aluno que deseja atualizar.\n");
                                                scanf("%d", &op2);
                                            
                                            for(i=1;i<=alunos[i].matricula==op2;i++)   
                                            {
                                                            if(alunos[i].matricula==op2)
                                                            {
                                                            cadastraraluno(alunos[i].nome, alunos[i].dtnasc, &alunos[i].sexo, &alunos[i].cadastrado, alunos[i].CPF, &alunos[i].matricula);
                                                            ci--;
                                                            }  
                                                            else
                                                                continue;
                                            }                
                            
                            
                            
                            
                            
                            case 0: break; 
                            default:printf("Opção inválida!\n"); goto I;
                                
                                    
                }                   
                  
    }    
    
    printf("Programa encerrado!\n");
        getchar();
        return;
} 



int validarSexo(char *sexx)
{    

	setbuf(stdin, NULL);
    fflush(stdin);
    printf("%c\n\n",*sexx);
    if (strlen(sexx)=='\0'){
        printf("Não há registro.\n");
        erros+= 1;
        return 1;}
    else{    
        if (*sexx == 'M' || *sexx == 'm'){
            strcpy(alunos[ci].sexoc, "Masculino");
				return 0;}
				
        else if (*sexx == 'F' || *sexx == 'f'){
            strcpy(alunos[ci].sexoc, "Feminino");
				return 0;}
                
        else if (*sexx == 'O' || *sexx == 'o'){
            strcpy(alunos[ci].sexoc, "Outro");
				return 0;}
                
        else{
            strcpy(&alunos[ci].sexo, "Sua opção foi inválida.");
                erros+=1;
        return 1;}
    }
    setbuf(stdin, NULL);
}
int validarcpf(char abc[], int *tam)
{
    int i,j,r1,r2; 
    int soma, soma2;
    int cpfre[11];
    char copia[11] = {'\0'};
    int tamm;
    

    
                            if(*tam!=14){
                                printf("Deu erro no tamanho da string.\n");
                                erros+=1;
                                setbuf(stdin,NULL);
                                getchar();
                                return 1;
                            }
                            
                            else
                            {

                                for(i=0,j=0;abc[i]!='\0';i++)
                                    {
                                        if(abc[i]== '.' || abc[i] == '-'){
                                             continue;                    }
                                            
                                        else{
                                             copia[j] = abc[i];
                                                 j++;
                                                 }
                                    }
                            } 


        if(strlen(copia)==11){      
                            for(i=0;i<strlen(copia);i++)
                                {
                            cpfre[i] = copia[i] - '0';
                                }
                                //printf("Aqui 1");
                                getchar();
                                setbuf(stdin,NULL);
                                
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
                                    //printf("CPF válido.\n");
                                    //getchar();
                                    setbuf(stdin, NULL);
                                    return 0;
                                    }
                                    
                                else{
                                    //printf("CPF inválido\n");
                        			erros+=1;
                        			//getchar();
                        			setbuf(stdin, NULL);
                        			return 1;
                                    }

                    }
        else{
                                    //printf("CPF inválido 2\n");
                        			erros+=1;
                        			//getchar();
                        			setbuf(stdin, NULL);
                        			return 1;
            }        

//529.982.247-25
    
}
int validarNome(char string[])
{
    int i;
    int ctd=0;
    setbuf(stdin,NULL);
    //printf("CHegou aqui 1");
    //printf("A quantidade de caracteres: %d", strlen(string));
    //getchar();
    
                if(strlen(string)==0 || string[i]=='\0'){
                    printf("Ocorreu um erro, string em branco");
                    //getchar();
                    erros+=1;
                    return 1;}
                    
                else
                {    
                  //printf("CHegou aqui 2");
                  //getchar();
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
int ValidarData(char data[])
{
    
    strcpy(alunos[ci].copdat,data);
    int i, idata[11],dd,mm,aa,y=0;
    char *aux;

    if(strlen(data)!=10){
        //printf("A quantidade de caracteres: %d\n", strlen(data));
        //printf("Erro!\n");
        erros+=1;
        return 1;
    }      
    else{
        aux=strtok(data,"/"); 
        dd = atoi(aux);
        //printf("DD = %d\n", dd);
        //printf("Dia = %02d\n", dd); 
        while(aux != NULL){
        if(y==0){    
                aux=strtok(NULL,"/"); 
                mm = atoi(aux);
                //printf("Mês: %d\n", mm); 
                y++;
                }
            else if(y==1)
        {
            aux=strtok(NULL,"/"); 
            aa = atoi(aux);
            //printf("Ano: %d\n", aa); 
            y++;
        }
        else
            break;
        }
        
    if (aa >= 1900 && aa <= 2100)
    {
        //verificar mês
        if (mm >= 1 && mm <= 12)
        {
            //verificar dias
                            if((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                            {
                                //printf("Parou aqui");
                                erros=0;
                                return 0;
                            }
                                            
                                
                            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                            {
                                //printf("Parou 2 aqui");
                                erros=0;
                                return 0;
                                
                            }
                                            
                            else if((dd >= 1 && dd <= 28) && (mm == 2))
                            {
                                //printf("Parou aqui 3");
                                erros=0;
                                return 0;
                            }
                                           
                                            
                            else if(dd == 29 && mm == 2 && (aa % 400 == 0 || (aa % 4 == 0 && aa % 100 != 0)))
                            {//bissexto
                                //printf("Parou aqui 4");
                                erros=0;
                                return 0;
                            }
                            
                            else
                                {
                                    //printf("Parou aqui, tudo errado.");
                                    erros+=1;
                                    return 1;
                                }
                                           
        }
        else
        {   
            //printf("Mês inválido\n");
            erros+=1;
            return 1;
        }
    }
    else
    {
        //printf("O ano está errado");
        erros+=1;
        return 1;
    }    
    }
    //printf("Fim do programa.");
    //return 50;
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
        printf("/// 1- Cadastrar professor\n/// 2- Remover professor\n");
        printf("/// 3- Lista geral e por sexo de professores\n");
        printf("/// 0- Sair do menu alino\n");
        printf("/////////////////////////////////////////////////////////////\n");
            scanf("%d", &op);
    
        switch(op){
            case 1: qtdp++; cadastrarprof(prof[conp].nome, prof[conp].dtnasc, &prof[conp].sexo, &prof[conp].cadastrado, prof[conp].CPF, &prof[conp].matricula); break;
            case 2: excluirp(); break;
            case 3: listarp(); break;
            case 0: break;
            default: printf("Opção inválida, tente novamente.\n"); goto In;
                    }
    }
    while(op!=0);
    return;
}
void cadastrarprof(char nome[conp], char data[conp], char sex[conp], int cad[conp], char CPF[conp], int matt[conp]){
    int op;
    char b;
    int tam;
    setbuf(stdin,NULL);
    if(conp<=QTD){
    do{
            Iniciocad:
            erros = 0;
            system("clear");
                                        GON:
                                        system("clear");
                                        printf("Digite o nome do professor: ");
                                            fgets(nome,50,stdin);
                                            strtok(nome, "\n");
                                            if(validarNome(nome)==1)
                                               {printf("Dados inválidos, insira-os novamente.\n");
                                                goto GON;}
                                        GOD:    
                                        system("clear");
                                        setbuf(stdin,NULL);
                                        printf("Digite a data de nascimento no modelo (dd/mm/aa): ");
                                            fgets(data,12,stdin);
                                            strtok(data, "\n");
                                            if(ValidarData(data)==1)
                                                {printf("Dados inválidos, insira-os novamente.\n");
                                                goto GOD;}
                                        
                                        GOS:
                                        system("clear");
                                        printf("Informe uma letra referente ao sexo: \nM- Masculino F- Feminino O- Outro\n");
                                            scanf(" %c", sex);
                                            getchar();
                                            setbuf(stdin,NULL);
                                            if(validarSexo(sex)==1)
                                                {printf("Dados inválidos, insira-os novamente.\n");
                                                getchar();
                                                goto GOS;}
                                            
                                            
                                            
                                        GOC: 
                                        system("clear");
                                        printf("Informe o seu CPF com pontuação:\n");
                                            fgets(prof[conp].CPF,15,stdin);
                                            strtok(CPF, "\n");
                                            tam=strlen(CPF);
                                            setbuf(stdin,NULL);
                                            //getchar();
                                            if(validarcpf(CPF,&tam)==1)
                                                {printf("Dados inválidos, insira-os novamente.\n");
                                                getchar();
                                                goto GOC;}
                                            
 
                                if(erros>1){
                            
                                        printf("Houve erros durante o registro. Refaça criteriosamente.\n");
                                        } 
                                else{
                                        system("clear"); 
                                        *matt = conp;
                                        setbuf(stdin,NULL);
                                        printf("Informaçoes de cadastro\nNome: %s\nData de nascimento: %s\n", nome, prof[conp].copdat);
                                    	printf("CPF: %s\nSexo: %s\nMatricula: %d\n", CPF,prof[conp].sexoc,*matt);
                                    	*cad=1;
                                    	conp++;
                                    	printf("Cadastro efetuado com sucesso. Pressione enter para continuar...\n");
                                    	getchar();
                                    }
                                        
    }
    while(op!=0 && conp<=QTD);
    }
                                        else{
                                            printf("Não há vagas.\n");}
                                        return;
}
void listarp()
{
    
    system("clear");
        getchar();
    setbuf(stdin,NULL);    
    int cont, op;
    if(qtdp==0 || qtdp>QTD){
        
        printf("Ainda não há registro de professores. Pressione enter para continuar...\n");
        getchar();
        return;
    }
    I:
    system("clear");
    printf("Modo de listamento:\n 1- Todos\n2- Professores do Sexo masculino\n3- Professores do Sexo feminino\n0- Para retornar ao menu professor\n");
    scanf("%d", &op);
    switch(op)
    {
    case 1:
                printf("||///////////////////////Professores cadastrados no sistema///////////////////////||\n");
                for(cont=1;cont<=qtdp;cont++)
                {
                    if(prof[cont].cadastrado == 1)
                    {
                            printf("|| Numero da Matricula: %d\n", prof[cont].matricula);
                            printf("|| Nome: %s\n", prof[cont].nome);
                            printf("|| Data de nascimento: %s\n", prof[cont].copdat);
                            printf("|| Sexo: %s\n", prof[cont].sexoc);
                            printf("|| CPF: %s\n", prof[cont].CPF);
                            printf("||///////////////////////\n\n");
                    }
                    else
                        continue;
    }
    getchar();        
    break;        
    
    case 2:
                printf("||///////////////////////Professores cadastrados no sistema///////////////////////||\n");
                for(cont=1;cont<=qtdp;cont++)
                {
                    if((prof[cont].cadastrado == 1 && alunos[cont].sexo) == 'm' || (prof[cont].cadastrado == 1 && alunos[cont].sexo == 'M'))
                    {
                            printf("|| Numero da Matricula: %d\n", prof[cont].matricula);
                            printf("|| Nome: %s\n", prof[cont].nome);
                            printf("|| Data de nascimento: %s\n", prof[cont].copdat);
                            printf("|| Sexo: %s\n", prof[cont].sexoc);
                            printf("|| CPF: %s\n", prof[cont].CPF);
                            printf("||///////////////////////\n\n");
                    }
                    else
                        continue;
                }        
    getchar();        
    break;    
    
    case 3:
                printf("||///////////////////////Professores cadastrados no sistema///////////////////////||\n");
                for(cont=1;cont<=qtdp;cont++)
                {
                    if((prof[cont].cadastrado == 1 && prof[cont].sexo) == 'f' || (prof[cont].cadastrado == 1 && prof[cont].sexo == 'F'))
                    {
                            printf("|| Numero da Matricula: %d\n", prof[cont].matricula);
                            printf("|| Nome: %s\n", prof[cont].nome);
                            printf("|| Data de nascimento: %s\n", prof[cont].copdat);
                            printf("|| Sexo: %s\n", prof[cont].sexoc);
                            printf("|| CPF: %s\n", prof[cont].CPF);
                            printf("||///////////////////////\n\n");
                    }
                    else
                        continue;
                }        
    getchar();        
    break;
    
    case 0: break;
    default:printf("Opção inválida.\n"); getchar(); goto I;
    }
    
    
    
            
            
    printf("Pressione Enter para continuar...\n");
    getchar();
    return;
}

int validarSexop()
{    
    char sex;  
	setbuf(stdin, NULL);
    fflush(stdin);
    if (strlen(&prof[conp].sexo)=='\0'){
        printf("Não há registro.\n");
        erros+= 1;
        return 1;}
    else{    
        if (prof[conp].sexo == 'M' || prof[conp].sexo == 'm'){
            strcpy(prof[conp].sexoc, "Masculino");
				return 0;}
				
        else if (prof[conp].sexo == 'F' || prof[conp].sexo == 'f'){
            strcpy(prof[conp].sexoc, "Feminino");
				return 0;}
                
        else if (prof[conp].sexo == 'O' || prof[conp].sexo == 'o'){
            strcpy(prof[conp].sexoc, "Outro");
				return 0;}
                
        else{
            strcpy(&prof[conp].sexo, "Sua opção foi inválida.");
                erros+=1;
        return 1;}
    }
    setbuf(stdin, NULL);
    fflush(stdin);
}
int ValidarDatap(char data[])
{
    
    strcpy(prof[conp].copdat,data);
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
        //verificar mês
        if (mm >= 1 && mm <= 12)
        {
            //verificar dias
                            if((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12))
                            {
                                //printf("Parou aqui");
                                erros=0;
                                return 0;
                            }
                                            
                                
                            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11))
                            {
                                //printf("Parou 2 aqui");
                                erros=0;
                                return 0;
                                
                            }
                                            
                            else if((dd >= 1 && dd <= 28) && (mm == 2))
                            {
                                //printf("Parou aqui 3");
                                erros=0;
                                return 0;
                            }
                                           
                                            
                            else if(dd == 29 && mm == 2 && (aa % 400 == 0 || (aa % 4 == 0 && aa % 100 != 0)))
                            {//bissexto
                                //printf("Parou aqui 4");
                                erros=0;
                                return 0;
                            }
                            
                            else
                                {
                                    //printf("Parou aqui, tudo errado.");
                                    erros+=1;
                                    return 1;
                                }
                                           
        }
        else
        {   
            //printf("Mês inválido\n");
            erros+=1;
            return 1;
        }
    }
    else
    {
        //printf("O ano está errado");
        erros+=1;
        return 1;
    }    
    }
    //printf("Fim do programa.");
    //return 50;
}
void excluirp()
{
    printf("Aqui");
    getchar();
    int i,j, op, op2;
        
        system("clear");
    if(qtdp==0) {
        printf("Não há professores no sistema. Tente mais tarde.\n"); 
        getchar();
        return;}
        
        
    else
    {
    I:
                for(i=1;i<=qtdp;i++)
                    {
                                    if(prof[i].cadastrado == 1)
                                    {
                                            printf("||///////////////////////\n\n");
                                            printf("|| Nome: %s\n", prof[i].nome);
                                            printf("|| Data de nascimento: %s\n", prof[i].copdat);
                                            printf("|| Sexo: %s\n", prof[i].sexoc);
                                            printf("|| CPF: %s\n", prof[i].CPF);
                                            printf("||///////////////////////\n\n");
                                    }
                    }                
                                printf("Deseja excluir um professor?\n1- Sim\n2- Não\n");
                                            scanf("%d", &op);   
                switch(op)
                {               
                            case 1:
                                            printf("Digite o numero da matricula do professor que quer excluir.\n");
                                                scanf("%d", &op2);
                                                for(i=1;i<=qtdp;i++)
                                                {
                                                                if(prof[i].matricula==op2)
                                                                    {
                                                                        prof[i].cadastrado=0;
                                                                        printf("Professor excluído!\n");
                                                                        getchar();
                                                                        for(j=i;j<=qtdp;j++)
                                                                        {
                                                                        if(prof[i].cadastrado==0)
                                                                                  {
                                                                                   prof[j+1].matricula--;
                                                                                   qtdp--;
                                                                                    }
                                                                        }            
                                                                           
                                                                    }
                                                }                    
                            break;   
                            
                                     case 2:
                                            printf("Digite o numero da matricula do aluno que deseja atualizar.\n");
                                                scanf("%d", &op2);
                                            
                                            for(i=1;i<=prof[i].matricula==op2;i++)   
                                            {
                                                            if(prof[i].matricula==op2)
                                                            {
                                                            cadastrarprof(prof[i].nome, prof[i].dtnasc, &prof[i].sexo, &prof[i].cadastrado, prof[i].CPF, &prof[i].matricula);
                                                            conp--;
                                                            }  
                                                            else
                                                                continue;
                                            }                
                            
                            
                            
                            
                            case 0: break; 
                            default:printf("Opção inválida!\n"); goto I;
                                
                                    
                }                   
                  
    }    
    
    printf("Programa encerrado!\n");
        getchar();
        return;
} 









