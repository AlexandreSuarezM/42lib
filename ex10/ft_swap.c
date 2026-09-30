#include <stdio.h>
#include <stdlib.h>

ft_swap(int *a, int *b)
{
    int c;
    c = *a;
    *a = *b;
    *b = c;
}