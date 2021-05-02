// #################################################
//  Instituto Federal da Bahia
//  Salvador - BA
//  Curso de Análise e Desenvolvimento de Sistemas http://ads.ifba.edu.br
//  Disciplina: INF029 - Laboratório de Programação
//  Professor: Renato Novais - renato@ifba.edu.br

//  ----- Orientações gerais -----
//  Descrição: esse arquivo deve conter as questões do trabalho do aluno.
//  Cada aluno deve renomear esse arquivo para Aluno<MATRICULA>.c
//  O aluno deve preencher seus dados abaixo, e implementar as questões do trabalho

//  ----- Dados do Aluno -----
//  Nome: Uriel Lincoln Santana Reis
//  email: uriellincoln97@gmail.com
//  Matrícula: 2019116044
//  Semestre: 2º

//  Copyright © 2016 Renato Novais. All rights reserved.
// Última atualização: 20/06/2018 - 19/08/2016

// #################################################

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/*
## função utilizada para testes  ##

 somar = somar dois valores
@objetivo
    Somar dois valores x e y e retonar o resultado da soma
@entrada
    dois inteiros x e y
@saida
    resultado da soma (x + y)
 */
int somar(int x, int y)
{
    int soma = 0;
    soma = x + y;
    return soma;
}

/*
## função utilizada para testes  ##

 fatorial = fatorial de um número
@objetivo
    calcular o fatorial de um número
@entrada
    um inteiro x
@saida
    fatorial de x -> x!
 */
int fatorial(int x)
{ //função utilizada para testes
    int fat = 1;
    return fat;
}

/*
 Q1 = validar data
@objetivo
    Validar uma data
@entrada
    uma string data. Formatos que devem ser aceitos: dd/mm/aaaa, onde dd = dia, mm = mês, e aaaa, igual ao ano. dd em mm podem ter apenas um digito, e aaaa podem ter apenas dois digitos.
@saida
    0 -> se data inválida
    1 -> se data válida
 @restrições
    Não utilizar funções próprias de string (ex: strtok)   
    pode utilizar strlen para pegar o tamanho da string
 */
//depois mudar pra int 
//int q1(char *data)
// q1(char *data)

int q1(char *data)
{
    setbuf(stdin, NULL);
    int i = 0, cont=1, x=0,y=0, z=0;
    char copia[11] = {0};
    char sDia[3] = {0}, sMes[3] = {0}, sAno[5] = {0};
    int iDia, iMes, iAno;

    for(i=0; i<strlen(data);i++)
    {
        
        if(data[i] == '/' || data[i] == '\0')
        { //IGNORA A BARRA OU O ULTIMO CARACTERE
                cont++;
                continue;
        }

          else
          {
                        if(cont==1)
                        { 
                          sDia[x] = data[i];
                          x++; 
                        }

                        if(cont==2){ 
                          sMes[y] = data[i];  
                          y++;  
                        }

                        if(cont==3)
                        { 
                          sAno[z] = data[i];
                          z++;
                        }
          }

    }
    iDia = atoi(sDia);
    iMes = atoi(sMes);
    iAno = atoi(sAno);

    //printf("Dia: %d\nMes: %d\nAnos:%d", iDia,iMes,iAno);
    //getchar();
    if(iAno<100)
      iAno+=2000;


    //printf("Dia: %d\n", iDia);
    //printf("Mes: %d\n", iMes);
    //printf("Ano: %d\n", iAno);

    if (iAno >= 1900 && iAno <= 2100)
    {
        if (iMes >= 1 && iMes <= 12)
        {
                            if((iDia >= 1 && iDia <= 31) && (iMes == 1 || iMes == 3 || iMes == 5 || iMes == 7 || iMes == 8 || iMes == 10 || iMes == 12))
                            {
                                return 1;
                            }
                                            
                                
                            else if ((iDia >= 1 && iDia <= 30) && (iMes == 4 || iMes == 6 || iMes == 9 || iMes == 11))
                            {
                                return 1;
                                
                            }
                                            
                            else if((iDia >= 1 && iDia <= 28) && (iMes == 2))
                            {
                                return 1;
                            }
                                           
                                            
                            else if(iDia == 29 && iMes == 2 && (iAno % 400 == 0 || (iAno % 4 == 0 && iAno % 100 != 0)))
                            {
                                return 1;
                            }
                            
                            else
                                {
                                    return 0;
                                }
                                           
        }
        else
        {   
            return 0;
        }
    }
    else
    {
        return 0;
    }    
}


