#include "pushswap.h"

void showlist(t_list *a)
{
	t_list	*aux;

	if (a == a->down)
	{
		write(1, a->content, ft_strlen(a->content));
		return ;
	}
	aux = a;
	while (aux->down != a)
	{
		write(1, aux->content, ft_strlen(aux->content));
		write(1, "\n", 1);
		aux = aux->down;
	}
	write(1, aux->content, ft_strlen(aux->content));
	write(1, "\n", 1);
	return ;
}