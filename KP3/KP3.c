#include <stdio.h> 
#include <math.h>

//функция факториала
long double fac_num (long double n)
{
    long double fa;
    for (fa = 1; n > 1; fa *= (n--)); return fa;
}

int main()
{
    int n, iterat;
    double tal_ans, func, tal_ch, a = 0.1, b = 0.6, x = 0.0; 
    long double eps = 1.0l;
    //Вычисляем машинный епсилон 
    while (2.0l + eps / 2.0l > 2.0l) {
        eps /= 2.0l;
    }
    printf("Machine eps double = %.16Le\n", eps); printf("Write n: \n");
    scanf("%d", &n);
    printf("n = %d, \n", n);
    printf("Table of Teylor values and stand f(x) = cos(x)\n");

    printf(" 	\n");
    printf("-------------------------------------------------------------------\n");
    printf("| x     |	sum	       |	f(x)	      |count iter |");

    printf(" 	\n");
    for (int i = 1; i <= n; i++) { 
        iterat = 1;
        tal_ch = 1; 
        func = cosh(x); 
        tal_ans = 1;
        while (fabs(tal_ch) > eps && iterat < 100) {
        tal_ch = (pow(x, 2*iterat))/fac_num(2*iterat); 
        tal_ans += tal_ch;
        iterat++;
    }
    printf("-------------------------------------------------------------------\n");
    printf("| %.3f | %.18lf | %.18lf |	%d	  |\n", x, tal_ans, func, iterat);
    printf("-------------------------------------------------------------------");
    printf(" 		\n");
    x += fabs(a - b) / n;
    }
return 0;
}