/*
 Q2 = diferença entre duas datas
 @objetivo
    Calcular a diferença em anos, meses e dias entre duas datas
 @entrada
    uma string datainicial, uma string datafinal. Além disso, a função tem três parâmetros qtdDias, qtdMeses e qtdAnos. Esses três parâmetros devem ser utilizados para guardar os resultados dos cálculos. Na chamada da função deve passar o valor -1 para os três
 @saida
    1 -> cálculo de diferença realizado com sucesso
    2 -> datainicial inválida
    3 -> datafinal inválida
    4 -> datainicial > datafinal
 */


int q2(char *datainicial, char *datafinal, int *qtdDias, int *qtdMeses, int *qtdAnos)
{

    //calcule os dados e armazene nas três variáveis a seguir
    int nDias, nMeses, nAnos;
    //data inicial
    int xDias, xMeses, xAnos;
    char yDias[3] = {0}, yMeses[3] = {0}, yAnos[5] = {0};
    //data final
    int aDias, aMeses, aAnos;
    char bDias[3] = {0}, bMeses[3] = {0}, bAnos[5] = {0};

    int x=0,y=0,z=0;
    int cont = 1, i;

    //separando strings
    for(i=0; i<strlen(datainicial);i++)
    {
        
        if(datainicial[i] == '/' || datainicial[i] == '\0')
        { //IGNORA A BARRA OU O ULTIMO CARACTERE
                cont++;
                continue;
        }

          else
          {
                        if(cont==1)
                        { 
                          yDias[x] = datainicial[i];
                          x++; 
                        }

                        if(cont==2){ 
                          yMeses[y] = datainicial[i];  
                          y++;  
                        }

                        if(cont==3)
                        { 
                          yAnos[z] = datainicial[i];
                          z++;
                        }
          }

    }
    //data inicial convertida para inteiro
    xDias = atoi(yDias);
    xMeses = atoi(yMeses); 
    xAnos = atoi(yAnos);

    //printf("Dias: %d\nMes:%d\nAno:%d", xDias, xMeses,xAnos);
    //getchar();


    //resetando os valores da variaveis para reutilizá-las
    x = 0, y = 0, z=0;
    cont = 1;
    //convertendo data final
    for(i=0; i<strlen(datafinal);i++)
    {
        
        if(datafinal[i] == '/' || datafinal[i] == '\0')
        { //IGNORA A BARRA OU O ULTIMO CARACTERE
                cont++;
                continue;
        }

          else
          {
                        if(cont==1)
                        { 
                          bDias[x] = datafinal[i];
                          x++; 
                        }

                        if(cont==2){ 
                          bMeses[y] = datafinal[i];  
                          y++;  
                        }

                        if(cont==3)
                        { 
                          bAnos[z] = datafinal[i];
                          z++;
                        }
          }

    }
    
    aDias = atoi(bDias);
    aMeses = atoi(bMeses); 
    aAnos = atoi(bAnos);

      //printf("Ano inicial: %d\nAno final: %d", xAnos, aAnos);
    setbuf(stdin,NULL);
    if(q1(datainicial) == 0)
    {
     // printf("Data inicial inválida.\n");
      return 2;
      }
      
    else if(q1(datafinal) == 0)
    {
     // printf("Data final inválida.\n");
      return 3;
      }

    else if(xAnos>aAnos){
      return 4;
    }
    //aqui começa de fato o programa
    else if(xAnos == aAnos)//ano igual
    {
            //nDias, nMeses, nAnos;
            nAnos = 0;
           // printf("Quantidade de anos: %d\n", nAnos);

            if(xMeses == aMeses)
            {
              nMeses = 0;
             // printf("Quantidade de meses: %d\n", nMeses);

                //dias iguais
                if(xDias == aDias)
                {
                  nDias = 0;
                 // printf("Quantidade de dias: %d\n", nDias);
                }
                else if(xDias < aDias)
                {
                  nDias = aDias - xDias;
                  if(aDias == 29 && aMeses == 2 && (aAnos % 400 == 0 || (aAnos % 4 == 0 && aAnos % 100 != 0)))
                  {
                    nDias+=1;
                  }
                //  printf("Quantidade de dias: %d\n", nDias);
                }
                else
                {
                  return 4;
                }
            }    
            else if(xMeses > aMeses) 
              {
                return 4;
              }
            else if(xMeses < aMeses)//meses diferença
            {
              nMeses = aMeses - xMeses;//resultado
              //printf("Quantidade de meses: %d\n", nMeses);
              if(xDias == aDias)//calcular dias
                {
                  nDias = 0;
                 // printf("Quantidade de dias: %d\n", nDias);
                }
                else if(xDias < aDias)
                {
                  nDias = aDias - xDias;
                //  printf("Quantidade de dias: %d\n", nDias);
                }
                else
                {
                  return 4;
                }

            }
    }

    //ano diferente
    else if(xAnos < aAnos)
    {
            nAnos = aAnos - xAnos;
           printf("Quantidade de anos: %d\n", nAnos);

            if(xMeses == aMeses)
            {
              nMeses = 0;
             //printf("Quantidade de meses: %d\n", nMeses);

                //dias iguais
                if(xDias == aDias)
                {
                  nDias = 0;
              //    printf("Quantidade de dias: %d\n", nDias);
                }
                
                else if(xDias < aDias)
                {
                  nDias = aDias - xDias;
                 // printf("Quantidade de dias: %d\n", nDias);
                }
                else if(xDias > aDias)
                    {
                      nDias+= xDias - aDias;


                      for(i=xAnos;i==aAnos;i++)
                      {
                        if(aMeses == 2 && (aAnos % 400 == 0 || (aAnos % 4 == 0 && aAnos % 100 != 0)))
                          {
                            nDias+=1;
                          }
                      }

                    }
                else
                {
                  return 4;
                }
            }    
            else if(xMeses > aMeses) 
              {
                return 4;
              }
            else if(xMeses < aMeses)
            {
              nMeses = aMeses - xMeses;
              if(xDias == aDias)//calcular dias
                {
                  nDias = 0;
                //  printf("Quantidade de dias: %d\n", nDias);
                }
                else if(xDias < aDias)
                {
                  nDias = aDias - xDias;
                 // printf("Quantidade de dias: %d\n", nDias);
                }
                else
                {
                  return 4;
                }

            }
        
        //meses diferentes
    }


    *qtdDias = aDias - xDias;
    *qtdMeses = aMeses - xMeses;
    *qtdAnos = aAnos - xMeses;



if (qtdMeses < 0){
        qtdAnos--;
        *qtdMeses = 12;
    }
    if (qtdDias < 0){
        qtdMeses--;
        *qtdDias = xDias + aDias;
    }

    
    *qtdDias = nDias;
    *qtdAnos = nAnos;
    *qtdMeses = nMeses;

    //coloque o retorno correto
    //printf("Chegou até o final\n");
    return 1;
}

