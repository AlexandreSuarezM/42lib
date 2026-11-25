#include "pushswap.h"

// just to check niely could call disorder
void showlist(t_list *a)
{
	t_list	*aux;

	if (a == a->down)
	{
		ft_printf("%d\n",a->content);
		return ;
	}

	while ((a->content) > (a->down->content))
	{
		ft_printf("%d\n",a->content);
		aux = aux->down;
	}
	return ;
}