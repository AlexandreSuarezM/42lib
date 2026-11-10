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

	if(argc < 2)
		return (0);
	i = 2;
	while (i < argc)
	{ 
		new = ft_lstnew((argv[i]));
		ft_lstadd_top(&alst, new);
		i++;
	}
	new = alst;
	while(new->down)
	{
		aux = new->down;
		while (aux)
		{
			if (aux->value == new->value)
				break;
			if (compare(aux->value,new->value) < 0)
				new->rel_pos++;
			aux = aux->down;
		}
		new = new->down;
	}
	if (argv[1] == "simple")
		selectionsort(&a, &b);
	if (argv[1] == "medium")
	//Chunk-based sorting — O(n√n).
	if (argv[1] == "complex")
		RadixSort(&alst,&blst, argc - 2);
	if (argv[1] == "adaptive")
	// adaptive
	else
		return (0);
	
	ft_lstclear(&alst);
	return (0);
}





