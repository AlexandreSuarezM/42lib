// we handle itns     vs    we map the char numbers to a table .
// lst adjusted for bidirectional loop


#include "libft.h"
/*
typedef struct s_list
{
	int				value;
	struct s_list	*up;
	struct s_list	*down;
}	t_list;
*/

// i = 0 nombre
// atoi modificado para devolver NULL si no num o overfloat
// la deteccion de numeros mas grandes esta en memoria
// puedo usar atoi o puedo usar una transformacion de los chars a valores
// ai ago esto necesito gaurdar el char .

int	main(int argc, char **argv)
{
	int	i;

	t_list	*new;
	t_list	*lst;
	t_list	*aux;

	i = 1;
	if(argc < 1)
		return (0);

	while (i < argv)
	{
		// create with the value 
		new = ft_lstnew(ft_atoi(argv[i]));
		// add on the top of the stack 
		ft_lstadd_top(&lst, new);
	}

	// initialize the b stack
	// sorting


	new = lst;
	while(new)
	{
		aux = new->down;
		while (aux)
		{
			if (aux->value == new->value)
				return (1);
			aux = aux->down;
		}
		new = new->down;
	}
	




	ft_lstclear(&lst);
	return (0);
}