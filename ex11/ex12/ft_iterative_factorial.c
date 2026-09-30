#include <stdio.h>
#include <stdlib.h>

int ft_iterative_factorial(int nb)
{
    if (nb == 0 || nb == 1)
        return 1;
    
    return nb * factorial (nb - 1);
    // a return not self calling the function will break the stack 
}

