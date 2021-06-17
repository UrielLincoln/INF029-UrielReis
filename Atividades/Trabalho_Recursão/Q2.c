#include <stdio.h>
#include <stdlib.h>


int fi(int n) 
{
	if(n < 2) {
		return 1;
	}
	//printf("N: %d\nN - 1 : %d\nN - 2 : %d\n(N - 1) + (N - 2) = %d\n\n", n, n - 1, n - 2, (n - 1) + (n - 2));
	//getchar();\n
	return fi(n - 1) + fi(n - 2);
}
int main()
{
    int num = 10, y = 0, a;
    a=fi(num);
    printf("Seq: %d", a);

    return 0;
}

