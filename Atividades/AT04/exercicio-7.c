#include <stdio.h>
#include <stdlib.h>
#include <string.h>
const int QTD =3;//QUANTIDADE DE PALAVRAS
void lert(int QTD)
{
    char plv[QTD][50];
    int i,j;
    for(i=0;i<QTD;i++)
    {
        for(j=0;j<1;j++) 
       {  
            printf("Digite uma palavra: ");
                scanf(" %s", plv[i]); 
       }   
    }
    for(i=0;i<QTD;i++)
    {
       for(j=0;j<1;j++) 
        printf("palavra: %s\n", plv[i]); 
    } 
}
int main()
{
    lert(QTD); //quantidade de palavras
    system("pause");
    return 0;
}

