#include <stdio.h>
#include <stdlib.h>

// method of fruteforcing is baf
int ft_sqrt(int nb)
{
    int i;
    int sqrt;

    i = 1;

    while (i < nb / 2)
        if (nb % i == 0)
            sqrt *= i;         
    if (sqrt * sqrt == nb)
        return sqrt;
    else 
        return 0;
}