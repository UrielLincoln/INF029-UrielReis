/*Evolua o programa que tem a função cadastrarCliente, para fazer as validações dos dados. Cada
validação deve ser feita em uma função diferente, conforme lista abaixo. A função cadastrarCliente
deve chamar cada uma dessas funções. A função main deve imprimir se o cadastro foi realizado
com sucesso ou se houve erro, informando onde foi o erro:       
• função validarNome: recebe o nome digitado, e valida se nome tem até 20 caracteres; *****************************COMPLETO
• função validarSexo: recebe o sexo digitado, e valida é um sexo válido (opções: m e M para *****************************COMPLETO
masculino; f e F para feminino, o e O para outro).
• função validarCPF: recebe o cpf digitado, e valida é um cpf válido; *****************************COMPLETO
• função validarNacimento: recebe o data digitada, e valida é uma data válida.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#define QTD 0

int conti = 0;
int erroF = 0;
int errnome=0,errcpf=0,errns=0,errsx=0;
struct cad_cliente
{
    char nome[30];
    char data[11];
    char cpf[12];
    char sexo, sex[12], sexx[12];
};
struct cad_cliente CAD[QTD];

void cadclt();
void validarNome();
void validarSexo();
void ValidarCPF(char cpfvar[11]);
void ValidarData(char data[11]);

int main(){
	setlocale(LC_ALL, "Portuguese");

    cadclt();
    erroF = errsx+errnome+errcpf+errns;
    if(erroF>0){
    printf("Numero total de erros: %d\n", erroF);
    if(errns==1)
    {
        printf("Erro encontrado na data de nascimento\n");
    }
    if(errsx==1)
    {
        printf("Erro encontrado no sexo\n");
    }
    if(errnome==1)
    {
        printf("Erro encontrado no nome\n");
    }
    if(errcpf==1)
    {
        printf("Erro encontrado no cpf\n");
    }
    }// mostrar onde ocorreram os erros
    
	
    else{
    printf("Cadastro realizado com sucesso\n");
    }
    
}
//strlen(const *char)
void cadclt(){
    int op;
    char copdat[11];
    setbuf(stdin, NULL);
    printf("Digite o nome do cliente: ");
        fgets(CAD[conti].nome,50,stdin);
    setbuf(stdin, NULL); 
    fflush(stdin);
    printf("Digite a data de nascimento no modelo dd/mm/aa\n");
        fgets(CAD[conti].data,11,stdin);
    setbuf(stdin, NULL);    
    printf("Informe uma letra referente ao sexo: \nM- Masculino\nF- Feminino\nO- Outro\n");
        scanf("  %c", &CAD[conti].sexo);
    //setbuf(stdin, NULL);
    getchar();
    printf("Informe somente os numeros do seu CPF: \tExemplo: 12345678901\n");
        fgets(CAD[conti].cpf,12,stdin);
    setbuf(stdin, NULL);
    fflush(stdin);
    strcpy(copdat,CAD[conti].data);
    ValidarCPF(CAD[conti].cpf);
    ValidarData(CAD[conti].data);
    validarSexo();
    validarNome();
    //system("clear");
    printf("Informaçoes de cadastro\nNome: %sData de nascimento: %s\n", CAD[conti].nome,copdat);
	printf("CPF: %s\nSexo: %s\n", CAD[conti].cpf,CAD[conti].sexx);
    return;
}
void validarNome()
{
int i;
int cont=0;
errnome=0;
    if(strlen(CAD[conti].nome)==0)
    {
        errnome=1;
        return;
    }
    else
    {
        for(i=0;CAD[conti].nome[i]!='\0';i++)
    {
        if(CAD[conti].nome[i]==' ' || CAD[conti].nome[i]=='\n'){
            continue;}
      cont+=1;
    }
    if(cont>20){
      errnome=1;
        return;}
    else
        printf("\n");
    }    
}
void validarSexo()
{
errsx=0;    
	setbuf(stdin, NULL);
    fflush(stdin);
    if (strlen(&CAD[conti].sexo)=='\0'){
        printf("Não há registro.\n");
        errsx=1;
        return;}
    else{    
        if (CAD[conti].sexo == 'M' || CAD[conti].sexo == 'm'){
            strcpy(CAD[conti].sexx, "Masculino");
                //printf("Opção válida");
				return;}
				
        else if (CAD[conti].sexo == 'F' || CAD[conti].sexo == 'f'){
            strcpy(CAD[conti].sexx, "Feminino");
                //printf("Opção válida");
				return;}
                
        else if (CAD[conti].sexo == 'O' || CAD[conti].sexo == 'o'){
            strcpy(CAD[conti].sexx, "Outro");
                //printf("Opção válida");
				return;}
                
        else{
            strcpy(CAD[conti].sexx, "Sua opção foi inválida.");
                errsx=1;
        return;}
    }
    setbuf(stdin, NULL);
    fflush(stdin);
}
void ValidarCPF(char cpfvar[11])
{
errcpf=0;    
        fflush(stdin);
        int cpff[11], i, j;
        int soma=0, soma2=0,r1,r2;
        int contador;

        setbuf(stdin, NULL);
        if(strlen(cpfvar)!=11){
            printf("%d quantidade",strlen(cpfvar));
            printf("Erro aqui xdxd\n");
            //printf("A quantidade de caracteres: %ld", strlen(CAD[conti].cpf));
            errcpf=1;
            return;}
        else
        {
            for(i=0;i<11;i++)
            {
               cpff[i] = cpfvar[i] - 48;
            }
        }
        for(i=0,j=10;i<9;i++,j--){soma+=cpff[i]*j;}r1=(soma*10)%11;//Verificador digito 1
        //printf("Digito 1 = %d\n", r1); //Mostra o digito 1
        for(i=0,j=11;i<10;i++,j--){soma2+=cpff[i]*j;}r2=(soma2*10)%11;//Verificador digito 2
        //printf("Digito 2 = %d\n", r2); Mostra o digito 2
        
        if(r1 == cpff[9] && r2 == cpff[10]){
            printf("CPF válido.\n");
            errcpf=0;
            setbuf(stdin, NULL);
            return;
            
        }
        else{
            printf("CPF inválido\n");
			errcpf=1;
			setbuf(stdin, NULL);
			}
        printf("Last %d e %d", cpff[9],cpff[10]);
        return;
}   
void ValidarData(char data[11])
{
    int i, idata[11],dd,mm,aa,y=0;
    //char data[11];
    char *aux;
            
    if(strlen(data)!=10){
        //printf("Erro!");
        errns=1;
        return;
    }      
    else{
        aux=strtok(data,"/"); 
        dd = atoi(aux);
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
            if((dd >= 1 && dd <= 31) && (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)){
                errns=0;}
            else if ((dd >= 1 && dd <= 30) && (mm == 4 || mm == 6 || mm == 9 || mm == 11)){
                errns=0;}
            else if((dd >= 1 && dd <= 28) && (mm == 2)){
                errns=0;}
            else if(dd == 29 && mm == 2 && (aa % 400 == 0 || (aa % 4 == 0 && aa % 100 != 0))){//bissexto
                errns=0;}
            else{
            errns=1;}
        }
        else
        {
            errns=1;
            return;
        }
    }
    else
    {
        errns=1;
        return;
    }    
    }
    //printf("Fim do programa.");
}  


    







