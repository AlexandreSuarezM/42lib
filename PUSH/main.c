// we handle itns     vs    we map the char numbers to a table .
// lst adjusted for bidirectional loop


#include "libft.h"

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
		new = ft_lstnew((argv[i]));
		// add on the top of the stack 
		ft_lstadd_top(&alst, new);
	}

	// stack b gets initialized with a lstadd 
	// sorting 


	new = alst;
	while(new->down)
	{
		aux = new->down;
		while (aux)
		{
			if (aux->value == new->value || isnum(new->value))
				return (1);
			if (ft_strcmp(aux->value,new->value))
				new->rel_pos++;
			aux = aux->down;
		}
		new = new->down;
	}
	if (isnum(aux->value))
		return (1);

	ft_lstclear(&alst);
	return (0);
}