/*
 Q3 = encontrar caracter em texto
 @objetivo
    Pesquisar quantas vezes um determinado caracter ocorre em um texto
 @entrada
    uma string texto, um caracter c e um inteiro que informa se é uma pesquisa Case Sensitive ou não. Se isCaseSensitive = 1, a pesquisa deve considerar diferenças entre maiúsculos e minúsculos.
        Se isCaseSensitive != 1, a pesquisa não deve  considerar diferenças entre maiúsculos e minúsculos.
 @saida
    Um número n >= 0.
 */
int q3(char *texto, char c, int isCaseSensitive)
{
    int qtdOcorrencias = 0;
    int i,j, h;
    int contador, AUXN, AUXM, AUXZ;

    for(i = 0; i<strlen(texto);i++)
    {

        if(isCaseSensitive == 1)
        {
            AUXZ = c;//pensei em fazer fazer um conversor pro Char c, mas acontece que não têm como utilizar um caractere especial por causa do tamanho
            AUXN=texto[i];
            AUXM=texto[i+1];
            if((AUXM>=-128 && AUXM<=-124)&&(AUXN == -61)){
              texto[i] = 'A';
            }
            else if((AUXM>=-120 && AUXM<=-117)&&(AUXN == -61))
            texto[i] = 'E'; 
            else if((AUXM>=-116 && AUXM<=-113)&&(AUXN == -61))
            texto[i] = 'I';
            else if((AUXM>=-109 && AUXM<=-106)&&(AUXN == -61))
            texto[i] = 'O';
            else if((AUXM>=-103 && AUXM<=-100)&&(AUXN == -61))
            texto[i] = 'U';
            //CASO SEJA VOGAL MINUSCULA A LETRA NO INDICE I DA STRING
            if((AUXM>=-95 && AUXM<=-92)&&(AUXN == -61)){
            texto[i] = 'a';}
          //  printf("A letra ta aqui\n");}
            else if((AUXM>=-85 && AUXM<=-82)&&(AUXN == -61))
            texto[i] = 'e'; 
           else if((AUXM>=-84 && AUXM<=-81)&&(AUXN == -61))
            texto[i] = 'i';
            else if((AUXM>=-77 && AUXM<=-74)&&(AUXN == -61))
            texto[i] = 'o';
            else if((AUXM>=-71 && AUXM<=-68)&&(AUXN == -61))
            texto[i] = 'u'; 










            if(texto[i] == c){//caso o char seja maiusculo
            qtdOcorrencias++;}
            else
              continue;   
        }   





        //CASE Sensitive OFF
        else if(isCaseSensitive == 0)
        {
            //"áàãâä" -95 a 92 //"éèêë" -88 a -85//"íìîï"" -84 a -81//"óòõôö"" -77 a -74//úùüû -71 a -68
            AUXN=texto[i];
            AUXM=texto[i+1];
            if((AUXM>=-128 && AUXM<=-124)&&(AUXN == -61)){
              texto[i] = 'A';
            }
            else if((AUXM>=-120 && AUXM<=-117)&&(AUXN == -61))
            texto[i] = 'E'; 
            else if((AUXM>=-116 && AUXM<=-113)&&(AUXN == -61))
            texto[i] = 'I';
            else if((AUXM>=-109 && AUXM<=-106)&&(AUXN == -61))
            texto[i] = 'O';
            else if((AUXM>=-103 && AUXM<=-100)&&(AUXN == -61))
            texto[i] = 'U';
            //CASO SEJA VOGAL MINUSCULA A LETRA NO INDICE I DA STRING
            if((AUXM>=-95 && AUXM<=-92)&&(AUXN == -61)){
            texto[i] = 'a';}
            else if((AUXM>=-85 && AUXM<=-82)&&(AUXN == -61))
            texto[i] = 'e'; 
           else if((AUXM>=-84 && AUXM<=-81)&&(AUXN == -61))
            texto[i] = 'i';
            else if((AUXM>=-77 && AUXM<=-74)&&(AUXN == -61))
            texto[i] = 'o';
            else if((AUXM>=-71 && AUXM<=-68)&&(AUXN == -61))
            texto[i] = 'u';




            if(texto[i] + 32 == c)
              qtdOcorrencias++;
            else if(texto[i] == c + 32)//caso o char seja maiusculo e o char string minusculo
            qtdOcorrencias++;
            else if(texto[i] - 32 == c)//CHAR STRING MAIUSCULO E CHAR TBM 
            qtdOcorrencias++;
            else if(texto[i] == c)//caso o char seja seja simplesmente igual
            qtdOcorrencias++;
            else
              continue;
        } 
        
    }
    //printf("\nQuantidade de ocorrencias: %d\n", qtdOcorrencias);




    return qtdOcorrencias;
}

