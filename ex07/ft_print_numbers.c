#include <stdio.h>
#include <stdlib.h>

void ft_print_numbers(void)
{
    /* abusin asci code */

    char * a;
    char b = "0"; /* not the char but the ascii value */
    a = &b;

    while (*a < 9)
    {
        write(1,(*a)++,1);
    }
}