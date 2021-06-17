#include <stdio.h>
#include <stdlib.h>


int inverter(int n, int x)
{
    if(n<=0)
    {
        if(n/10==0)
        {
            x/=10;
            return x;
        }
       else
       {    
            x+= (n%10);
            return inverter(n/10,x*=10);
       }    
    }
    else
    {   
        x+= (n%10);
        return inverter(n/10,x*=10);
    }
}

int main()
{
    int num, y = 0, a;
    printf("Digite o numero para ser invertido: \n");
        scanf("%d", &num);
    a=inverter(num, y);
    printf("inverso = %d", a);

    return 0;
}