/*
 Q4 = encontrar palavra em texto
 @objetivo
    Pesquisar todas as ocorrências de uma palavra em um texto
 @entrada
    uma string texto base (strTexto), uma string strBusca e um vetor de inteiros (posicoes) que irá guardar as posições de início e fim de cada ocorrência da palavra (strBusca) no texto base (texto).
 @saida
    Um número n >= 0 correspondente a quantidade de ocorrências encontradas.
    O vetor posicoes deve ser preenchido com cada entrada e saída correspondente. Por exemplo, se tiver uma única ocorrência, a posição 0 do vetor deve ser preenchido com o índice de início do texto, e na posição 1, deve ser preenchido com o índice de fim da ocorrencias. Se tiver duas ocorrências, a segunda ocorrência será amazenado nas posições 2 e 3, e assim consecutivamente. Suponha a string "Instituto Federal da Bahia", e palavra de busca "dera". Como há uma ocorrência da palavra de busca no texto, deve-se armazenar no vetor, da seguinte forma:
        posicoes[0] = 13;
        posicoes[1] = 16;
        Observe que o índice da posição no texto deve começar ser contado a partir de 1.
        O retorno da função, n, nesse caso seria 1;

 */
int q4(char *strTexto, char *strBusca, int posicoes[30])
{
    int i, j, k = 0, cont = 0, cont2 = 0;
    char copia[10] = {'\0'};
    int x=0, y=0;

    //"áàãâä" -95 a 92 //"éèêë" -88 a -85//"íìîï"" -84 a -81//"óòõôö"" -77 a -74//úùüû -71 a -68
    int texto_int[100]; //A : -128 A -124//E : -120 A -117//I : -116 A -113// O : -109 A -106//U : -103 A -100 
    int texto_int2[100];
    int a, b;
      
    for (a = 0; strTexto[a] != '\0'; a+=1)//percorre a string que foi passada
    {
        texto_int[a] = strTexto[a]; 
        texto_int[a+1] = strTexto[b+1]; 
    }

    k = 0;
    for (b = 0; b < a; b++)
    {
        if (texto_int[b] != -61)
        {
            texto_int2[k] = texto_int[b];
            k++;
        }    
    }

for(i=0;texto_int2[i]!='\0';i++)
    {
        if(strBusca[0]==texto_int2[i])
        {
            k = i;
            for(j=0;j<strlen(strBusca);j++)
            {
                if(strBusca[j]==texto_int2[k])
                {
                    y=k+1;
                    k++;
                    cont2++;
                }
            }
            //k=0;
            if(cont2 >= strlen(strBusca))
            { 
                posicoes[x] = i+1;
                x++;
                posicoes[x] = y;
                x++;

                cont++;
            }
            cont2=0;
        }
            else
                continue;
    }
    return cont;
}

