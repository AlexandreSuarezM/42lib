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

#include "pushswap.h"

int	main(int argc, char **argv)
{
	int	i;

	t_list	*new;
	t_list	*alst;
	t_list	*aux;
	t_list	*blst;

	i = 1;
	if(argc < 1)
		return (0);

	while (i < argv)
	{
		// create with the value 
		new = ft_lstnew(ft_atoi(argv[i]));
		// add on the top of the stack 
		ft_lstadd_top(&alst, new);
	}

	// stack b gets initialized with a lstadd 
	// sorting 


	new = alst;
	while(new)
	{
		aux = new->down;
		while (aux)
		{
			if (aux->value == new->value)
				return (1);
			if (aux->value < new->value)
				new->rel_pos++;
			aux = aux->down;
		}
		new = new->down;
	}

	ft_lstclear(&alst);
	return (0);
}