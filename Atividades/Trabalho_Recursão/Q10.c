#include <stdio.h>
#include <stdlib.h>


int Multip_Rec(int n1, int n2){
    if(n2 <= 1)
        return n1;
    return n1 + Multip_Rec(n1,n2 - 1);
}
int main()
{
     int x = 9, y = 5;
     printf("Resultado = %d", Multip_Rec(x,y));
     return 0;
}