/*
 Q5 = inverte número
 @objetivo
    Inverter número inteiro
 @entrada
    uma int num.
 @saida
    Número invertido
 */

int q5(int num)
{

    int numc = 0;
    int i=0,j=0, aux[10], auxy[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000}, cont = 0;
    
    while(num>0)
    {
    cont++;
    aux[cont] = num%10;
    num= num/10;
    }

    for(i=cont-1, j=1;i>=0;i--,j++){
        numc += aux[j] * auxy[i];
    }

    return numc;
}

/*
 Q5 = ocorrência de um número em outro
 @objetivo
    Verificar quantidade de vezes da ocorrência de um número em outro
 @entrada
    Um número base (numerobase) e um número de busca (numerobusca).
 @saida
    Quantidade de vezes que número de busca ocorre em número base
 */

int q6(int numerobase, int numerobusca)
{
    int qtdOcorrencias = 0;
    int cont = 0, auxy[10] = {1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};//não fica visualmente legal, mas é funcional
    int num, numa;
    num = numerobase;
    numa = numerobusca;
    int aux[50];
    int j = 0;
    
    while(numa>0)
    {
    cont++;
    aux[cont] = numa%10;
    numa = numa/10;
    }

    while(num>0)
    {
    j = num%auxy[cont];
        if(j==numerobusca)
            qtdOcorrencias++;

    num = num/10;
    }
    return qtdOcorrencias;


}