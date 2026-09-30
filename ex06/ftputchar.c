#include <stdio.h>
#include <stdlib.h>


void ft_print_alphabet(void)
{
    char * a;
    char b = 'a';
    a = &b;

    /* remembe '' characters vs strings special importance for memori allocations  */
    /*memori asignation on variable and after it are NOT the same */

    write(1, a ,1);
    while (*a < 'z')
    {
        write(1,(*a)++,1);
    }
    /*memori alocation */
    /*prioriti on the operator + over * */
}